import java.util.Scanner;

class JNIExample {

  // Native method, no body.
  public native void sayHello(int length);

  public static void main (String args[]) {
    Scanner sc = new Scanner(System.in);
    System.out.println("Java Area ----------");
    System.out.println("Enter the number to Generate : ");
    (new JNIExample()).sayHello(sc.nextInt());
  }

  // This loads the library at runtime. NOTICE: on *nix/Mac the extension of the
  // lib should exactly be `.jnilib`, not `.so`, and have `lib` prefix, i.e.
  // the library file should be `libjniexample.jnilib`.
  static {
    System.loadLibrary("jniexample");
  }
}