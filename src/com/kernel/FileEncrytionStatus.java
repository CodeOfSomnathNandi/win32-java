package com.kernel;

public enum FileEncrytionStatus {
    // The file is encrypted.
    FILE_IS_ENCRYPTED(1),
    // The file is a read-only file.
    FILE_READ_ONLY(8),
    // The file is a root directory. Root directories cannot be encrypted.
    FILE_ROOT_DIR(3),
    // The file is a system file. System files cannot be encrypted.
    FILE_SYSTEM_ATTR(2),
    // The file is a system directory. System directories cannot be encrypted.
    FILE_SYSTEM_DIR(4),
    // The file system does not support file encryption.
    FILE_SYSTEM_NOT_SUPPORT(6),
    // The encryption status is unknown. The file may be encrypted.
    FILE_UNKNOWN(5),
    // Reserved for future use.
    FILE_USER_DISALLOWED(7),
    // The file can be encrypted.
    // Home, Home Premium, Starter, and ARM Editions of Windows: FILE_ENCRYPTABLE
    // may be returned but EFS does not support encrypting files on these editions
    // of Windows
    FILE_ENCRYPTABLE(0);

    public int value = 0;

    FileEncrytionStatus(int value) {
        this.value = value;
    }
}
