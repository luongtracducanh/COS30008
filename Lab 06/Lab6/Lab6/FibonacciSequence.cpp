#include "FibonacciSequence.h"
#include "FibonacciSequenceIterator.h"
#include <stdexcept>

FibonacciSequence::FibonacciSequence(uint64_t aLimit) :fPrevious(0), fCurrent(1), fPosition(1), fLimit(aLimit){}

const uint64_t& FibonacciSequence::current() const
{
	return fCurrent;
}

void FibonacciSequence::advance()
{
	if (fPosition > fLimit && fLimit != 0)
	{
		throw std::out_of_range("Maximum Fibonacci position reached");
	}
	uint64_t lNext = fCurrent + fPrevious;
	fPrevious = fCurrent;
	fCurrent = lNext;
	fPosition++;
}

const uint64_t& FibonacciSequence::getLimit() const
{
	return fLimit;
}

void FibonacciSequence::reset()
{
	fPrevious = 0;
	fCurrent = 1;
	fPosition = 1;
}

FibonacciSequenceIterator FibonacciSequence::begin() const
{
	FibonacciSequenceIterator result = FibonacciSequenceIterator(*this);
	return result.begin();
}

FibonacciSequenceIterator FibonacciSequence::end() const
{
	FibonacciSequenceIterator result = FibonacciSequenceIterator(*this);
	return result.end();
}
