
// COS30008, Problem Set 1/2, 2022

#include "Polynomial.h"

#include <cmath>

using namespace std;

double Polynomial::operator()( double aX ) const
{
    double Result = 0.0;                                                    // 3
    
    for ( size_t i = 0; i <= fDegree; i++ )                                 // 5
    {
        Result += fCoeffs[i] * pow( aX, i );                                // 7
    }
    
    return Result;                                                          // 1/(16)
}

Polynomial Polynomial::getDerivative() const
{
    Polynomial Result;                                                      // 2
    
    if ( fDegree )                                                          // 2
    {
        Result.fDegree = fDegree - 1;                                       // 2
        
        for ( size_t i = 0; i < fDegree; i++ )                              // 6
        {
            Result.fCoeffs[i] = (i + 1) * fCoeffs[i + 1];                   // 6
        }
    }
    
    return Result;                                                          // 1/(19)
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
    Polynomial Result;                                                      // 2
    
    Result.fDegree = fDegree + 1;                                           // 2
    
    for ( size_t i = 1; i <= fDegree + 1; i++ )                             // 6
    {
        Result.fCoeffs[i] = fCoeffs[i - 1] / i;                             // 6
    }
    
    return Result;                                                          // 1/(17)
}

double Polynomial::getDefiniteIntegral( double aXLow, double aXHigh ) const
{
    Polynomial lIndefiniteIntegral = getIndefiniteIntegral();               // 4
    
    return lIndefiniteIntegral( aXHigh ) - lIndefiniteIntegral( aXLow );    // 4/(8)
}
                                                                            // 16+19+17+8=60
