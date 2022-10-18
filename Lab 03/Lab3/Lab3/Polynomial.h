// COS30008, Tutorial 3, 2022

#pragma once

#include <iostream>

#define MAX_POLYNOMIAL 10               // max degree for input
#define MAX_DEGREE MAX_POLYNOMIAL*2     // max degree = 10 + 10 = 20

class Polynomial
{
private:
	size_t fDegree;					// the maximum degree of the polynomial
	double fCoeffs[MAX_DEGREE+1];	// the coefficients (0..10, 0..20)

public:
	Polynomial();

	// binary operator* to multiple to polynomials
	// arguments are read-only, signified by const
	// the operator* returns a fresh polynomial with degree i+j
	Polynomial operator*( const Polynomial& aRHS ) const;

    // binary operator== to compare two polynomials
    // arguments are read-only, signified by const
    // the operator== returns true if this polynomial is
    // structurally equivalent to the aRHS polynomial
    bool operator==( const Polynomial& aRHS ) const;

	// input operator for polynomials (highest to lowest)
	friend std::istream& operator>>( std::istream& aIStream, Polynomial& aObject );

	// output operator for polynomials (highest to lowest)
	friend std::ostream& operator<<( std::ostream& aOStream, const Polynomial& aObject );
};
