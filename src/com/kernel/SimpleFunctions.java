package com.kernel;
/**
 * This class is not so important this contains purely native functions.
 * You should avoid this function and use Wrapper functions.
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
    public static native boolean CreateDirectory(String lpPathName, SecurityAttributes attr);
    public static native boolean DeleteFile(String lpFileName);
    public static native boolean MoveFile(String lpExistingFileName, String lpNewFileName);
    public static native String GetCurrentDirectory();
}
