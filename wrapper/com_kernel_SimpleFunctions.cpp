#include "com_kernel_SimpleFunctions.h"
#include <windows.h>
#include <string>

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetLastError(JNIEnv *, jclass)
{
    return (jlong)(INT32)GetLastError();
}

JNIEXPORT void JNICALL Java_com_kernel_SimpleFunctions_SetLastError(JNIEnv *, jclass, jlong error_no)
{
    SetLastError((DWORD)error_no);
}

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetProcessVersion(JNIEnv *env, jclass clazz, jlong processId)
{
    return (jlong)GetProcessVersion((DWORD)processId);
}

JNIEXPORT void JNICALL Java_com_kernel_SimpleFunctions_ExitProcess(JNIEnv *, jclass, jint uExitCode)
{
    ExitProcess((UINT)uExitCode);
}

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetCurrentProcessId(JNIEnv *, jclass)
{
    return (jlong)(INT32)GetCurrentProcessId();
}

char *jstring_to_cstr(JNIEnv *env, jstring str)
{
    int length = env->GetStringLength(str);
    char *cstr = new char[length + 1];
    const jchar *charArray = env->GetStringChars(str, nullptr);

    for (int i = 0; i < length; i++)
    {
        cstr[i] = (char)charArray[i];
    }

    cstr[length] = '\0';

    return cstr;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CopyFile(JNIEnv *env, jclass, jstring lpExistingFileName, jstring lpNewFileName, jboolean bFailIfExists)
{
    char *newFileName = jstring_to_cstr(env, lpNewFileName);
    char *existingFileName = jstring_to_cstr(env, lpExistingFileName);
    int success = CopyFileA(existingFileName, newFileName, (bFailIfExists == JNI_TRUE));

    if (success == TRUE)
    {
        return JNI_TRUE;
    }
    else
    {
        return JNI_FALSE;
    }
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateDirectory
(JNIEnv * env, jclass, jstring lpPathName, jobject attr)
{
    
}
