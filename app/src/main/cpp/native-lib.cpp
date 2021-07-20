#include <jni.h>
#include <string>
#include <stdio.h>
#include "test.h"


extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello = "Hello from C++ " + std::to_string(minus(4, 5));
    return env->NewStringUTF(hello.c_str());
}

//int main() {
//    printf("add = %d", add(4, 5));
//    return 0;
//}