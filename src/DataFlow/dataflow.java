package DataFlow;

public class dataflow {
    static {
        System.loadLibrary("DataFlow");
    }
    String src = "Tainted";
    String dst;
    public native void nativeMethod();
    public void getTaintedData(String data) {
        dst = data;
    }
    public static void main(String[] args) {
        dataflow d = new dataflow();
        System.out.print("In java, dst is ");
        d.nativeMethod(); // getTaintedData(src)
        System.out.println(d.dst);
    }
}
