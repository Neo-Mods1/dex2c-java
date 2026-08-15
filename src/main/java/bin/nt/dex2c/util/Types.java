package bin.nt.dex2c.util;
import java.util.*;
public final class Types{
 private Types(){}
 public static boolean ref(String t){return t!=null&&(t.startsWith("L")||t.startsWith("["));}
 public static boolean wide(String t){return "J".equals(t)||"D".equals(t);}
 public static String c(String t){if(t==null)return "jlong";if("V".equals(t))return "void";if("Z".equals(t))return "jboolean";if("B".equals(t))return "jbyte";if("S".equals(t))return "jshort";if("C".equals(t))return "jchar";if("I".equals(t))return "jint";if("J".equals(t))return "jlong";if("F".equals(t))return "jfloat";if("D".equals(t))return "jdouble";return t.startsWith("[")?"jarray":"jobject";}
 public static String jniSuffix(String t){if(t==null)return "Object";if("V".equals(t))return "Void";if("Z".equals(t))return "Boolean";if("B".equals(t))return "Byte";if("C".equals(t))return "Char";if("S".equals(t))return "Short";if("I".equals(t))return "Int";if("J".equals(t))return "Long";if("F".equals(t))return "Float";if("D".equals(t))return "Double";return "Object";}
 public static String descToClass(String d){if(d==null)return "java/lang/Object";if(d.startsWith("L")&&d.endsWith(";"))return d.substring(1,d.length()-1);return d;}
 public static String escape(String s){return s.replace("\\","\\\\").replace("\"","\\\"").replace("\n","\\n").replace("\r","\\r").replace("\t","\\t");}
 public static List<String> params(String desc){List<String> r=new ArrayList<>();int i=1;while(i<desc.length()&&desc.charAt(i)!=')'){int s=i;if(desc.charAt(i)=='['){while(desc.charAt(i)=='[')i++;if(desc.charAt(i)=='L')while(desc.charAt(i++)!=';');else i++;}else if(desc.charAt(i)=='L'){while(desc.charAt(i++)!=';');}else i++;r.add(desc.substring(s,i));}return r;}
 public static String ret(String desc){return desc.substring(desc.indexOf(')')+1);}
}
