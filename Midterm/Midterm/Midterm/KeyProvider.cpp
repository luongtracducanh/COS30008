#include "KeyProvider.h"

KeyProvider::KeyProvider(const std::string& aKeyword): fKeyword(new char[aKeyword.length()]), fSize(aKeyword.length()), fIndex(0)
{
	initialize(aKeyword);
}

KeyProvider::~KeyProvider()
{
	delete[] fKeyword;
}

void KeyProvider::initialize(const std::string& aKeyword)
{
	delete[] fKeyword;
	fSize = aKeyword.length();
	fKeyword = new char[fSize];
	for (size_t i = 0; i < fSize; i++)
	{
		fKeyword[i] = static_cast<char>(toupper(aKeyword[i]));
	}
	fIndex = 0;
}

char KeyProvider::operator*() const
{
	return fKeyword[fIndex];
}

KeyProvider& KeyProvider::operator<<(char aKeyCharacter)
{
	fKeyword[fIndex] = static_cast<char>(toupper(aKeyCharacter));
	if (++fIndex >= fSize)
	{
		fIndex = 0;
	}
	return *this;
}