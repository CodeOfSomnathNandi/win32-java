package com.kernel;

public class Handle {
    private long handleValue = -1;

    public Handle(long value) {
        this.handleValue = value;
    }
    
    public long getHandleValue() {
        return this.handleValue;
    }

}