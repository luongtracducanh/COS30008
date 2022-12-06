
// COS30008, Problem Set 2 & Tutorial 12, 2022

#include "IntVector.h"

#include <stdexcept>
#include <algorithm>

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
    delete [] fElements;
}

size_t IntVector::size() const
{
    return fNumberOfElements;
}

const int IntVector::get( size_t aIndex ) const
{
    return (*this)[aIndex];
}

void IntVector::swap( size_t aSourceIndex, size_t aTargetIndex )
{
    if ( aSourceIndex < fNumberOfElements &&
         aTargetIndex < fNumberOfElements )
    {
        // std::swap, tutorial 12
        std::swap( fElements[aSourceIndex], fElements[aTargetIndex] );
    }
    else
    {
        throw out_of_range( "Illegal vector indices" );
    }
}

const int IntVector::operator[]( size_t aIndex ) const
{
    if ( aIndex < fNumberOfElements )
    {
        return fElements[aIndex];
    }
 
    throw out_of_range( "Illegal vector index" );
}
