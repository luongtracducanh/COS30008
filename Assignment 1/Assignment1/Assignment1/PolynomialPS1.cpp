#include "Polynomial.h"
#include <cmath>

double Polynomial::operator()(double aX) const
{
	double result = 0.0;

	for (int i = 0; i <= fDegree; i++) {
		result += fCoeffs[i] * pow(aX, i);
	}
	return result;
}

Polynomial Polynomial::getDerivative() const
{
	Polynomial Result;

	if (fDegree == 0) {
		return Result;
	}

	Result.fDegree = fDegree - 1;

	for (size_t i = 1; i <= fDegree; i++) {
		Result.fCoeffs[i - 1] = fCoeffs[i] * i;
	}

	return Result;
}

Polynomial Polynomial::getIndefiniteIntegral() const
{
	Polynomial Result;

	Result.fDegree = fDegree + 1;

	for (int i = fDegree; i >= 0; i--) {
		Result.fCoeffs[i + 1] = fCoeffs[i] / (i + 1);
	}

	return Result;
}

double Polynomial::getDefiniteIntegral(double aXLow, double aXHigh) const
{
	return this->getIndefiniteIntegral()(aXHigh) - this->getIndefiniteIntegral()(aXLow);
}