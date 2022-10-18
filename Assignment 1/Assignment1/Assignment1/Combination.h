#pragma once
#include <cstddef>
class Combination
{
private:
	size_t fN;
	size_t fK;

public:
	// constructor for combination n over k with defaults
	Combination(size_t aN = 0, size_t aK = 0);
	// getters
	size_t getN() const;
	size_t getK() const;
	// call operator to calculate n over k
	// We do not want to evaluate factorials.
	// Rather, we use this method
	//
	// n (n-0) (n-1) (n - (k - 1))
	// ( ) = ----- * ----- * ... * -------------
	// k 1 2 k
	//
	// which maps to a simple for-loop over 64-bit values.
	// https://en.wikipedia.org/wiki/Combination
	unsigned long long operator()() const;
};