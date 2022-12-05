
// COS30008, Tutorial 4, 2022

#include "ResistorBase.h"

using namespace std;

void ResistorBase::setBaseValue( double aBaseValue )
{
    fBaseValue = aBaseValue;
}

ResistorBase::ResistorBase( double aBaseValue )
{
    setBaseValue( aBaseValue );
}

// returns base value
double ResistorBase::getBaseValue() const
{
    return fBaseValue;
}

// returns (frequency-dependent) voltage drop
double ResistorBase::getPotentialAt( double aCurrent, double aFrequency ) const
{
    // V = R * I
    
    return getReactance( aFrequency ) * aCurrent;
}

// returns (frequency-dependent) current flowing through a resistor
double ResistorBase::getCurrentAt( double aVoltage, double aFrequency ) const
{
    // I = V / R
    
    return aVoltage / getReactance( aFrequency );
}

// resistor I/O
istream& operator>>( istream& aIStream, ResistorBase& aObject )
{
    double lRawValue;
    string lRawUnit;
    
    aIStream >> lRawValue >> lRawUnit;
    
    aObject.flatten( lRawValue, lRawUnit );
    
    return aIStream;
}

ostream& operator<<( ostream& aOStream, const ResistorBase& aObject )
{
    double lNormalizeValue;
    string lNormalizedUnit;
    
    aObject.normalize( lNormalizeValue, lNormalizedUnit );
    
    aOStream << lNormalizeValue << ' ' << lNormalizedUnit;
    
    return aOStream;
}
