#pragma once
#include "IntVector.h"
#include <functional>
using Comparable = std::function<bool(int, int)>;
class SortableIntVector : public IntVector
{
public:
	SortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

	virtual void sort(Comparable aOrderFunction);
};