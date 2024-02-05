package com.kernel;

import java.io.IOException;

public class NativeThread {

        public static native boolean CreateProcessA(String lpApplicationName, String lpCommandLine,
                        boolean bInheritHandles, long dwCreationFlags, long lpEnvironment, String lpCurrentDirectory);

        public static native void ExitProcess(int uExitCode);

        public static native String GetCommandLineA();

        public static native long GetCurrentProcess();

        private static native long GetCurrentProcessorNumber();

        private static native String GetEnvironmentVariable(String lpName);

        private static native int[] GetProcessTimes(long hProcess);

        private static native long OpenProcess(long dwDesiredAccess, boolean bInheritHandle, long dwProcessId);

        private static native boolean TerminateProcess(long hProcess, int uExitCode);

        public NativeThread(String processName) throws IOException {
                boolean isSuccess = CreateProcessA(processName, "", false, 0x00000010, 0, "");
                if (isSuccess) {
                        throw new IOException("Unable to create process");
                }
        }

}
