#pragma once
// include for size_t (unsigned integral type)
#include <cstddef>
class IntVector
{
private:
	int* fElements;
	size_t fNumberOfElements;

public:
	// Constructor: copy argument array
	IntVector(const int aArrayOfIntegers[], size_t aNumberOfElements);

	// Destructor: release memory
	// Destructor is virtual to allow inheritance
	virtual ~IntVector();
	// size getter
	size_t size() const;

	// element getter
	const int get(size_t aIndex) const;
	// swap two elements within the vector
	void swap(size_t aSourceIndex, size_t aTargetIndex);
	// indexer
	const int operator[](size_t aIndex) const;
};