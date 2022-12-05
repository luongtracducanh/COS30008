
// Problem Set 2, 2022

#include "IntVector.h"

#include <stdexcept>                                                    // (4)

using namespace std;

IntVector::IntVector( const int aArrayOfIntegers[], size_t aNumberOfElements )
{
    fNumberOfElements = aNumberOfElements;
    fElements = new int[fNumberOfElements];
    
    for ( size_t i = 0; i < fNumberOfElements; i++ )
    {
        fElements[i] = aArrayOfIntegers[i];
    }
}

IntVector::~IntVector()
{
    delete [] fElements;                                                // (4)
}

size_t IntVector::size() const
{
    return fNumberOfElements;                                           // (2)
}

const int IntVector::get( size_t aIndex ) const
{
    return (*this)[aIndex];                                             // (6)
}

void IntVector::swap( size_t aSourceIndex, size_t aTargetIndex )
{
    if ( aSourceIndex < fNumberOfElements &&
         aTargetIndex < fNumberOfElements )                             // 8
    {
        // classical swap
        int lTemp = fElements[aSourceIndex];                            // 4
        
        fElements[aSourceIndex] = fElements[aTargetIndex];              // 4
        fElements[aTargetIndex] = lTemp;                                // 4
    }
    else
    {
        throw out_of_range( "Illegal vector indices" );                 // 2(22)
    }
}

const int IntVector::operator[]( size_t aIndex ) const
{
    if ( aIndex < fNumberOfElements )                                   // 4
    {
        return fElements[aIndex];                                       // 4
    }
 
    throw out_of_range( "Illegal vector index" );                       // 2(10)
}
                                                    // 4+4+2+6+22+10=(48)
