#include "DataFlow_dataflow.h"

JNIEXPORT void JNICALL Java_DataFlow_dataflow_nativeMethod
  (JNIEnv *env, jobject obj)
{
    jfieldID fid;
    jstring jstr;

    // getTaintedData(src)

    // Get a reference to obj's class
    jclass cls = (*env)->GetObjectClass(env, obj);

    // Look for the instance field src in cls
    fid = (*env)->GetFieldID(env, cls, "src", "Ljava/lang/String;");
//    if (fid == NULL){
//        return; /* failed to find the field */
//    }
    /* Read the instance field s */
    jstr = (*env)->GetObjectField(env, obj, fid);

    // Look for the instance method src in cls
    jmethodID mid = (*env)->GetMethodID(env, cls, "getTaintedData", "(Ljava/lang/String;)V");
//    if (mid == NULL){
//        return;
//    }
    (*env)->CallVoidMethod(env, obj, mid, jstr);
}