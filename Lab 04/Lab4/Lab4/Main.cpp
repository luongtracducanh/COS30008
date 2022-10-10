
// COS30008, Tutorial 4, 2022

//#define P1
//#define P2
//#define P3
//#define P4
//#define P5

#include <iostream>
#include <iomanip>

using namespace std;

#include "PassiveResistor.h"
#include "Capacitor.h"
#include "Inductor.h"

#ifdef P1

void runP1()
{
    PassiveResistor lR;

    cout << "Enter resistor value: ";
    cin >> lR;
    cout << "Passive resistor value: " << lR << endl;
    cout << "Current at 9.0V: " << lR.getCurrentAt( 9.0 ) << "A" << endl;
    cout << "Voltage drop at 200mA: " << lR.getPotentialAt( 0.2 ) << "V" << endl;
}

#endif

#ifdef P2

void runP2()
{
    Capacitor lC;

    cout << "Enter capacitor value: ";
    cin >> lC;
    cout << "Capacitor value: " << lC << endl;

    // create a temporary passive resistor object to properly format value
    cout << "XC at 60Hz: " << PassiveResistor( lC.getReactance( 60.0 ) ) << endl;
    cout << "Current at 9V and 60Hz: " << lC.getCurrentAt( 9.0, 60.0 ) << "A" << endl;
    cout << "Voltage drop at 2mA and 60Hz: " << lC.getPotentialAt( 0.002, 60.0 ) << "V" << endl;
}

#endif

#ifdef P3

void runP3()
{
    Capacitor lC( 0.00047 );

    cout << "Capacitor value: " << lC << endl;

    double lXC = 0.0;
    double lFrequency = 50.0;

    do
    {
        lXC = lC.getReactance( lFrequency );
        cout << "XC at " << setw( 5 ) << lFrequency << "Hz:\t" << PassiveResistor( lXC ) << endl;
        lFrequency += 50.0;
    } while (lXC > 1.0);
}

#endif

#ifdef P4

void runP4()
{
    Inductor lL;

    cout << "Enter inductor value: ";
    cin >> lL;
    cout << "Inductor value: " << lL << endl;

    // create a temporary passive resistor object to properly format value
    cout << "XC at 10kHz: " << PassiveResistor( lL.getReactance( 10000.0 ) ) << endl;
    cout << "Current at 9V and 10kHz: " << lL.getCurrentAt( 9.0, 10000.0 ) << "A" << endl;
    cout << "Voltage drop at 2mA and 10kHz: " << lL.getPotentialAt( 0.002, 10000.0 ) << "V" << endl;
}

#endif

#ifdef P5

void runP5()
{
    Inductor lL( 0.52 );

    cout << "Inductor value: " << lL << endl;

    double lXC = 0.0;
    double lFrequency = 50.0;

    do
    {
        lXC = lL.getReactance( lFrequency );
        cout << "XC at " << setw( 5 ) << lFrequency << "Hz:\t" << PassiveResistor( lXC ) << endl;
        lFrequency += 50.0;
    } while (lXC < 1000.0);
}

#endif

int main()
{
#ifdef P1

	runP1();

#endif

#ifdef P2

	runP2();

#endif

#ifdef P3

	runP3();

#endif

#ifdef P4

	runP4();

#endif

#ifdef P5

	runP5();

#endif

	return 0;
}
