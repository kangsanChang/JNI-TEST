#include <stdio.h>
#include <stdlib.h>
#include <jni.h>
#include "JNIExample.h"

JNIEXPORT int JNICALL Java_JNIExample_randGenerator(JNIEnv *env, jobject object, jint cnt)
{
  printf("\nC Area ----------\n");
  int sum=0;
  while (cnt > 0)
  {
    int n = rand() % 100 + 1; // 1~100 random number
    printf("Generate new Random Number! ===> %d \n", n);
    sum += n;
    cnt--;
  }
  return sum;
}
