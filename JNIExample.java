import java.util.Scanner;

class JNIExample {

  // Native method, no body.
  public native int randGenerator(int count);
  public native String strTest(String evcc, String secc);

  public static void main (String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Java Area ----------");
    System.out.println("Enter the number to Generate : ");
    JNIExample jniex = new JNIExample();
    int result = jniex.randGenerator(sc.nextInt());
    System.out.println("\nJava Area ----------");
    System.out.println("The returned sum value from C function is "+result);
    System.out.println("TEST2************************");
    System.out.println("Input EVCC MAC Address");
    String evcc = sc.next();
    System.out.println("Input SECC MAC Address");
    String secc = sc.next();
    String receivedmsg = jniex.strTest(evcc, secc);
    System.out.println("The returned message from C function is "+receivedmsg);
  }

  // This loads the library at runtime. NOTICE: on *nix/Mac the extension of the
  // lib should exactly be `.jnilib`, not `.so`, and have `lib` prefix, i.e.
  // the library file should be `libjniexample.jnilib`.
  static {
    System.loadLibrary("jniexample");
  }
}