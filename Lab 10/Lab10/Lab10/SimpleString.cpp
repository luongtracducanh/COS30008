
// COS30008, Tutorial 10, 2022

#include "Tests.h"

#include "SimpleString.h"

#include <cstring>
#include <algorithm>

using namespace std;

SimpleString::SimpleString()
{
	fCharacters = new char[1];
	*fCharacters = '\0';
}

SimpleString::~SimpleString()
{
	delete [] fCharacters;
}

SimpleString& SimpleString::operator+( const char aCharacter )
{
    char *temp = new char[strlen(fCharacters) + 2];
    unsigned int i = 0;
    
    for ( ; i < strlen( fCharacters ); i++ )
        temp[i] = fCharacters[i];
    
    temp[i++] = aCharacter;
    temp[i] = '\0';
    
    delete [] fCharacters;
    fCharacters = temp;
    return *this;
}

const char* SimpleString::operator*() const
{ 
    return fCharacters;
}

#if TEST >= 1

SimpleString::SimpleString( const SimpleString& aOtherString )
{
	unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
  	fCharacters = new char[lLength];
  
  	for ( unsigned int i = 0; i < lLength; i++ )
    	fCharacters[i] = aOtherString.fCharacters[i];
}

#endif

#if TEST >= 3

SimpleString& SimpleString::operator=( const SimpleString& aOtherString )
{
    if ( &aOtherString != this )
	{
		delete [] fCharacters;
	
		unsigned long lLength = strlen(aOtherString.fCharacters) + 1;
  		fCharacters = new char[lLength];
  
  		for ( unsigned int i = 0; i < lLength; i++ )
    		fCharacters[i] = aOtherString.fCharacters[i];
	}

	return *this;
}

#endif

#if TEST >= 4

SimpleString::SimpleString( SimpleString&& aOtherString )
{
    // simple swap move idiom

    fCharacters = new char[1];
    *fCharacters = '\0';

    swap( fCharacters, aOtherString.fCharacters );
}

SimpleString& SimpleString::operator=( SimpleString&& aOtherString )
{
    if ( &aOtherString != this )
    {
        // delete this contents
        this->~SimpleString();

        fCharacters = new char[1];
        *fCharacters = '\0';

        // copy contents

        swap( fCharacters, aOtherString.fCharacters );
    }

    return *this;
}

#endif

#if TEST >= 5

SimpleString* SimpleString::clone()
{
	return new SimpleString( *this );
}

#endif
