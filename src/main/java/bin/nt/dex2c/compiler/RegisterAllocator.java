package bin.nt.dex2c.compiler;
import java.util.*;import bin.nt.dex2c.instruction.*;
public final class RegisterAllocator{
 private final Map<Variable,Integer> slots=new IdentityHashMap<>();private int next;
 public RegisterAllocator(Collection<Value> values){for(Value v:values)if(v instanceof Variable)allocate((Variable)v);}
 public int allocate(Variable v){return slots.computeIfAbsent(v,k->next++);} public int get(Variable v){return slots.getOrDefault(v,-1);}public int size(){return next;}
}
