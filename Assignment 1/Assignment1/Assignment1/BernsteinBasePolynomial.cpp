#include "BernsteinBasisPolynomial.h"
#include <cmath>

BernsteinBasisPolynomial::BernsteinBasisPolynomial(unsigned int aV, unsigned int aN) : fFactor(Combination(aN, aV))
{}

double BernsteinBasisPolynomial::operator()(double aX) const
{
	return fFactor() * pow(aX, fFactor.getK()) * pow((1 - aX), (fFactor.getN() - fFactor.getK()));
}