package com.kernel;

public class NativeThread {
    public static native boolean CreateProcessA(
            String lpApplicationName,
            String lpCommandLine,
            boolean bInheritHandles,
            long dwCreationFlags,
            long lpEnvironment,
            String lpCurrentDirectory);

    public static native void ExitProcess(
            int uExitCode);

    public static native String GetCommandLineA();

    public static native long GetCurrentProcess();

    private static native long GetCurrentProcessorNumber();

    private static native String GetEnvironmentVariable(String lpName);

    private static native int[] GetProcessTimes(long hProcess);

    private static native long OpenProcess(
            long dwDesiredAccess,
            boolean bInheritHandle,
            long dwProcessId);

    private static native boolean TerminateProcess(
            long hProcess,
            int uExitCode);
}
