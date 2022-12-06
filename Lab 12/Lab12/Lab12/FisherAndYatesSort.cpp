
// COS30008, Tutorial 12, 2022

#include "FisherAndYatesSort.h"

#include <cstdlib>
#include <ctime>
#include <iostream>

using namespace std;

void FisherAndYatesSort::shuffle()
{
    // Fisher & Yates shuffling
    size_t n = size();

    while ( n > 1 )
    {
        // new random index in the range 0 to n
        int k = rand() % n;
        n--;                    // n last pertinent index
        swap( n, k );           // algorithm library
    }
}

FisherAndYatesSort::FisherAndYatesSort( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
    SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{
    srand( (unsigned int)time( NULL ) );
}

void FisherAndYatesSort::sort( Comparable aOrderFunction )
{
    bool lIsSorted = false;
    size_t lSwaps = 0;
    
    cout << "Before sorting: " << *this <<  endl;

    do
    {
        lIsSorted = true;
        
        for ( size_t i = 1; i < size(); i++ )
        {
            if ( aOrderFunction( get( i ), get( i - 1 ) ) )
            {
                lIsSorted = false;
                break;
            }
        }

        cout << "\tStage: " << *this  << endl;

        if ( !lIsSorted )
        {
            shuffle();
            lSwaps++;
        }
    } while ( !lIsSorted );
    
    cout << "After sorting: " << *this << endl;
    cout << "Sorting required " << lSwaps << " shuffle calls." << endl;
}
