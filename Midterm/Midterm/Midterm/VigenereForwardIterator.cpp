#include "VigenereForwardIterator.h"

VigenereForwardIterator::VigenereForwardIterator(iVigenereStream& aIStream): fIStream(aIStream), fCurrentChar(0), fEOF(aIStream.eof())
{
    if (!fEOF)
    {
    	fIStream >> fCurrentChar;
    }
}

char VigenereForwardIterator::operator*() const
{
    return fCurrentChar;
}

VigenereForwardIterator& VigenereForwardIterator::operator++()
{
    fIStream >> fCurrentChar;
    fEOF = fIStream.eof();
    return *this;
}

VigenereForwardIterator VigenereForwardIterator::operator++(int)
{
    VigenereForwardIterator temp = *this;
    ++(*this);
    return temp;
}

bool VigenereForwardIterator::operator==(const VigenereForwardIterator& aOther) const
{
    return (&fIStream == &aOther.fIStream) && (fEOF == aOther.fEOF);
}

bool VigenereForwardIterator::operator!=(const VigenereForwardIterator& aOther) const
{
    return !(*this == aOther);
}

VigenereForwardIterator VigenereForwardIterator::begin() const
{
    VigenereForwardIterator lResult = *this;
    lResult.fIStream.reset();
    lResult.fEOF = lResult.fIStream.eof();
    if (!lResult.fEOF)
    {
        lResult.fIStream >> lResult.fCurrentChar;
    }
    return lResult;
}

VigenereForwardIterator VigenereForwardIterator::end() const
{
    VigenereForwardIterator lResult = *this;
    lResult.fEOF = true;
    return lResult;
}