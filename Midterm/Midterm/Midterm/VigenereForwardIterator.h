#pragma once
#include "iVigenereStream.h"
class VigenereForwardIterator
{
private:
	iVigenereStream& fIStream;
	char fCurrentChar;
	bool fEOF;

public:
	VigenereForwardIterator(iVigenereStream& aIStream); // [10]
	// forward iterator interface
	char operator*() const; // [2]
	VigenereForwardIterator& operator++(); // prefix increment [10]
	VigenereForwardIterator operator++(int); // postfix increment [10]

	bool operator==(const VigenereForwardIterator& aOther) const; // [8]
	bool operator!=(const VigenereForwardIterator& aOther) const; // [4]

	VigenereForwardIterator begin() const; // [16]
	VigenereForwardIterator end() const; // [10]
};