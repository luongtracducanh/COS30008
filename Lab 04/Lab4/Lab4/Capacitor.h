
// COS30008, Tutorial 4, 2022

#pragma once

#include "ResistorBase.h"

class Capacitor : public ResistorBase
{
protected:

    // auxiliary methods
    // aValue < 1.0
    bool mustScale( double aValue ) const override;
    // 1000.0
    const double getMultiplier() const override;
    // "F"
    const std::string getMajorUnit() const override;
    // minor units: "Fmunp", the first letter means "no major unit"
    const std::string getMinorUnits() const override;

public:

    // constructor with a default value
    Capacitor( double aBaseValue = 0.0 );

    // returns (frequency-dependent) passive resistance value
    double getReactance( double aFrequency = 0.0 ) const override;
};

