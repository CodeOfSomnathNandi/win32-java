/* DO NOT EDIT THIS FILE - it is machine generated */
#include <jni.h>
/* Header for class com_kernel_SimpleFunctions */

#ifndef _Included_com_kernel_SimpleFunctions
#define _Included_com_kernel_SimpleFunctions
#ifdef __cplusplus
extern "C" {
#endif
/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    GetLastError
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetLastError
  (JNIEnv *, jclass);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    SetLastError
 * Signature: (J)V
 */
JNIEXPORT void JNICALL Java_com_kernel_SimpleFunctions_SetLastError
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    GetProcessVersion
 * Signature: (J)J
 */
JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetProcessVersion
  (JNIEnv *, jclass, jlong);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    ExitProcess
 * Signature: (I)V
 */
JNIEXPORT void JNICALL Java_com_kernel_SimpleFunctions_ExitProcess
  (JNIEnv *, jclass, jint);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    GetCurrentProcessId
 * Signature: ()J
 */
JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetCurrentProcessId
  (JNIEnv *, jclass);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    CopyFileA
 * Signature: (Ljava/lang/String;Ljava/lang/String;Z)V
 */
JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CopyFile
  (JNIEnv *, jclass, jstring, jstring, jboolean);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    CreateDirectory
 * Signature: (Ljava/lang/String;Lcom/kernel/SecurityAttributes;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateDirectory
  (JNIEnv *, jclass, jstring, jobject);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    DeleteFile
 * Signature: (Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_DeleteFile
  (JNIEnv *, jclass, jstring);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    MoveFile
 * Signature: (Ljava/lang/String;Ljava/lang/String;)Z
 */
JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_MoveFile
  (JNIEnv *, jclass, jstring, jstring);

/*
 * Class:     com_kernel_SimpleFunctions
 * Method:    GetCurrentDirectory
 * Signature: ()Ljava/lang/String;
 */
JNIEXPORT jstring JNICALL Java_com_kernel_SimpleFunctions_GetCurrentDirectory
  (JNIEnv *, jclass);

#ifdef __cplusplus
}
#endif
#endif
