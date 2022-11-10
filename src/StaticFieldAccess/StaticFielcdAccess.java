package StaticFieldAccess;

public class StaticFielcdAccess {

    private static int si;

    private native void accessField();

    public static void main(String[] args) {
        StaticFielcdAccess c = new StaticFielcdAccess();
        StaticFielcdAccess.si = 100;
        c.accessField();
        System.out.println("In Java:");
        System.out.println(" StaticFielcdAccess.si = " + si);
    }

    static {
        System.loadLibrary("StaticFielcdAccess");
    }
}
