#include <iostream>
#include <fstream>
#include <iomanip>

//#define P1
//#define P2
//#define Automate
//#define P3
//#define P4

using namespace std;

#ifdef P1
#include "Polygon.h"
void runProblem1(Polygon& aShape)
{
	cout << "Calculating the signed area:" << endl;
	float lArea = aShape.getSignedArea();

	cout << "The area of the polygon is " << fabs(lArea) << endl;

	if (lArea > 0.0)
	{
		cout << "The vertices in the polygon are arranged in counterclockwise order."
			<< endl;
	}
	else
	{
		cout << "The vertices in the polygon are arranged in clockwise order." << endl;
	}
}
#endif

#ifdef P2
#include "Polynomial.h"
void runProblem2()
{
    Polynomial A;
    cout << "Specify polynomial:" << endl;
    cin >> A;
    cout << "A = " << A << endl;
    double x;
    cout << "Specify value of x:" << endl;
    cin >> x;
    cout << "A(x) = " << A(x) << endl;
    Polynomial B;
    if (B == B.getDerivative())
    {
        cout << "Derivative programmatically sound." << endl;
    }
    else
    {
        cout << "Derivative is broken." << endl;
    }
    if (A == A.getIndefiniteIntegral().getDerivative())
    {
        cout << "Polynomial operations are sound." << endl;
    }
    else
    {
        cout << "Polynomial operations are broken." << endl;
    }
    cout << "Indefinite integral of A = "
        << A.getIndefiniteIntegral() << endl;
    cout << "Derivative of A = "
        << A.getDerivative() << endl;
    cout << "Derivative of indefinite integral of A = "
        << A.getIndefiniteIntegral().getDerivative() << endl;
    cout << "Definite integral of A(xlow=0, xhigh=12.0) = "
        << A.getDefiniteIntegral(0, 12.0) << endl;
}
#endif

#ifdef P3
#include "Combination.h"
void runProblem3()
{
    // first 10 levels of Pascal's triangle

    cout << "The first ten levels of Pascal's triangle:" << endl;

    for (size_t n = 0; n < 10; n++)
    {
        cout << "(n=" << n << ", 0<=k<=" << n << "):";

        int lLead = ((10 - static_cast<int>(n))) * 3;
        for (size_t k = 0; k <= n; k++)
        {
            Combination lC(n, k);
            cout << setw(lLead) << " " << setw(3) << lC();
            lLead = 3;
        }

        cout << endl;
    }

    cout << "\nLarge Numbers:" << endl;
    Combination a(28, 14);
    Combination b(52, 5);
    cout << a.getN() << " over " << a.getK() << " = " << a() << endl;
    cout << b.getN() << " over " << b.getK() << " = " << b() << endl;
}
#endif

#ifdef P4
#include "BernsteinBasisPolynomial.h"
void runProblem4()
{
    BernsteinBasisPolynomial bba(0, 4);
    BernsteinBasisPolynomial bbb(1, 4);
    BernsteinBasisPolynomial bbc(2, 4);
    BernsteinBasisPolynomial bbd(3, 4);
    BernsteinBasisPolynomial bbe(4, 4);
    for (double i = 0.0; i < 1.1; i += 0.2)
    {
        cout << "4th degree Bernstein basis polynomial at "
            << i << " = "
            << bba(i) + bbb(i) + bbc(i) + bbd(i) + bbe(i)
            << endl;
    }
}
#endif

int main(int argc, char* argv[])
{
#ifdef P1
    if (argc < 2)
    {
        cerr << "Arguments missing." << endl;
        cerr << "Usage: P1 <filename>" << endl;

        // return failure, not enough arguments
        return 1;
    }

    // create text input stream connected to file named in argv[1]
    ifstream lInput(argv[1], ifstream::in);

    // operation can fail
    if (!lInput.good())
    {
        cerr << "Cannot open input file: " << argv[1] << endl;

        return 2;    // program failed (cannot open input)
    }

    Polygon lPolygon;

    lPolygon.readData(lInput);

    // close input file
    lInput.close();

    cout << "Data read:" << endl;

    for (size_t i = 0; i < lPolygon.getNumberOfVertices(); i++)
    {
        cout << "Vertex #" << i << ": " << lPolygon.getVertex(i) << endl;
    }

    runProblem1(lPolygon);
#endif

#ifdef P2
    runProblem2();
#endif

#ifdef P3
    runProblem3();
#endif

#ifdef P4
    runProblem4();
#endif
    return 0;
}