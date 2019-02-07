import java.util.Scanner;
import java.util.Arrays;

class JNIExample {

  // Native method, no body.
  public native String setSniffer(String evcc, String secc);
  public native String hexStrTest();
  public native byte[] byteArrTest();

  public static byte[] hexStringToByteArray(String s) {
	    int len = s.length();
	    byte[] data = new byte[len / 2];
	    for (int i = 0; i < len; i += 2) {
	        data[i / 2] = (byte) ((Character.digit(s.charAt(i), 16) << 4)
	                             + Character.digit(s.charAt(i+1), 16));
	    }
	    return data;
	}

  public static void main (String args[]) {
    JNIExample jniex = new JNIExample();
    Scanner sc = new Scanner(System.in);
    System.out.println("\nJava Area ----------");
    System.out.println("Input EVCC MAC Address");
    String evcc = sc.next();
    System.out.println("Input SECC MAC Address");
    String secc = sc.next();
    String receivedmsg = jniex.setSniffer(evcc, secc);
    System.out.println("The returned message from Native Function \n : "+receivedmsg);
    System.out.println("HEX String 을 받아서 java 에서 byte arr 로 변환한 후 출력하는 예제 ");
    String hexstr = jniex.hexStrTest();
    System.out.println("The returned hexstr from Native Function \n : "+hexstr);
    System.out.println("hexstr -> bytearr \n : "+Arrays.toString(hexStringToByteArray(hexstr)));
    // 아래 방법으로도 변환 가능함 단, 앞이 00 일때 못씀
    // System.out.println("hexstr -> bytearr \n : "+Arrays.toString(new java.math.BigInteger(hexstr, 16).toByteArray()));
    System.out.println("hexstr -> bytearr \n : "+(new String(hexStringToByteArray(hexstr))));

    System.out.println("byte arr 를 받아서 출력하는 예제 ");
    byte[] resultArr = jniex.byteArrTest();
    System.out.println(Arrays.toString(resultArr));
    System.out.println(new String(resultArr));
  }

  // This loads the library at runtime. NOTICE: on *nix/Mac the extension of the
  // lib should exactly be `.jnilib`, not `.so`, and have `lib` prefix, i.e.
  // the library file should be `libjniexample.jnilib`.
  static {
    System.loadLibrary("jniexample");
  }
}