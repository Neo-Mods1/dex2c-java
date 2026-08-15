package bin.nt.dex2c.instruction;
public final class Constant extends Value {
    private final Object value;
    public Constant(Object value,String type){this.value=value;markConstant();if(type!=null)refineType(type);}
    public Object getConstant(){return value;}
    @Override public String toString(){return String.valueOf(value);}
}
