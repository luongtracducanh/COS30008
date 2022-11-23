
// Problem Set 2. 2022

#include "SortableIntVector.h"

SortableIntVector::SortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
    IntVector( aArrayOfIntegers, aNumberOfElements )                                                // (8)
{}

void SortableIntVector::sort( Comparable aOrderFunction )
{
    for ( size_t i = 0; i < size(); i++ )                                                           // 6
    {
        for ( size_t j = size() - 1; j > i; j-- )                                                   // 6
        {
            if ( aOrderFunction( get( j ), get( j - 1 ) ) )                                         // 6
            {
                swap( j, j - 1 );                                                                   // 4(22)
            }
        }
    }                                                                                               // (30)
}
