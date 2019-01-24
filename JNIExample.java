import java.util.Scanner;

class JNIExample {

  // Native method, no body.
  public native int randGenerator(int count);

  public static void main (String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Java Area ----------");
    System.out.println("Enter the number to Generate : ");
    int result = (new JNIExample()).randGenerator(sc.nextInt());
    System.out.println("\nJava Area ----------");
    System.out.println("The returned sum value from C function is "+result);
  }

  // This loads the library at runtime. NOTICE: on *nix/Mac the extension of the
  // lib should exactly be `.jnilib`, not `.so`, and have `lib` prefix, i.e.
  // the library file should be `libjniexample.jnilib`.
  static {
    System.loadLibrary("jniexample");
  }
}