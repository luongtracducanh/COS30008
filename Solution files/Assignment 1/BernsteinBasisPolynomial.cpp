
// COS30008, Problem Set 1/4, 2022

#include "BernsteinBasisPolynomial.h"

#include <cmath>

using namespace std;

BernsteinBasisPolynomial::BernsteinBasisPolynomial( unsigned int aV, unsigned int aN ) :
    fFactor(aN, aV)                                                     // (4)
{}

double BernsteinBasisPolynomial::operator()( double aX ) const
{
    double Result = fFactor() * pow( aX, fFactor.getK() );              // 7
    
    return Result * pow( 1 - aX, fFactor.getN() - fFactor.getK() );     // 9(16)
}                                                                       // 4+16 = 20
