
// COS30008, Midterm, Problem 3, 2022

#include "iVigenereStream.h"

using namespace std;

iVigenereStream::iVigenereStream( Cipher aCipher,
                                  const std::string& aKeyword,
                                  const char* aFileName ) :
	fCipherProvider( aKeyword ),                                        // 3
	fCipher(aCipher)                                                    // 3
{
	open( aFileName );                                                  // 2(8)
}

iVigenereStream::~iVigenereStream()
{
	fIStream.close();                                                   // (2)
}

void iVigenereStream::open( const char* aFileName )
{
	if ( aFileName )                                                    // 3
		fIStream.open( aFileName, ifstream::binary );                   // 5(8)
}

void iVigenereStream::close()
{
	fIStream.close();                                                   // (2)
}

void iVigenereStream::reset()
{
	fCipherProvider.reset();                                            // 4

	if ( is_open() )                                                    // 4
	{
		seekstart();                                                    // 2(10)
	}
}

bool iVigenereStream::good() const
{
	return fIStream.good();                                             // (3)
}

bool iVigenereStream::is_open() const
{
	return fIStream.is_open();                                          // (3)
}

bool iVigenereStream::eof() const
{
	return fIStream.eof();                                              // (3)
}

iVigenereStream& iVigenereStream::operator>>( char& aCharacter )
{
	char lCharacter = 0;                                                // 3

	if ( fIStream.get( lCharacter ) )                                   // 5
	{
		aCharacter = fCipher( fCipherProvider, lCharacter );            // 6
	}

	return *this;                                                       // 3(17)
}                                                                       // 8+2+8+2+10+3+3+3+17 = (56)
