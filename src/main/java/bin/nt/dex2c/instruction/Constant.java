package bin.nt.dex2c.instruction;

/**
 * A compile-time constant value.
 *
 * <p>Constants are marked as such at construction time, which lets the type
 * inference pass widen them from integer to reference/float types.</p>
 */
public final class Constant extends Value {

    private final Object value;

    /**
     * @param value the constant payload
     * @param type  an optional initial type
     */
    public Constant(Object value, String type) {
        this.value = value;
        markConstant();
        if (type != null) {
            refineType(type);
        }
    }

    /** The constant payload. */
    public Object getConstant() {
        return value;
    }

    @Override
    public String toString() {
        return String.valueOf(value);
    }
}
