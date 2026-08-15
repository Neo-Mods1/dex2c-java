package bin.nt.dex2c.compiler;

import java.util.Collection;
import java.util.IdentityHashMap;
import java.util.Map;

import bin.nt.dex2c.instruction.Value;
import bin.nt.dex2c.instruction.Variable;

/**
 * Assigns a stable native slot to every SSA variable of a method.
 *
 * <p>Slots are allocated in visit order and never reused within a method;
 * the writer addresses them as {@code v<slot>}.</p>
 */
public final class RegisterAllocator {

    private final Map<Variable, Integer> slots = new IdentityHashMap<>();
    private int next;

    /**
     * Allocates slots for all variables of a value collection.
     *
     * @param values the method's SSA values
     */
    public RegisterAllocator(Collection<Value> values) {
        for (Value v : values) {
            if (v instanceof Variable) {
                allocate((Variable) v);
            }
        }
    }

    /**
     * Allocates (or reuses) the slot of a variable.
     *
     * @param v the variable
     * @return its slot
     */
    public int allocate(Variable v) {
        return slots.computeIfAbsent(v, k -> next++);
    }

    /**
     * The slot of a variable, or {@code -1} when not allocated.
     *
     * @param v the variable
     * @return its slot
     */
    public int get(Variable v) {
        return slots.getOrDefault(v, -1);
    }

    /** Number of slots allocated so far. */
    public int size() {
        return next;
    }
}
