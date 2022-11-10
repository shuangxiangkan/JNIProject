#include <jni.h>
#include <stdio.h>
#include "InstanceMethodAccess_InstanceMethodCall.h"

JNIEXPORT void JNICALL Java_InstanceMethodAccess_InstanceMethodCall_nativeMethod
  (JNIEnv *env, jobject obj)
{
    jclass cls = (*env)->GetObjectClass(env, obj);
    jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
    if (mid == NULL){
        return;
    }
    printf("In C\n");
    (*env)->CallVoidMethod(env, obj, mid);
}