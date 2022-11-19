#pragma once

#include "SimpleString.h"
#include <cstring>
#include <algorithm>

SimpleString::SimpleString()
{
	fCharacters = new char[1];
	*fCharacters = '\0';
}

SimpleString::~SimpleString()
{
	delete fCharacters;
}

SimpleString& SimpleString::operator+(const char aCharacter)
{
	char *Temp = new char[strlen(fCharacters) + 2];
	unsigned int i;

	for (i = 0; i < strlen(fCharacters); i++)
	{
		Temp[i] = fCharacters[i];
	}
	Temp[i++] = fCharacters[i];
	Temp[i] = '\0';

	delete fCharacters;
	fCharacters = Temp;
	return *this;
}

const char* SimpleString::operator*() const
{
	return fCharacters;
}
