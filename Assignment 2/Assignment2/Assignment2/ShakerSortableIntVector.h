#pragma once
#include "SortableIntVector.h"
class ShakerSortableIntVector : public SortableIntVector
{
public:
	ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

	void sort(Comparable aOrderFunction = [](int aLeft, int aRight)
		{ return aLeft <= aRight; }) override;
};