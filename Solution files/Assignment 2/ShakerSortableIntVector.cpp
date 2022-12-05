
// Problem Set 2. 2022

#include "ShakerSortableIntVector.h"

ShakerSortableIntVector::ShakerSortableIntVector( const int aArrayOfIntegers[], size_t aNumberOfElements ) :
    SortableIntVector( aArrayOfIntegers, aNumberOfElements )                    // (10)
{}

void ShakerSortableIntVector::sort( Comparable aOrderFunction )
{
    size_t lBeginIndex = 0;                                                     // 2
    size_t lEndIndex = size() - 1;                                              // 4
        
        while ( lBeginIndex < lEndIndex )                                       // 4
        {
            for ( size_t i = lBeginIndex; i < lEndIndex; i++ )                  // 6
            {
                if ( aOrderFunction( get( i ), get( i + 1 ) ) )                 // 6
                {
                    swap( i, i + 1 );                                           // 4
                }
            }
            
            lEndIndex--;                                                        // 2

            for ( size_t i = lEndIndex; i > lBeginIndex; i-- )                  // 6
            {
                if ( aOrderFunction( get( i - 1 ), get( i ) ) )                 // 8
                {
                    swap( i - 1, i );                                           // 4
                }
            }
            
            lBeginIndex++;                                                      // 2
        }                                                                       // (48)
}                                                                               // 10+48=(58)
