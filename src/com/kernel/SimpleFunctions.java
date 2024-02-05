package com.kernel;

/**
 * This class is not so important this contains purely native functions.
 * You should avoid this function and use Wrapper functions.
 * 
 * @author Somnath Nandi
 * @since 0.0.1
 */
public class SimpleFunctions {

    static {
        System.loadLibrary("win32");
    }

    public static native long GetLastError();

    public static native void SetLastError(long error_no);

    public static native long GetProcessVersion(long processId);

    public static native void ExitProcess(int uExitCode);

    public static native long GetCurrentProcessId();

    public static native boolean CopyFile(String lpExistingFileName, String lpNewFileName, boolean bFailIfExists);

    public static native boolean CreateDirectory(String lpPathName);

    public static native boolean DeleteFile(String lpFileName);

    public static native boolean MoveFile(String lpExistingFileName, String lpNewFileName);

    public static native String GetCurrentDirectory();

    public static native boolean CreateSymbolicLinkA(String lpSymlinkFileName, String lpTargetFileName, long dwFlags);

    public static native boolean DecryptFileA(String lpFileName, long dwReserved);

    public static native boolean EncryptFileA(String lpFileName);

    public static native boolean FileEncryptionStatusA(String lpFileName, long lpStatus);

    public static native long GetFileSize(String hFileName);

    public static native long GetFileType(String hFileName);

    public static native long CreateFileA(
            String lpFileName,
            long dwDesiredAccess,
            long dwShareMode,
            long dwCreationDisposition,
            long dwFlagsAndAttributes,
            long hTemplateFile);

    public static native String GetLongPathNameA(String lpszShortPath);

    public static native String GetTempPathA(String nBufferLength);

    public static native boolean CreateDirectoryA(String lpPathName);

    public static native boolean RemoveDirectoryA(String lpPathName);

    public static native boolean SetCurrentDirectory(String lpPathName);

    public static native int GetDriveTypeA(String lpRootPathName);

}
