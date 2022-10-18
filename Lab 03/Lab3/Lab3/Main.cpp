// COS30008, Tutorial 3, 2022

#include <iostream>

#include "Polynomial.h"

using namespace std;

int main()
{
	Polynomial A;
	cout << "Specify first polynomial (degree followed by coefficients):" << endl;
	cin >> A;
	cout << "A = " << A << endl;

    Polynomial AA = A;
    
    if ( AA == A )
    {
        cout << "Comparison successful." << endl;
    }
    else
    {
        cout << "Comparison failed." << endl;
    }
    
	Polynomial B;
	cout << "Specify second polynomial (degree followed by coefficients):" << endl;
	cin >> B;
	cout << "B = " << B << endl;

	Polynomial C = A * B;
	cout << "C = A * B = " << C << endl;

	return 0;
}
