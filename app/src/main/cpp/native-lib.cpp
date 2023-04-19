#include <jni.h>
#include <string>

extern "C" JNIEXPORT void JNICALL
Java_lu_uni_graux_bm18_MainActivity_fieldCopyUsingJNI(
        JNIEnv* env,
        jobject thisObj) {
    jclass cid = env->GetObjectClass(thisObj);
    jfieldID fidImei = env->GetFieldID(cid, "imei", "Ljava/lang/String;");
    jfieldID fidNotImei = env->GetFieldID(cid, "notImei", "Ljava/lang/String;");
    jfieldID fidNotImei2 = env->GetFieldID(cid, "notImei2", "Ljava/lang/String;");
    jstring imei_jstr = (jstring) env->GetObjectField(thisObj, fidImei);

    const jchar* original = env->GetStringChars(imei_jstr, NULL);
    jsize len = env->GetStringLength(imei_jstr);
    jchar* copy = (jchar*) malloc(sizeof(jchar)*len);
    env->GetStringRegion(imei_jstr, 0, len/2, copy);
    for(unsigned int i=len/2 ; i<len ; i++ ) {
        copy[i] = original[i];
    }
    env->ReleaseStringChars(imei_jstr, original);
    jstring copy_jstr = env->NewString(copy, len);
    env->SetObjectField(thisObj, fidNotImei, copy_jstr);

    const char* original_utf = env->GetStringUTFChars(imei_jstr, NULL);
    jsize len_utf = env->GetStringUTFLength(imei_jstr);
    char* copy_utf = (char*) malloc(sizeof(char)*(len+1));
    env->GetStringUTFRegion(imei_jstr, 0, len_utf/2, copy_utf);
    for(unsigned int i=len_utf/2 ; i<len_utf ; i++ ) {
        copy_utf[i] = original_utf[i];
    }
    copy_utf[len] = '\0';
    env->ReleaseStringUTFChars(imei_jstr, original_utf);
    jstring copy_utf_jstr = env->NewStringUTF(copy_utf);
    env->SetObjectField(thisObj, fidNotImei2, copy_utf_jstr);
}