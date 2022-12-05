
// COS30008, Midterm, Problem 2, 2022

#include "Vigenere.h"

using namespace std;

void Vigenere::initializeTable()
{
	for ( char row = 0; row < CHARACTERS; row++ )
	{
		char lChar = 'B' + row;

		for ( char column = 0; column < CHARACTERS; column++ )
		{
            if ( lChar > 'Z' )
                lChar = 'A';

            fMappingTable[row][column] = lChar++;
		}
	}
}
