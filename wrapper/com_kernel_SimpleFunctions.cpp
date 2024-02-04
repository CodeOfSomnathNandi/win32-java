#include "com_kernel_SimpleFunctions.h"
#include <windows.h>
#include <winerror.h>
#include <string>
#include "utility.h"
#include <winnt.h>

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

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateDirectory(JNIEnv *env, jclass, jstring lpPathName)
{
    char *pathName = jstring_to_cstr(env, lpPathName);

    int isSuccess = CreateDirectoryA(pathName, NULL);

    if (isSuccess == TRUE)
    {
        return JNI_TRUE;
    }
    else
    {
        return JNI_FALSE;
    }
}
