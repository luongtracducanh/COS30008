
// COS30008, Tutorial 4, 2022

#define _USE_MATH_DEFINES     // must be defined before any #include

#include "Inductor.h"

#include <cmath>

using namespace std;

bool Inductor::mustScale( double aValue ) const
{
	return aValue < 1.0;
}

const double Inductor::getMultiplier() const
{
	return 1000.0;
}

const std::string Inductor::getMajorUnit() const
{
	return "H";
}

const std::string Inductor::getMinorUnits() const
{
	return "Hmunp";
}

Inductor::Inductor( double aBaseValue ) :
	ResistorBase( aBaseValue )
{}

double Inductor::getReactance( double aFrequency ) const
{
	// PI = 4.0 * atan( 1.0 )
	// w = 2PIf
	// wL
	return (2 * M_PI * aFrequency) * getBaseValue();
}
