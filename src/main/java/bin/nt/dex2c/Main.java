package bin.nt.dex2c;

import java.io.*;
import java.nio.file.*;
import java.util.*;
import java.util.zip.*;
import com.android.tools.smali.dexlib2.DexFileFactory;
import com.android.tools.smali.dexlib2.iface.*;
import com.android.tools.smali.dexlib2.iface.instruction.*;
import com.android.tools.smali.dexlib2.iface.reference.*;
import com.android.tools.smali.dexlib2.dexbacked.DexBackedDexFile;

public final class Main {
  public static void main(String[] args) throws Exception {
    Cli cli = Cli.parse(args);
    if (cli.help) { Cli.usage(); return; }
    if (cli.version) { System.out.println("dex2c-cli 1.0.0"); return; }
    if (cli.input == null) throw new IllegalArgumentException("Missing --input");
    Path input = Paths.get(cli.input);
    if (!Files.isRegularFile(input)) throw new FileNotFoundException(input.toString());
    if ("inspect".equals(cli.command)) {
      new Inspector().run(input);
      return;
    }
    Path out = cli.output == null ? Paths.get("dex2c-out") : Paths.get(cli.output);
    Files.createDirectories(out);
    List<Path> dexes = InputDexes.extract(input, out.resolve(".input"));
    Compiler compiler = new Compiler(cli);
    int methods = 0, compiled = 0;
    for (Path dex : dexes) {
      DexBackedDexFile df = DexFileFactory.loadDexFile(dex.toFile(), null);
      Result r = compiler.compile(df, out);
      methods += r.methods; compiled += r.compiled;
    }
    System.out.printf("dex2c: scanned %d methods, emitted %d -> %s%n", methods, compiled, out.toAbsolutePath());
  }

  static final class Cli {
    String command="compile", input, output, filter, classFilter, methodFilter;
    boolean help, version, dynamicRegister=false, keepSynthetic=false, comments=true;
    static Cli parse(String[] a) {
      Cli c=new Cli();
      for(int i=0;i<a.length;i++) {
        String x=a[i];
        switch(x) {
          case "-h": case "--help": c.help=true; break;
          case "-v": case "--version": c.version=true; break;
          case "--command": c.command=a[++i]; break;
          case "-i": case "--input": c.input=a[++i]; break;
          case "-o": case "--output": c.output=a[++i]; break;
          case "--filter": c.filter=a[++i]; break;
          case "--class": c.classFilter=a[++i]; break;
          case "--method": c.methodFilter=a[++i]; break;
          case "--dynamic-register": c.dynamicRegister=true; break;
          case "--keep-synthetic": c.keepSynthetic=true; break;
          case "--no-comments": c.comments=false; break;
          default:
            if (!x.startsWith("-") && c.input==null) c.input=x;
            else throw new IllegalArgumentException("Unknown option: "+x);
        }
      }
      return c;
    }
    static void usage() {
      System.out.println("dex2c-cli - DEX/APK to JNI C++ source compiler\n" +
          "Usage: java -jar dex2c-cli-all.jar [options]\n" +
          "  -i, --input <apk|dex>       Input APK or DEX\n" +
          "  -o, --output <dir>          Output directory\n" +
          "  --filter <regex>            Method descriptor filter\n" +
          "  --class <regex>             Class descriptor filter\n" +
          "  --method <regex>            Method name filter\n" +
          "  --dynamic-register          Emit RegisterNatives metadata\n" +
          "  --command <compile|inspect>\n" +
          "  -h, --help                  Show help\n");
    }
  }

  static final class InputDexes {
    static List<Path> extract(Path in, Path dir) throws IOException {
      Files.createDirectories(dir);
      String n=in.getFileName().toString().toLowerCase(Locale.ROOT);
      if (n.endsWith(".dex")) return List.of(in);
      if (!n.endsWith(".apk") && !n.endsWith(".zip")) throw new IOException("Input must be .dex, .apk or .zip");
      List<Path> r=new ArrayList<>();
      try(ZipFile z=new ZipFile(in.toFile())) {
        Enumeration<? extends ZipEntry> e=z.entries();
        while(e.hasMoreElements()) {
          ZipEntry ze=e.nextElement();
          if (ze.isDirectory()) continue;
          String p=ze.getName();
          if (p.matches("classes(\\d*)\\.dex")) {
            Path d=dir.resolve(Paths.get(p).getFileName().toString());
            try(InputStream is=z.getInputStream(ze)){ Files.copy(is,d,StandardCopyOption.REPLACE_EXISTING); }
            r.add(d);
          }
        }
      }
      if(r.isEmpty()) throw new IOException("No classes*.dex found in "+in);
      r.sort(Comparator.comparingInt(Main::dexNumber));
      return r;
    }
  }

  static int dexNumber(Path p) { String n=p.getFileName().toString(); if ("classes.dex".equals(n)) return 1; if(n.startsWith("classes") && n.endsWith(".dex")){ try{return Integer.parseInt(n.substring(7,n.length()-4));}catch(Exception ignored){} } return Integer.MAX_VALUE; }

  static final class Inspector {
    void run(Path input) throws Exception {
      Path temp=Files.createTempDirectory("dex2c-inspect-");
      for(Path dex:InputDexes.extract(input,temp)) {
        DexBackedDexFile df=DexFileFactory.loadDexFile(dex.toFile(),null);
        int cls=0,m=0;
        for(ClassDef c:df.getClasses()) {
          cls++;
          System.out.println(c.getType()+"  super="+c.getSuperclass()+"  flags=0x"+Integer.toHexString(c.getAccessFlags()));
          for(Method x:c.getMethods()) {
            m++;
            System.out.printf("  %s%s  flags=0x%x%n",x.getName(),x.getDescriptor(),x.getAccessFlags());
          }
        }
        System.out.printf("-- %s: %d classes, %d methods --%n",dex.getFileName(),cls,m);
      }
    }
  }

  static final class Result { int methods, compiled, unsupported; }
}
