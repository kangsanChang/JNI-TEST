#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "JNIExample.h"

JNIEXPORT void JNICALL Java_JNIExample_sayHello(JNIEnv *env, jobject object, jint len)
{
  printf("\nC Area ----------\n");
  while (len > 0)
  {
    int n = rand() % 100 + 1; // 1~100 random number
    printf("Generate new Random Number! ===> %d \n", n);
    len--;
  }
}
