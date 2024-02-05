package com.kernel;

public enum ProcessCreationFlags {
    
    CREATE_BREAKAWAY_FROM_JOB(0x01000000),
    CREATE_DEFAULT_ERROR_MODE(0x04000000),
    CREATE_NEW_CONSOLE(0x00000010),
    CREATE_NEW_PROCESS_GROUP(0x00000200),
    CREATE_NO_WINDOW(0x08000000),
    CREATE_PROTECTED_PROCESS(0x00040000);

    public int value = 0;
    ProcessCreationFlags(int value) {
        this.value = value;
    }
}
