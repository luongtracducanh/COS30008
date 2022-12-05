
// COS30008, Problem Set 1/3, 2022

#include "Combination.h"

Combination::Combination( size_t aN, size_t aK ) :
    fN(aN),                                                         // 2
    fK(aK)                                                          // 2/(4)
{}

size_t Combination::getN() const
{
    return fN;                                                      // (2)
}

size_t Combination::getK() const
{
    return fK;                                                      // (2)
}

unsigned long long Combination::operator()() const
{
    if ( fK > fN )                                                  // 3
    {
        return 0;                                                   // 2
    }
    else
    {
        unsigned long long Result = 1;                              // 2

        for ( unsigned long long i = 0; i < fK; )                   // 8
        {
            Result *= (fN - i);                                     // 7
            Result /= ++i;                                          // 7
        }

        return Result;                                              // 1(30)
    }
}                                                                   // 4+2+2+30 = 38
