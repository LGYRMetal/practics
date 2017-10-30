#include <stdio.h>
#include <jni.h>
#include "HelloWorld.h"

JNIEXPORT void JNICALL Java_HelloWorld_hello(JNIEnv *env, jobject obj, jstring name)
{
    printf("Hello %s!\n", (*env)->GetStringUTFChars(env, name, 0));
    return;
}
