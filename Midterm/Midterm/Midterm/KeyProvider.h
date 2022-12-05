#pragma once
#include <string>
class KeyProvider
{
private:
	char* fKeyword; // keyword
	size_t fSize; // length of keyword
	size_t fIndex; // index to current keyword character

public:

	// Initialize key provider. [10]
	// aKeyword is a string of letters.
	KeyProvider(const std::string& aKeyword);
	// Destructor, release resources. [4]
	~KeyProvider();
	// Initialize (or reset) keyword [30]
	void initialize(const std::string& aKeyword);

	// Dereference, returns current keyword character. [4]
	char operator*() const;

	// Push new keyword character. [18]
	// aKeyCharacter is a letter (isalpha() is true).
	// aKeyCharacter replaces current keyword character.
	// Key provider advances to next keyword character.
	KeyProvider& operator<<(char aKeyCharacter);
};