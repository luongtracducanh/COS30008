
// COS30008, Tutorial 6, 2022

#pragma once

#include <cstdint>

// forward declaration to break mutual recursion of
// FibonacciSequence and FibonacciSequence
class FibonacciSequenceIterator;

class FibonacciSequence
{
private:
    uint64_t fPrevious;    // previous Fibonacci number (initially 0)
    uint64_t fCurrent;     // current Fibonacci number (initially 1)
    uint64_t fPosition;    // position in the sequence (starts with 1)
    uint64_t fLimit;       // set limit for sequence (0 for no limit)

public:
    
    // Default constructor to set up a Fibonacci sequence
    // (aLimit = 0 means infinite)
    FibonacciSequence( uint64_t aLimit = 20 );
    
    // get current Fibonacci number
    const uint64_t& current() const;

    // advance to next Fibonacci number, may throw out_of_range exception on
    // exceeding limit
    void advance();
    
    // extract sequence limit
    const uint64_t& getLimit() const;
    
    // restart sequence
    void reset();
    
    // return new iterator positioned at start
    FibonacciSequenceIterator begin() const;

    // return new iterator positioned at a desired limit
    FibonacciSequenceIterator end() const;
};
