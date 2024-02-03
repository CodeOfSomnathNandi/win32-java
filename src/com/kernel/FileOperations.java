package com.kernel;

import java.io.IOException;

public class FileOperations {
    
    public static boolean CopyFile(String existingFilePath, String newFilePath) throws IOException {
        
        if (existingFilePath == null && newFilePath == null) {
            throw new IOException("File path is null");
        }

        
        
        return true;
    }

}
