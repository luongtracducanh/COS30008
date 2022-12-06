
// COS30008, Tutorial 12, 2022

#pragma once

#include "IntVector.h"

#include <functional>

using Comparable = std::function<bool(int, int)>;

class SortableIntVector : public IntVector
{
public:

    SortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
        IntVector(aArrayOfIntegers, aNumberOfElements)
    {}
    
    virtual void sort( Comparable aOrderFunction ) = 0;
};

