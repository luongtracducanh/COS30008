#include "Combination.h"

Combination::Combination(size_t aN, size_t aK) : fN(aN), fK(aK)
{}

size_t Combination::getN() const
{
	return fN;
}

size_t Combination::getK() const
{
	return fK;
}

unsigned long long Combination::operator()() const
{
	if (fK > fN) return 0ll;
	unsigned long long Result = 1;

	for (size_t i = 0; i < fK; i++) {
		Result *= (fN - i);
		Result /= (i + 1);
	}

	return Result;
}