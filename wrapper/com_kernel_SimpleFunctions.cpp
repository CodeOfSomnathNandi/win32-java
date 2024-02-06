#include <windows.h>
#include <winerror.h>
#include <string>

#include "com_kernel_SimpleFunctions.h"
#include "utility.h"

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

    delete newFileName;
    delete existingFileName;
    return success == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateDirectory(JNIEnv *env, jclass, jstring lpPathName)
{
    char *pathName = jstring_to_cstr(env, lpPathName);
    int isSuccess = CreateDirectoryA(pathName, NULL);

    delete pathName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_DeleteFile(JNIEnv *env, jclass, jstring fileName)
{
    char *cfileName = jstring_to_cstr(env, fileName);
    int isSuccess = DeleteFileA(cfileName);

    delete cfileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_MoveFile(JNIEnv *env, jclass, jstring existingFileName, jstring newFileName)
{
    char *lpExistingFileName = jstring_to_cstr(env, existingFileName);
    char *lpNewFileName = jstring_to_cstr(env, newFileName);
    int isSuccess = MoveFileA(lpExistingFileName, lpNewFileName);

    delete lpExistingFileName;
    delete lpNewFileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jstring JNICALL Java_com_kernel_SimpleFunctions_GetCurrentDirectory(JNIEnv *env, jclass)
{
    const int size = 2056;
    LPSTR buffer = new char[size];
    DWORD length = GetCurrentDirectoryA(size, buffer);
    LPSTR newBuff = new char[length + 1];

    for (DWORD i = 0; i < length; i++)
    {
        newBuff[i] = buffer[i];
    }

    newBuff[length] = '\0';

    jstring buff = env->NewStringUTF(newBuff);

    delete newBuff;
    delete buffer;

    return buff;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateSymbolicLinkA(JNIEnv *env, jclass, jstring symlinkFileName, jstring targetFileName, jlong dwFlags)
{
    char *lpSymlinkFileName = jstring_to_cstr(env, symlinkFileName);
    char *lpTargetFileName = jstring_to_cstr(env, targetFileName);
    int isSuccess = CreateSymbolicLinkA(lpSymlinkFileName, lpTargetFileName, (DWORD)dwFlags);

    delete lpSymlinkFileName;
    delete lpTargetFileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_DecryptFileA(JNIEnv *env, jclass, jstring fileName, jlong dwReserved)
{
    char *lpFileName = jstring_to_cstr(env, fileName);
    int isSuccess = DecryptFileA(lpFileName, (DWORD)dwReserved);

    delete lpFileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_EncryptFileA(JNIEnv *env, jclass, jstring fileName)
{
    char *lpFileName = jstring_to_cstr(env, fileName);
    int isSuccess = EncryptFileA(lpFileName);

    delete lpFileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_FileEncryptionStatusA(JNIEnv *env, jclass, jstring fileName, jlong status)
{
    char *lpFileName = jstring_to_cstr(env, fileName);
    DWORD lpStatus;
    int isSuccess = FileEncryptionStatusA(lpFileName, &lpStatus);
    status = (jlong)lpStatus;

    delete lpFileName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetFileSize(JNIEnv *env, jclass, jstring fileName)
{
    char *lpFileName = jstring_to_cstr(env, fileName);

    HANDLE fileHandle = CreateFileA(lpFileName, GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD fileSize;
    GetFileSize(fileHandle, &fileSize);

    delete lpFileName;

    return (jlong)fileSize;
}

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_GetFileType(JNIEnv *env, jclass, jstring fileName)
{
    char *lpFileName = jstring_to_cstr(env, fileName);
    HANDLE fileHandle = CreateFileA(lpFileName, GENERIC_ALL, FILE_SHARE_READ, NULL, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
    DWORD fileType = GetFileType(fileHandle);

    delete lpFileName;

    return (jlong)fileType;
}

JNIEXPORT jlong JNICALL Java_com_kernel_SimpleFunctions_CreateFileA(JNIEnv *, jclass, jstring, jlong, jlong, jlong, jlong, jlong)
{
    
}

JNIEXPORT jstring JNICALL Java_com_kernel_SimpleFunctions_GetLongPathNameA(JNIEnv *env, jclass, jstring pathName)
{
    char *lpPathName = jstring_to_cstr(env, pathName);
    const int size = 2056;
    char *lpLongPathName = new char[size];
    int length = GetLongPathNameA(lpPathName, lpLongPathName, size);
    char* newBuff = new char[length+1];

    for (int i = 0; i < length; i++)
    {
        newBuff[i] = lpLongPathName[i];
    }
    newBuff[length] = '\0';

    delete lpPathName;
    delete lpLongPathName;
    delete newBuff;

    return env->NewStringUTF(newBuff);
}

JNIEXPORT jstring JNICALL Java_com_kernel_SimpleFunctions_GetTempPathA(JNIEnv *env, jclass, jstring)
{
    const int length = 2056;
    char *buff = new char[length];

    int totalLength = GetTempPathA(length, buff);
    char *newBuff = new char[totalLength + 1];

    for (int i = 0; i < totalLength; i++)
    {
        newBuff[i] = buff[i];
    }
    newBuff[totalLength] = '\0';

    delete buff;
    delete newBuff;

    return env->NewStringUTF(newBuff);
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_CreateDirectoryA(JNIEnv *env, jclass, jstring pathName)
{
    char *lpPathName = jstring_to_cstr(env, pathName);
    int isSuccess = CreateDirectoryA(lpPathName, NULL);

    delete lpPathName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_RemoveDirectoryA(JNIEnv *env, jclass, jstring pathName)
{
    char *lpPathName = jstring_to_cstr(env, pathName);
    int isSuccess = RemoveDirectoryA(lpPathName);

    delete lpPathName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}

JNIEXPORT jboolean JNICALL Java_com_kernel_SimpleFunctions_SetCurrentDirectory(JNIEnv *env, jclass, jstring pathName)
{
    char *lpPathName = jstring_to_cstr(env, pathName);
    int isSuccess = SetCurrentDirectoryA(lpPathName);

    delete lpPathName;

    return isSuccess == TRUE ? JNI_TRUE : JNI_FALSE;
}
