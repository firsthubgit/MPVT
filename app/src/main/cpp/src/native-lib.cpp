#include <jni.h>
#include <string>
#include <stdio.h>


extern "C" JNIEXPORT jstring JNICALL
Java_is_xyz_mpv_MainActivity_stringFromJNI(
        JNIEnv* env,
        jobject /* this */) {
    std::string hello = "Hello from C++";
    const char * he = "TTT";
    printf("%s", he);
    return env->NewStringUTF(hello.c_str());
}