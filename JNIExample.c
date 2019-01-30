#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <jni.h>
#include "JNIExample.h"

JNIEXPORT int JNICALL Java_JNIExample_randGenerator(JNIEnv *env, jobject object, jint cnt)
{
  printf("\nC Area ------------\n");
  printf("\nInt test ----------\n");
  int sum=0;
  srand(time(NULL));
  while (cnt > 0)
  {
    int n = rand()%100 + 1; // 1~100 random number
    printf("Generate new Random Number! ===> %d \n", n);
    sum += n;
    cnt--;
  }
  return sum;
}

JNIEXPORT jstring JNICALL Java_JNIExample_strTest(JNIEnv *env, jobject object, jstring evccMAC, jstring seccMAC)
{
  printf("\nC Area -------------------\n");
  printf("\nString test -------------\n");
  // Step 1: jstring 을 c string 으로 바꿔서 쓸 수 있게 함 
  const char *evccStr = (*env)->GetStringUTFChars(env, evccMAC, NULL);
  if (NULL == evccStr)
    return NULL;

  const char *seccStr = (*env)->GetStringUTFChars(env, seccMAC, NULL);
  if (NULL == seccStr)
    return NULL;

  // Step 2: 만든 C string 으로 할일 함. release 작업. 
  printf("\nSECC MAC : %s\n", evccStr);
  (*env)->ReleaseStringUTFChars(env, evccMAC, evccStr);
  printf("EVCC MAC : %s\n", seccStr);
  (*env)->ReleaseStringUTFChars(env, seccMAC, seccStr);

  // Step 3: Cstring 을 다시 Jstring 으로 보내야 java 에서 읽을 수 있음.
  char* result = "Received MAC Addresses";
  return (*env)->NewStringUTF(env, result);
}

JNIEXPORT jbyteArray JNICALL Java_JNIExample_byteArrTest(JNIEnv *env, jobject object, jstring evccMAC, jstring seccMAC)
{
  printf("\nC Area -------------------\n");
  printf("\nbyte array test ----------\n");
  const char *evccStr = (*env)->GetStringUTFChars(env, evccMAC, NULL);
  if (NULL == evccStr)
    return NULL;

  const char *seccStr = (*env)->GetStringUTFChars(env, seccMAC, NULL);
  if (NULL == seccStr)
    return NULL;

  printf("\nSECC MAC : %s\n", evccStr);
  (*env)->ReleaseStringUTFChars(env, evccMAC, evccStr);
  printf("EVCC MAC : %s\n", seccStr);
  (*env)->ReleaseStringUTFChars(env, seccMAC, seccStr);

  // arr 받아와서 하려면 이렇게 해야할듯
  /*
  you can get jbyte* by GetByteArrayElements:

  jbyte* bufferPtr = (*env)->GetByteArrayElements(env, array, NULL);
  And it is important to know the length of your array:

  jsize lengthOfArray = (*env)->GetArrayLength(env, array);
  Having jbyte* and length, you can do all the things in c-array. Finally, releasing it:

  (*env)->ReleaseByteArrayElements(env, array, bufferPtr, 0);
  */

  // byte array 생성 후 보냄 
  jbyte a[] = {1,2,3,4,5,6};
  jbyteArray ret = (*env)->NewByteArray(env, 6);
  (*env)->SetByteArrayRegion(env, ret, 0, 6, a);
  return ret;
}
