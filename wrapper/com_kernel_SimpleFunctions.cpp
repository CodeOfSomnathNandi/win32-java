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

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_DeleteFile(JNIEnv *env, jclass, jstring fileName)
{
    char *cfileName = jstring_to_cstr(env, fileName);
    int isSuccess = DeleteFileA(cfileName);
    if (isSuccess == TRUE)
    {
        return JNI_TRUE;
    }
    else
    {
        return JNI_FALSE;
    }
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_MoveFile(JNIEnv *env, jclass, jstring existingFileName, jstring newFileName)
{
    char *lpExistingFileName = jstring_to_cstr(env, existingFileName);
    char *lpNewFileName = jstring_to_cstr(env, newFileName);

    int isSuccess = MoveFileA(lpExistingFileName, lpNewFileName);

    if (isSuccess == TRUE)
    {
        return JNI_TRUE;
    }
    else
    {
        return JNI_FALSE;
    }
}

JNIEXPORT jstring JNICALL Java_com_kernel_SimpleFunctions_GetCurrentDirectory(JNIEnv * env, jclass)
{
    const int size = 2056;
    LPSTR buffer = new char[size];
    DWORD length = GetCurrentDirectoryA(size, buffer);
    LPSTR newBuff = new char[length];

    for (DWORD i = 0; i < length; i++)
    {
        newBuff[i] = buffer[i];
    }
    

    jstring buff = env->NewStringUTF(newBuff);

    delete newBuff;
    delete buffer;

    return buff;
}
