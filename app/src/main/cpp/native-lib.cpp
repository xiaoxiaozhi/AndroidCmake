#include <jni.h>
#include <string>
#include "test.h"
#include "test1.h"

extern "C" JNIEXPORT jstring JNICALL
Java_com_example_myapplication_MainActivity_stringFromJNI(
        JNIEnv *env,
        jobject /* this */) {
    std::string hello =
            "Hello from C++ " + std::to_string(minus(4, 5)) + " " + std::to_string(add(4, 5));
    return env->NewStringUTF(hello.c_str());
}

int main() {
    printf("add = %d minus= %d ", add(4, 5), minus(5, 4));
    return 0;
}