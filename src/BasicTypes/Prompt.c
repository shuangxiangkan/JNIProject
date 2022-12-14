#include <jni.h>
#include <stdio.h>
#include "BasicTypes_Prompt.h"

JNIEXPORT jstring JNICALL Java_BasicTypes_Prompt_getLine
  (JNIEnv *env, jobject obj, jstring prompt)
{
    char buf[128];
    const jbyte *str;
    str = (*env)->GetStringUTFChars(env, prompt, NULL);
    if (str == NULL){
        return NULL;// OutOfMemoryError already thrown
    }
    printf("%s", str);
    (*env)->ReleaseStringUTFChars(env, prompt, str);
    // We assume here that the user does not type more then 127 characters
    scanf("%s", buf);
    return (*env)->NewStringUTF(env, buf);
}