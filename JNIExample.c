#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <jni.h>
#include <string.h>
#include "JNIExample.h"

JNIEXPORT jstring JNICALL Java_JNIExample_setSniffer(JNIEnv *env, jobject object, jstring evccMAC, jstring seccMAC)
{
  printf("---------- Native Area ----------\n");
  printf("\nSet Sniffer...\n");
  // Step 1: jstring 을 c string 으로 바꿔서 쓸 수 있게 함 
  const char *evccStr = (*env)->GetStringUTFChars(env, evccMAC, NULL);
  if (NULL == evccStr)
    return NULL;

  const char *seccStr = (*env)->GetStringUTFChars(env, seccMAC, NULL);
  if (NULL == seccStr)
    return NULL;

  // Step 2: 만든 C string 으로 할일 함. release 작업. 
  printf("\nSet SECC MAC : %s\n", evccStr);
  (*env)->ReleaseStringUTFChars(env, evccMAC, evccStr); // 더이상 사용하지 않으므로 release
  printf("Set EVCC MAC : %s\n", seccStr);
  (*env)->ReleaseStringUTFChars(env, seccMAC, seccStr);

  // Step 3: Cstring 을 다시 Jstring 으로 보내야 java 에서 읽을 수 있음.
  char* result = "sniffer start!";
  printf("---------------------------------\n");
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jbyteArray JNICALL Java_JNIExample_byteArrTest(JNIEnv *env, jobject object){
  printf("---------- Native Area ----------\n");
  char testpkt[] = "48656c6c6f0d0a546869732069732054657374205061636b657421";
  jbyteArray retArr = (*env)->NewByteArray(env, sizeof(testpkt));
  (*env)->SetByteArrayRegion(env, retArr, 0, sizeof(testpkt), (jbyte *)testpkt);
  printf("---------------------------------\n");
  return retArr;
}

JNIEXPORT jstring JNICALL Java_JNIExample_hexStrTest(JNIEnv *env, jobject object)
{
  printf("---------- Native Area ----------\n");
  printf("\nbyte array test ----------\n");

  const char* testpkt ="48656c6c6f0d0a546869732069732054657374205061636b657421";

  // unsigned char byteTest[sizeof(testpkt)];
  // memset(byteTest, 0x00, sizeof(byteTest));

  // string 이 " " 기준으로 분리되어있을 때 사용.
  // unsigned char* st = (unsigned char*)strtok(testpkt," ");
  // int i=0;
  // while(st != NULL){
  //   printf("%s\n",st);
  //   byteTest[i] = *st;
  //   i++;
  // }
  // jbyteArray jba = (*env)->NewByteArray(env, sizeof(testpkt));
  // jsize lengthOfArray = (*env)->GetArrayLength(env, jba);
  // (*env)->SetByteArrayRegion(env, jba, 0, lengthOfArray, (jbyte *)byteTest);
  // printf("\n%s\n",(jbyte *)testpkt);
  // (*env)->SetByteArrayRegion(env, jba, 0, lengthOfArray, (jbyte *)testpkt);
      // byte array 생성 후 보냄
      // jbyte a[] = {1, 2, 3, 4, 5, 6};
      // jbyteArray ret = (*env)->NewByteArray(env, lengthOfArray);
      // (*env)->SetByteArrayRegion(ret, 0, 6, a);
      // env->SetByteArrayRegion(ret, 0, 28, (jbyte*)SendData.bytes)
      // return jba;
  printf("---------------------------------\n");
  return (*env)->NewStringUTF(env, testpkt);
}
