#pragma once
#include <iostream>
#define MAX_POLYNOMIAL 10 // max degree for input
#define MAX_DEGREE MAX_POLYNOMIAL*2+1 // max degree = 10 + 10 + 1 = 21
class Polynomial
{
private:
	size_t fDegree; // the maximum degree of the polynomial
	double fCoeffs[MAX_DEGREE + 1]; // the coefficients (0..10, 0..20)
public:
	// the default constructor (initializes all member variables)
	Polynomial();
	// binary operator* to multiple two polynomials
	// arguments are read-only, signified by const
	// the operator* returns a fresh polynomial with degree i+j
	Polynomial operator*(const Polynomial& aRHS) const;
	// binary operator== to compare two polynomials
	// arguments are read-only, signified by const
	// the operator== returns true if this polynomial is
	// structurally equivalent to the aRHS polynomial
	bool operator==(const Polynomial& aRHS) const;
	// input operator for polynomials (highest to lowest)
	friend std::istream& operator>>(std::istream& aIStream,
		Polynomial& aObject);
	// output operator for polynomials (highest to lowest)
	friend std::ostream& operator<<(std::ostream& aOStream,
		const Polynomial& aObject);
	// Problem Set 1 extension
	// call operator to calculate polynomial for a given x (i.e., aX)
	double operator()(double aX) const;
	// compute derivative: the derivative is a fresh polynomial with degree
	 // fDegree-1, the method does not change the current object
	Polynomial getDerivative() const;

	// compute indefinite integral: the indefinite integral is a fresh
   // polynomial with degree fDegree+1
	// the method does not change the current object
	Polynomial getIndefiniteIntegral() const;
	// calculate definite integral: the method does not change the current
   // object; the method computes the indefinite integral and then
	// calculates it for xlow and xhigh and returns the difference
	double getDefiniteIntegral(double aXLow, double aXHigh) const;
};