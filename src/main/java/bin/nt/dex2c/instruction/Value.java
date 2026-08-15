package bin.nt.dex2c.instruction;

import java.util.ArrayList;
import java.util.Collections;
import java.util.IdentityHashMap;
import java.util.List;
import java.util.Objects;
import java.util.Set;

/**
 * Base class of every SSA value.
 *
 * <p>Carries the value's type, its defining instruction, its use sites and
 * the constant flag. Types start unresolved ({@code null}) and are refined
 * during the inference pass; once sealed they cannot change.</p>
 */
public class Value {

    private String type;
    private boolean sealed;
    private Instruction definition;
    private final Set<Use> uses = Collections.newSetFromMap(new IdentityHashMap<>());
    private boolean constant;

    /** The resolved type, or {@code null} while unknown. */
    public String getType() {
        return type;
    }

    /**
     * Seals the type of the value, if it was never sealed before.
     *
     * @param t the type
     * @return {@code true} if the type was applied
     */
    public boolean setType(String t) {
        if (t == null || sealed) {
            return false;
        }
        sealed = true;
        if (Objects.equals(type, t)) {
            return false;
        }
        type = t;
        return true;
    }

    /**
     * Refines the type, merging with the current one where possible.
     *
     * @param t the type to merge in
     * @return {@code true} if the type changed
     */
    public boolean refineType(String t) {
        if (t == null || sealed || Objects.equals(type, t)) {
            return false;
        }
        if (type == null) {
            type = t;
            return true;
        }
        if (constant && TypeUtil.isInt(type) && TypeUtil.isRef(t)) {
            type = t;
            return true;
        }
        if (constant && TypeUtil.isInt(type) && TypeUtil.isFloat(t)) {
            type = t;
            return true;
        }
        String merged = TypeUtil.merge(type, t);
        if (merged == null) {
            throw new IllegalStateException("unable to refine type " + type + " with " + t);
        }
        if (!Objects.equals(type, merged)) {
            type = merged;
            return true;
        }
        return false;
    }

    /** Records the instruction that defines this value. */
    public void setDefinition(Instruction i) {
        definition = i;
    }

    /** The defining instruction, or {@code null} for parameters/constants. */
    public Instruction getDefinition() {
        return definition;
    }

    /** Whether this value is a compile-time constant. */
    public boolean isConstant() {
        return constant;
    }

    /** Marks the value as a constant (called by {@link Constant}). */
    protected void markConstant() {
        constant = true;
    }

    /** Immutable view of the use sites. */
    public Set<Use> getUses() {
        return Collections.unmodifiableSet(uses);
    }

    /** Every instruction using this value. */
    public List<Instruction> getUsers() {
        List<Instruction> r = new ArrayList<>();
        for (Use u : uses) {
            if (u.user() != null) {
                r.add(u.user());
            }
        }
        return r;
    }

    /** Records a use of this value by an instruction. */
    public void addUser(Instruction i) {
        if (i != null) {
            uses.add(new Use(this, i));
        }
    }

    /** Drops all uses recorded for an instruction. */
    public void removeUser(Instruction i) {
        uses.removeIf(u -> u.user() == i);
    }

    /** Redirects every use of this value to another value. */
    public void replaceAllUsesWith(Value n) {
        for (Use u : new ArrayList<>(uses)) {
            u.user().replaceUse(this, n);
        }
        uses.clear();
    }

    /** Whether the value has no users. */
    public boolean useEmpty() {
        return uses.isEmpty();
    }

    @Override
    public String toString() {
        return "value";
    }

    /** A single use of a value by an instruction. */
    public static final class Use {
        private final Value value;
        private final Instruction user;

        Use(Value v, Instruction u) {
            value = v;
            user = u;
        }

        /** The used value. */
        public Value value() {
            return value;
        }

        /** The using instruction. */
        public Instruction user() {
            return user;
        }
    }

    /** Type helpers shared by the SSA builder and the inference pass. */
    public static final class TypeUtil {
        private static final List<String> INTS = List.of("Z", "B", "S", "C", "I");

        private TypeUtil() {
        }

        /** Whether a type is a reference ({@code L...} or {@code [...]}). */
        public static boolean isRef(String t) {
            return t != null && (t.startsWith("L") || t.startsWith("["));
        }

        /** Whether a type is an integer family type. */
        public static boolean isInt(String t) {
            return INTS.contains(t);
        }

        /** Whether a type is a floating-point type. */
        public static boolean isFloat(String t) {
            return "F".equals(t) || "D".equals(t);
        }

        /** Whether a type occupies two registers. */
        public static boolean isWide(String t) {
            return "J".equals(t) || "D".equals(t);
        }

        /**
         * Merges two types, returning the common supertype or {@code null}
         * when no merge exists.
         */
        public static String merge(String a, String b) {
            if (a == null) {
                return b;
            }
            if (b == null) {
                return a;
            }
            if (a.equals(b)) {
                return a;
            }
            if (isInt(a) && isInt(b)) {
                return INTS.get(Math.max(INTS.indexOf(a), INTS.indexOf(b)));
            }
            if (isFloat(a) && isFloat(b)) {
                return "D".equals(a) || "D".equals(b) ? "D" : "F";
            }
            if (isRef(a) && isRef(b)) {
                return "Ljava/lang/Object;";
            }
            return null;
        }
    }
}
