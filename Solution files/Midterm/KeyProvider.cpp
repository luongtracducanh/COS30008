
// COS30008, Midterm, Problem 1, 2022

#include "KeyProvider.h"

#include <cctype>                                               // (2)

using namespace std;

KeyProvider::KeyProvider( const string& aKeyword ) :
    fKeyword(nullptr),                                          // 2
    fSize(0),                                                   // 2
    fIndex(0)                                                   // 2
{
    initialize( aKeyword );                                     // 4(10)
}

KeyProvider::~KeyProvider()
{
    delete [] fKeyword;                                         // (4)
}

void KeyProvider::initialize( const string& aKeyword )
{
    delete [] fKeyword;                                         // 4

    fSize = aKeyword.size();                                    // 4
    fKeyword = new char [fSize];                                // 6
    fIndex = 0;                                                 // 2

    for ( size_t i = 0; i < fSize; i++ )                        // 6
    {
        fKeyword[i] = toupper( aKeyword[i] );                   // 8(30)
    }
}

char KeyProvider::operator*() const
{
    return fKeyword[fIndex];                                    // (4)
}

KeyProvider& KeyProvider::operator<<( char aKeyCharacter )
{
    fKeyword[fIndex] = toupper( aKeyCharacter );                // 6
    fIndex++;                                                   // 2
        
    if ( fIndex == fSize )                                      // 4
    {
        fIndex = 0;                                             // 2
    }
    
    return *this;                                               // 4(18)
}                                                               // 2+10+4+30+4+18 = (68)
