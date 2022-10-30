
// COS30008, Tutorial 6, 2022

#include "FibonacciSequenceIterator.h"

FibonacciSequenceIterator::FibonacciSequenceIterator( const FibonacciSequence& aSequenceObject, uint64_t aStart ) :
    fSequenceObject(aSequenceObject),
    fIndex(aStart)
{}
    
FibonacciSequenceIterator::FibonacciSequenceIterator( uint64_t aLimit, uint64_t aStart ) :
    fSequenceObject(aLimit),
    fIndex(aStart)
{}

const uint64_t& FibonacciSequenceIterator::operator*() const
{
    return fSequenceObject.current();
}

FibonacciSequenceIterator& FibonacciSequenceIterator::operator++()
{
    fSequenceObject.advance();
    fIndex++;
    
    return *this;
}

FibonacciSequenceIterator FibonacciSequenceIterator::operator++( int )
{
    FibonacciSequenceIterator result = *this;
    
    ++(*this);
    
    return result;
}

bool FibonacciSequenceIterator::operator==( const FibonacciSequenceIterator& aOther ) const
{
    return fIndex == aOther.fIndex;
}

bool FibonacciSequenceIterator::operator!=( const FibonacciSequenceIterator& aOther) const
{
    return !(*this == aOther);
}

FibonacciSequenceIterator FibonacciSequenceIterator::begin() const
{
    FibonacciSequenceIterator Result = *this;
    
    Result.fSequenceObject.reset();
    Result.fIndex = 1;
    
    return Result;
}

FibonacciSequenceIterator FibonacciSequenceIterator::end() const
{
    FibonacciSequenceIterator Result = *this;
    uint64_t lLimit = Result.fSequenceObject.getLimit();
    
    if ( lLimit != 0 )
    {
        Result.fIndex = lLimit + 1;
    }
    else
    {
        Result.fIndex = 0;
    }

    return Result;
}
