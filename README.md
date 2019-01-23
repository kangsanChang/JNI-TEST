# JNI-TEST

## JNI?

- Java Native Interface
- JVM 위의 java code 가 Native application(HW, OS dependent) 및 C, C++, ASM 과 같이 다른 언어들로 작성된 라이브러리를 호출하거나 반대로 호출되도록 하는 Programming Framework
- JAVA 에서 C, CPP 코드 사용하고 싶을 때!

## 시작하기 전
- 당연히 java, gcc compiler 필요
- $JAVA_HOME 환경변수 설정 되어 있어야 함
```
# java 1.8 버전의 경우
export JAVA_HOME="$(/usr/libexec/java_home -v 1.8)"
```
- Window, Max, Linux 에 필요한 파일이 각각 다르다.
  - 파일 이름이 HelloWorld 일 때,
  - Window: HelloWorld.dll
  - Mac: libHelloWorld.jnilib
  - Linux: libHelloWorld.so

## 실행방법
### 1. JNIExample.java 컴파일
```
javac JNIExample.java
```
- JNIExample.class 파일 생성 됨 

### 2. header 파일 생성
```
javah -jni JNIExample
```
- JNIExample.h 파일 생성 됨

### 3. JNIExample.c 컴파일
```
gcc -I"$JAVA_HOME/include" -I"$JAVA_HOME/include/darwin/" -o libjniexample.jnilib -shared JNIExample.c
```

### 4. 실행
`java.library.path` 를 현재 디렉토리(.)로 설정하고 실행해야 함
```
java -Djava.library.path=. JNIExample
```
## 실행화면

![screen shot 2019-01-23 at 22 40 41](https://user-images.githubusercontent.com/15089420/51612811-909ee080-1f65-11e9-9aa7-553aff02a4ec.png)

## 참고

[JNI Example (Mac OS)](https://gist.github.com/DmitrySoshnikov/8b1599a5197b5469c8cc07025f600fdb)

[java에서 JNI 를 이용하여 c 라이브러리(.so,.dll) 사용하기](https://shuming.tistory.com/entry/java%EC%97%90%EC%84%9C-JNI-%EB%A5%BC-%EC%9D%B4%EC%9A%A9%ED%95%98%EC%97%AC-c-%EB%9D%BC%EC%9D%B4%EB%B8%8C%EB%9F%AC%EB%A6%ACsodll-%EC%82%AC%EC%9A%A9%ED%95%98%EA%B8%B0)

[jni로 HelloWorld출력](http://blog.devez.net/166)

[Why am I getting this UnsatisfiedLinkError with native code?](https://stackoverflow.com/questions/761639/why-am-i-getting-this-unsatisfiedlinkerror-with-native-code)

