package com.kernel;

import java.io.FileNotFoundException;
import java.io.IOException;

public class FileOperations {
    
    public static boolean CopyFile(String existingFilePath, String newFilePath) throws IOException {
        
        // clearing previous error value
        SimpleFunctions.GetLastError();

        if (existingFilePath == null || newFilePath == null) {
            throw new IOException("File path is null");
        }

        boolean isSuccess = SimpleFunctions.CopyFile(existingFilePath, newFilePath, true);
        if (isSuccess) {
            return true;
        }
        var error_no = SimpleFunctions.GetLastError();
        if (error_no == WinErrorCodes.ERROR_FILE_NOT_FOUND.getValue()) {
            throw new FileNotFoundException(String.format("%s Not Found.", existingFilePath));
        }
        
        if (WinErrorCodes.ERROR_ACCESS_DENIED.getValue() == error_no) {
            throw new IOException(String.format("%s Access Denied.", existingFilePath));
        }
        

        return false;
    }


    public static void MoveFile(String existingFileName, String newFileName) throws IOException {
        // resetting error no.
        SimpleFunctions.GetLastError();

        if (existingFileName == null || newFileName == null) {
            throw new IOException("File path is null");
        }

        boolean isSuccess =  SimpleFunctions.MoveFile(existingFileName, newFileName);

        if (isSuccess) {
            return;
        }

        long error = SimpleFunctions.GetLastError();

        if (error == WinErrorCodes.ERROR_PATH_NOT_FOUND.getValue()) {
            throw new IOException("Path Not Found.");
        }

        if (error != 0) {
            throw new IOException(String.format("Native function throw error: %d", error));
        }

    }

    // @Override
    // public 
}
