
// COS30008, Midterm, Problem 2, 2022

#include "Vigenere.h"

#include <cctype>                                                   // (2)

using namespace std;

Vigenere::Vigenere( const string& aKeyword ) :
    fKeyword( aKeyword ),                                           // 3
    fKeywordProvider( aKeyword )                                    // 3
{
	initializeTable();                                              // 2(8)
}

string Vigenere::getCurrentKeyword()
{
    string Result;                                                  // 2
    
    for ( size_t i = 0; i < fKeyword.size(); i++ )                  // 6
    {
        char lKeyCharacter = *fKeywordProvider;                     // 4
        
        Result += lKeyCharacter;                                    // 4
        fKeywordProvider << lKeyCharacter;                          // 4
    }
    
	return Result;                                                  // 2(22)
}

void Vigenere::reset()
{
    fKeywordProvider.initialize( fKeyword );                        // (6)
}

char Vigenere::encode( char aCharacter )
{
	if ( isalpha( aCharacter ) )                                    // 4
	{
		bool isLower = islower( aCharacter );                       // 4
		aCharacter = toupper( aCharacter );                         // 4

        // get indices
		char lRow = *fKeywordProvider - 'A';                        // 4
		char lColumn = aCharacter - 'A';                            // 4

        // update keyword
        fKeywordProvider << aCharacter;                             // 4

        // object encoded character
		aCharacter = fMappingTable[lRow][lColumn];                  // 4

		if ( isLower )                                              // 2
        {
			aCharacter = tolower( aCharacter );                     // 4
        }
 	}

	return aCharacter;                                              // 2/(36)
}

char Vigenere::decode( char aCharacter )
{
	if ( isalpha( aCharacter ) )                                    // 4
	{
		bool isLower = islower( aCharacter );                       // 4
		aCharacter = toupper( aCharacter );                         // 4
        
        // get indices and clear character
		char lRow = *fKeywordProvider - 'A';                        // 4

		for ( char lColumn = 0; lColumn < CHARACTERS; lColumn++ )   // 6
		{
			if ( aCharacter == fMappingTable[lRow][lColumn] )       // 6
			{
				aCharacter = 'A' + lColumn;                         // 4
				break;                                              // 2
			}
		}

        // update keyword
        fKeywordProvider << aCharacter;                             // 4

        // recover spelling
        if ( isLower )                                              // 2
        {
            aCharacter = tolower( aCharacter );                     // 4
        }
	}

	return aCharacter;                                              // 2(46)
}                                                                   // Total: 2+8+22+6+36+46 = 120
