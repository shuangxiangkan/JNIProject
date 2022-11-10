#include<jni.h>

JNIEXPORT void JNICALL Java_DataFlow_dataflow_nativeMethod
  (JNIEnv *env, jobject obj)
{
    jclass cls = (*env)->GetObjectClass(env, obj);
}