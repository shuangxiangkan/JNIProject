#include <stdio.h>
#include "Exceptions_CatchThrow.h"

JNIEXPORT void JNICALL Java_Exceptions_CatchThrow_doit
  (JNIEnv *env, jobject obj)
{
    jthrowable exc;
    jclass cls = (*env)->GetObjectClass(env, obj);
    jmethodID mid = (*env)->GetMethodID(env, cls, "callback", "()V");
    if(mid == NULL){
        return;
    }
    (*env)->CallVoidMethod(env, obj, mid);
    exc = (*env)->ExceptionOccurred(env);
    if(exc){
        jclass newExcCls;
        (*env)->ExceptionDescribe(env);
        (*env)->ExceptionClear(env);
        newExcCls = (*env)->FindClass(env, "java/lang/IllegalArgumentException");
        if (newExcCls == NULL)
            return;
        (*env)->ThrowNew(env, newExcCls, "throw from C code");
    }
}