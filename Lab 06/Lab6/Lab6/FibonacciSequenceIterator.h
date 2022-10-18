
// COS30008, Tutorial 6, 2022

#pragma once

#include "FibonacciSequence.h"

class FibonacciSequenceIterator
{
private:
    FibonacciSequence fSequenceObject;              // Sequence object
    uint64_t fIndex;                                // current iterator position

public:
    
    // iterator constructor, copies FibonacciSequence object
    // and aStart set by default to 1
    FibonacciSequenceIterator( const FibonacciSequence& aSequenceObject, uint64_t aStart = 1 );

    // iterator constructor, initializes FibonacciSequence object
    // and aStart set by default to 1
    FibonacciSequenceIterator( uint64_t aLimit = 20, uint64_t aStart = 1 );
    
    // iterator methods
    
    const uint64_t& operator*() const;              // return current Fibonacci number
    FibonacciSequenceIterator& operator++();        // prefix, next Fibonacci number
    FibonacciSequenceIterator operator++( int );    // postfix (extra unused argument)
    bool operator==( const FibonacciSequenceIterator& aOther ) const;
    bool operator!=( const FibonacciSequenceIterator& aOther) const;

    // iterator methods
    
    // return new iterator positioned at start
    FibonacciSequenceIterator begin() const;

    // return new iterator positioned at limit
    FibonacciSequenceIterator end() const;
};
