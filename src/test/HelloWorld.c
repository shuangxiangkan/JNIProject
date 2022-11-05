#include <jni.h>
#include <stdio.h>
#include "test_HelloWorld.h"

JNIEXPORT void JNICALL Java_test_HelloWorld_print
  (JNIEnv *env, jobject obj)
{
    printf("Hello JNI World!!!!");
    return;
}