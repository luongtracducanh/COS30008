#pragma once
#include "KeyProvider.h"
#define CHARACTERS 26
class Vigenere
{
private:
	char fMappingTable[CHARACTERS][CHARACTERS];
	const std::string fKeyword;
	KeyProvider fKeywordProvider;
	// Initialize the mapping table
	// Row 1: B - A
	// Row 26: A - Z
	void initializeTable();

public:
	// Initialize Vigenere scrambler [8]
	Vigenere(const std::string& aKeyword);
	// Return the current keyword. [22]
	// This method scans the keyword provider and copies the keyword characters
	// into a result string.
	std::string getCurrentKeyword();
	// Reset Vigenere scrambler. [6]
	// This method has to initialize the keyword provider.
	void reset();
	// Encode a character using the current keyword character and update keyword. [36]
	char encode(char aCharacter);
	// Decode a character using the current keyword character and update keyword. [46]
	char decode(char aCharacter);
};