
// COS30008, Tutorial 10, 2022

#pragma once

#include <stdexcept>

#include <iostream>

template<class T>
class Handle
{
private:
    T* fPointer;
    size_t* fCount;

    void addRef();
    void releaseRef();

public:
    
    Handle( T* aPointer = nullptr );
    Handle( const Handle<T>& aOtherHandle );
    Handle& operator=( Handle<T>& aOtherHandle );
    ~Handle();

    T& operator*();
    T* operator->();
};
