package com.kernel;

import java.io.IOException;

public class NativeProcess {

        public static native long CreateProcessA(String lpApplicationName, String lpCommandLine,
                        boolean bInheritHandles, long dwCreationFlags, long lpEnvironment, String lpCurrentDirectory);

        public static native void ExitProcess(int uExitCode);

        public static native String GetCommandLineA();

        public static native long GetCurrentProcess();

        private static native long GetCurrentProcessorNumber();

        private static native String GetEnvironmentVariable(String lpName);

        private static native int[] GetProcessTimes(long hProcess);

        private static native long OpenProcess(long dwDesiredAccess, boolean bInheritHandle, long dwProcessId);

        private static native boolean TerminateProcess(long hProcess, int uExitCode);
        private static native long GetCurrentProcessId();

        private Handle threadHandle;

        private long creationTime;
        private long exitTime;
        private long kernelTime;
        private long userTime;

        private NativeProcess(Handle handle) throws IOException {
                threadHandle = handle;

                int[] array = GetProcessTimes(threadHandle.getHandleValue());
                long error_no = SimpleFunctions.GetLastError();
                if (error_no != WinErrorCodes.NO_ERROR.value) {
                        throw new IOException("Unable to create process");
                }

                creationTime = array[0];
                exitTime = array[1];
                kernelTime = array[2];
                userTime = array[3];
        }

        public NativeProcess(String processName) throws IOException {
                SimpleFunctions.GetLastError();
                long handle = CreateProcessA(processName, "", false,
                                ProcessCreationFlags.CREATE_NEW_CONSOLE.value, 0, "");
                threadHandle = new Handle(handle);
                long error_no = SimpleFunctions.GetLastError();
                if (error_no != WinErrorCodes.NO_ERROR.value) {
                        throw new IOException("Unable to create process");
                }

                int[] array = GetProcessTimes(threadHandle.getHandleValue());
                error_no = SimpleFunctions.GetLastError();
                if (error_no != WinErrorCodes.NO_ERROR.value) {
                        throw new IOException("Unable to seeting process info.");
                }

                creationTime = array[0];
                exitTime = array[1];
                kernelTime = array[2];
                userTime = array[3];

        }

        public void exit(int exitCode) throws IOException {
                boolean isSuccess = TerminateProcess(threadHandle.getHandleValue(), exitCode);
                if (!isSuccess) {
                        throw new IOException("Unable to terminate process");
                }
        }

        public long getCreationTime() {
                return creationTime;
        }

        public long getExitTime() {
                return exitTime;
        }

        public long getKernelTime() {
                return kernelTime;
        }

        public long getUserTime() {
                return userTime;
        }

        public String getCommandLineString() {
                return GetCommandLineA();
        }

        public long getPID() {
                return GetCurrentProcessId();
        }

        public long getCurrentProccessorNumber() {
                return GetCurrentProcessorNumber();
        }

        public static NativeProcess getCurrentProcessHandle() throws IOException {
                long handle = GetCurrentProcess();
                Handle threadHandle = new Handle(handle);
                NativeProcess nativeProcess = new NativeProcess(threadHandle);
                return nativeProcess;
        }

        public static NativeProcess openProcess(long dwDesiredAccess, boolean bInheritHandle, long dwProcessId)
                        throws IOException {
                long handle = OpenProcess(dwDesiredAccess, bInheritHandle, dwProcessId);
                Handle threadHandle = new Handle(handle);
                NativeProcess nativeProcess = new NativeProcess(threadHandle);
                return nativeProcess;
        }

        public void exitCurrentProcess(int exitCode) {
                ExitProcess(exitCode);
        }

}
