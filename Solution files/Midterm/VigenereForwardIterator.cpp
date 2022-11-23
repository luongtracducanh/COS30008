
// COS30008, Midterm, Problem 4, 2022

#include "VigenereForwardIterator.h"

using namespace std;

VigenereForwardIterator::VigenereForwardIterator( iVigenereStream& aIStream ) :
    fIStream(aIStream),                                                     // 3
    fEOF(false)                                                             // 3
{
    ++(*this);                                                              // 4(10)
}

char VigenereForwardIterator::operator*() const
{
    return fCurrentChar;                                                    // (2)
}

VigenereForwardIterator& VigenereForwardIterator::operator++()
{
    fIStream >> fCurrentChar;                                               // 4

    fEOF = fIStream.eof();                                                  // 4

    return *this;                                                           // 2(10)
}

VigenereForwardIterator VigenereForwardIterator::operator++( int )
{
    VigenereForwardIterator temp = *this;                                   // 4
    
    ++(*this);                                                              // 4
    
    return temp;                                                            // 2(10)
}

bool VigenereForwardIterator::operator==( const VigenereForwardIterator& aOther ) const
{
    return &fIStream == &aOther.fIStream && fEOF == aOther.fEOF;            // (8)
}

bool VigenereForwardIterator::operator!=( const VigenereForwardIterator& aOther) const
{
    return !(*this == aOther);                                              // (4)
}

VigenereForwardIterator VigenereForwardIterator::begin() const
{
    VigenereForwardIterator Result = *this;                                 // 4
    
    Result.fIStream.reset();                                                // 4
    Result.fEOF = false;                                                    // 4

    return ++Result;                                                        // 4(16)
}

VigenereForwardIterator VigenereForwardIterator::end() const
{
    VigenereForwardIterator Result = *this;                                 // 4
    
    Result.fEOF = true;                                                     // 4

    return Result;                                                          // 2(10)
}                                                                           // 10+2+10+10+8+4+16+10 = (70)
