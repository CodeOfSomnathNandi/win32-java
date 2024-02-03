package com.kernel;

public enum FileFlags {

    // The link target is a directory.
    SYMBOLIC_LINK_FLAG_DIRECTORY(0x1),
    // The link target is a file.
    SYMBOLIC_LINK_FLAG_FILE(0x0),
    // Specify this flag to allow creation of symbolic links when the process is not
    // elevated. In UWP, Developer Mode must first be enabled on the machine before
    // this option will function. Under MSIX, developer mode is not required to be
    // enabled for this flag.
    SYMBOLIC_LINK_FLAG_ALLOW_UNPRIVILEGED_CREATE(0x2);

    public int value = 0;

    FileFlags(int value) {
        this.value = value;
    }
}
