#include <jni.h>
#include <stdio.h>
#include "StaticFieldAccess_StaticFielcdAccess.h"

JNIEXPORT void JNICALL Java_StaticFieldAccess_StaticFielcdAccess_accessField
  (JNIEnv *env, jobject obj)
{
    jfieldID fid;
    jint si;

    // Get a reference to obj's class
    jclass cls = (*env)->GetObjectClass(env, obj);

    printf("In C:\n");

    // Look for the static field si in cls
    fid = (*env)->GetStaticFieldID(env, cls, "si", "I");
    if (fid == NULL){
        return;
    }

    // Access the static field si
    si = (*env)->GetStaticIntField(env, cls, fid);
    printf(" StaticFielcdAccess.si = %d\n", si);
    (*env)->SetStaticIntField(env, cls, fid, 200);
}