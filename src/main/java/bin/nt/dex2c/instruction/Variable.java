package bin.nt.dex2c.instruction;
public class Variable extends Value {
    private final int register, version;
    public Variable(int register,int version){this.register=register;this.version=version;}
    public int getRegister(){return register;} public int getVersion(){return version;}
    @Override public String toString(){return "v"+(register<0?"Result":register)+"_"+version;}
}
