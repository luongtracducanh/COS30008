
// COS30008, Tutorial 12, 2022

#include "BubbleSort.h"

#include <iostream>

using namespace std;

BubbleSort::BubbleSort( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
    SortableIntVector(aArrayOfIntegers, aNumberOfElements)
{}

void BubbleSort::sort( Comparable aOrderFunction )
{
    size_t lSwaps = 0;

    cout << "Before sorting: " << *this <<  endl;

    for ( size_t i = 0; i < size() ; i++ )
    {
        for ( size_t j = size() - 1; j > i; j-- )
        {
            if ( aOrderFunction( get( j ), get( j - 1 ) ) )
            {
                swap( j, j - 1 );
                lSwaps++;
            }
        }
        
        cout << "\tStage i = " << i << ": " << *this << endl;
    }
    
    
    cout << "After sorting: " << *this << endl;
    cout << "Sorting required " << lSwaps << " exchanges." << endl;
}
