package bin.nt.dex2c.instruction;

import java.util.*;

/** SSA value, directly mirroring dex2c's Value/Use model. */
public class Value {
    private String type;
    private boolean sealed;
    private Instruction definition;
    private final Set<Use> uses = Collections.newSetFromMap(new IdentityHashMap<>());
    private boolean constant;

    public String getType(){ return type; }
    public boolean setType(String t){
        if(t==null || sealed) return false;
        sealed=true;
        if(Objects.equals(type,t)) return false;
        type=t; return true;
    }
    public boolean refineType(String t){
        if(t==null || sealed || Objects.equals(type,t)) return false;
        if(type==null){ type=t; return true; }
        if(constant && TypeUtil.isInt(type) && TypeUtil.isRef(t)){ type=t; return true; }
        if(constant && TypeUtil.isInt(type) && TypeUtil.isFloat(t)){ type=t; return true; }
        String merged=TypeUtil.merge(type,t);
        if(merged==null) throw new IllegalStateException("unable to refine type "+type+" with "+t);
        if(!Objects.equals(type,merged)){type=merged;return true;}
        return false;
    }
    public void setDefinition(Instruction i){definition=i;}
    public Instruction getDefinition(){return definition;}
    public boolean isConstant(){return constant;}
    protected void markConstant(){constant=true;}
    public Set<Use> getUses(){return Collections.unmodifiableSet(uses);}
    public List<Instruction> getUsers(){
        List<Instruction> r=new ArrayList<>(); for(Use u:uses) if(u.user()!=null) r.add(u.user()); return r;
    }
    public void addUser(Instruction i){ if(i!=null) uses.add(new Use(this,i)); }
    public void removeUser(Instruction i){ uses.removeIf(u->u.user()==i); }
    public void replaceAllUsesWith(Value n){
        for(Use u:new ArrayList<>(uses)) u.user().replaceUse(this,n);
        uses.clear();
    }
    public boolean useEmpty(){return uses.isEmpty();}
    @Override public String toString(){return "value";}

    public static final class Use { private final Value value; private final Instruction user; public Use(Value v,Instruction u){value=v;user=u;} public Value value(){return value;} public Instruction user(){return user;} }

    public static final class TypeUtil {
        private static final List<String> INTS=List.of("Z","B","S","C","I");
        public static boolean isRef(String t){return t!=null&&(t.startsWith("L")||t.startsWith("["));}
        public static boolean isInt(String t){return INTS.contains(t);}
        public static boolean isFloat(String t){return "F".equals(t)||"D".equals(t);}
        public static boolean isWide(String t){return "J".equals(t)||"D".equals(t);}
        public static String merge(String a,String b){
            if(a==null)return b;if(b==null)return a;if(a.equals(b))return a;
            if(isInt(a)&&isInt(b)) return INTS.get(Math.max(INTS.indexOf(a),INTS.indexOf(b)));
            if(isFloat(a)&&isFloat(b)) return "D".equals(a)||"D".equals(b)?"D":"F";
            if(isRef(a)&&isRef(b)) return "Ljava/lang/Object;";
            return null;
        }
    }
}
