#include "iVigenereStream.h"

iVigenereStream::iVigenereStream(Cipher aCipher, const std::string& aKeyword, const char* aFileName): fIStream(std::ifstream()), fCipherProvider(Vigenere(aKeyword)), fCipher(std::move(aCipher))
{
	if (aFileName != nullptr)
	{
		open(aFileName);
	}
}

iVigenereStream::~iVigenereStream()
{
	close();
}

void iVigenereStream::open(const char* aFileName)
{
	fIStream.open(aFileName, std::ios::binary);
}

void iVigenereStream::close()
{
	fIStream.close();
}

void iVigenereStream::reset()
{
	fCipherProvider.reset();
	seekstart();
}

bool iVigenereStream::good() const
{
	return fIStream.good();
}

bool iVigenereStream::is_open() const
{
	return fIStream.is_open();
}

bool iVigenereStream::eof() const
{
	return fIStream.eof();
}

iVigenereStream& iVigenereStream::operator>>(char& aCharacter)
{
	aCharacter = fCipher(fCipherProvider, static_cast<char>(fIStream.get()));
	return *this;
}