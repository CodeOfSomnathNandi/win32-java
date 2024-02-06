#include "com_kernel_NativeProcess.h"
#include "utility.h"
#include <windows.h>

JNIEXPORT jlong JNICALL Java_com_kernel_NativeProcess_CreateProcessA(JNIEnv *env, jclass, jstring applicationName, jstring commandLine, jboolean bInheritHandles, jlong dwCreationFlags, jlong lpEnvironment, jstring currentDirectory)
{
    char *lpApplicationName = jstring_to_cstr(env, applicationName);
    char *lpCommandLine = jstring_to_cstr(env, commandLine);
    char *lpCurrentDirectory = jstring_to_cstr(env, currentDirectory);
    PROCESS_INFORMATION pi;
    CreateProcessA(lpApplicationName, lpCommandLine, NULL, NULL, bInheritHandles, dwCreationFlags, NULL, lpCurrentDirectory, NULL, &pi);

    delete lpApplicationName;
    delete lpCommandLine;
    delete lpCurrentDirectory;

    return (jlong)pi.hProcess;
}

JNIEXPORT void JNICALL Java_com_kernel_NativeProcess_ExitProcess(JNIEnv *, jclass, jint exitCode)
{
    ExitProcess(exitCode);
}

JNIEXPORT jstring JNICALL Java_com_kernel_NativeProcess_GetCommandLineA(JNIEnv *env, jclass)
{
    LPSTR lpCmdLine = GetCommandLineA();
    jstring cmdLine = env->NewStringUTF(lpCmdLine);
    return cmdLine;
}

JNIEXPORT jlong JNICALL Java_com_kernel_NativeProcess_GetCurrentProcess(JNIEnv *, jclass)
{
    HANDLE currentHandle = GetCurrentProcess();
    return (jlong)currentHandle;
}

JNIEXPORT jlong JNICALL Java_com_kernel_NativeProcess_GetCurrentProcessorNumber(JNIEnv *, jclass)
{
    return GetCurrentProcessorNumber();
}

JNIEXPORT jstring JNICALL Java_com_kernel_NativeProcess_GetEnvironmentVariable(JNIEnv *env, jclass, jstring envName)
{
    char *lpEnvName = jstring_to_cstr(env, envName);
    const int size = 2056;
    char *lpValue = new char[size];
    long newSize = GetEnvironmentVariableA(lpEnvName, lpValue, size);
    char *finalValue = new char[newSize + 1];
    for (int i = 0; i < newSize; i++)
    {
        finalValue[i] = lpValue[i];
    }

    finalValue[newSize] = '\0';
    jstring value = env->NewStringUTF(finalValue);

    // freeing memory
    delete lpEnvName;
    delete lpValue;
    delete finalValue;

    return value;
}

JNIEXPORT jintArray JNICALL Java_com_kernel_NativeProcess_GetProcessTimes(JNIEnv *env, jclass, jlong hProcess)
{
    FILETIME creationTime;
    FILETIME exitTime;
    FILETIME kernelTime;
    FILETIME userTime;
    GetProcessTimes((HANDLE)hProcess, &creationTime, &exitTime, &kernelTime, &userTime);

    jintArray jarr = env->NewIntArray(4);

    jint *arr = env->GetIntArrayElements(jarr, NULL);

    arr[0] = creationTime.dwHighDateTime;
    arr[1] = exitTime.dwHighDateTime;
    arr[2] = kernelTime.dwHighDateTime;
    arr[3] = userTime.dwHighDateTime;

    return jarr;
}

JNIEXPORT jlong JNICALL Java_com_kernel_NativeProcess_OpenProcess(JNIEnv *, jclass, jlong dwDesiredAccess, jboolean bInheritHandle, jlong dwProcessId)
{
    HANDLE processHandle = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
    return (jlong)processHandle;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_NativeProcess_TerminateProcess(JNIEnv *, jclass, jlong handle, jint exitCode)
{
    int isSuccess = TerminateProcess((LPVOID)handle, exitCode);
    if (isSuccess)
    {
        return JNI_TRUE;
    }
    else
    {
        return JNI_FALSE;
    }
}
