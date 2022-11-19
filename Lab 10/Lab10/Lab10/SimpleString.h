
// COS30008, Tutorial 10, 2022

#pragma once

#include "Tests.h"

class SimpleString
{
private:
	char* fCharacters;

public:
	SimpleString();
	virtual ~SimpleString();

#if TEST >= 1
    
	SimpleString( const SimpleString& aOtherString );

#endif

#if TEST >= 3

    SimpleString& operator=( const SimpleString& aOtherString );

#endif

#if TEST >= 4

    SimpleString( SimpleString&& aOtherString );
    SimpleString& operator=( SimpleString&& aOtherString );

#endif
    
#if TEST >= 6

	virtual SimpleString* clone();

#endif
	
	SimpleString& operator+( const char aCharacter );
	const char* operator*() const;
};
