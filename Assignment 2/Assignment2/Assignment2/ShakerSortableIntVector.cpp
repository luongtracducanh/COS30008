#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector(const int aArrayOfIntegers[], size_t aNumberOfElements) : SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{}

void ShakerSortableIntVector::sort(Comparable aOrderFunction)
{
	for (size_t i = 0; i < (*this).size(); i++)
	{
		for (size_t j = (*this).size() - 1; j > i; j--)
		{
			if (aOrderFunction(get(j - 1), get(j)))
			{
				(*this).swap(j, j - 1);
			}
		}
	}
}