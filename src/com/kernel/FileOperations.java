package com.kernel;

import java.io.FileNotFoundException;
import java.io.IOException;

public class FileOperations {
    
    public  boolean CopyFile(String existingFilePath, String newFilePath) throws IOException {
        
        // clearing previous error value
        SimpleFunctions.GetLastError();

        if (existingFilePath == null && newFilePath == null) {
            throw new IOException("File path is null");
        }

        boolean isSuccess = SimpleFunctions.CopyFile(existingFilePath, newFilePath, true);
        if (isSuccess) {
            return true;
        }
        var error_no = SimpleFunctions.GetLastError();
        if (error_no == WinErrorCodes.ERROR_FILE_NOT_FOUND.getValue()) {
            throw new FileNotFoundException(String.format("{} Not Found.", existingFilePath));
        }
        
        if (WinErrorCodes.ERROR_ACCESS_DENIED.getValue() == error_no) {
            throw new IOException(String.format("{} Access Denied.", existingFilePath));
        }
        

        return false;
    }

    // @Override
    // public 
}
