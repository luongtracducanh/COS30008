
// COS30008, Tutorial 12, 2022

#include <iostream>

using namespace std;

//#define P1
//#define P2
//#define P3

#ifdef P1

#include "IntVector.h"

void runP1()
{
    cout << "Test output operator:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    IntVector lVector( lArray, lArrayLength );
            
    cout << "Vector: " << lVector << endl;
}

#endif

#ifdef P2

#include "BubbleSort.h"

void runP2()
{
    cout << "Test bubble sort:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    BubbleSort lIntSorter( lArray, lArrayLength );
  
    lIntSorter.sort( [](int aLeft, int aRight ) { return aLeft <= aRight; }  );
}

#endif

#ifdef P3

#include "FisherAndYatesSort.h"

void runP3()
{
    cout << "Test Fisher&Yates sort:" << endl;

    int lArray[] = { 34, 65, 890, 86, 16, 218, 20, 49, 2, 29 };
    size_t lArrayLength = sizeof(lArray) / sizeof(int);

    FisherAndYatesSort lIntSorter( lArray, lArrayLength );
    
    lIntSorter.sort( [](int aLeft, int aRight ) { return aLeft <= aRight; }  );
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

    return 0;
}
