
// COS30008, Tutorial 12, 2022

#pragma once

#include "SortableIntVector.h"

class FisherAndYatesSort : public SortableIntVector
{
private:
    void shuffle();
    
public:
    
    FisherAndYatesSort( const int aArrayOfIntegers[], size_t aNumberOfElements );
    
    void sort( Comparable aOrderFunction ) override;
};
