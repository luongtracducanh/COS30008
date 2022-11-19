
// COS30008, Tutorial 7, 2022

#include "ofstream12.h"

using namespace std;

void ofstream12::init()
{
    for ( size_t i = 0; i < fBufferSize; i++ )
        fBuffer[i] = 0;

    fByteIndex = 0;
    fBitIndex = 7;
}

void ofstream12::writeBit0()
{
    completeWriteBit();
}

void ofstream12::writeBit1()
{
    fBuffer[fByteIndex] += 1 << fBitIndex;
    completeWriteBit();
}

void ofstream12::completeWriteBit()
{
    fBitIndex--;

    if ( fBitIndex < 0 )
    {
        fByteIndex++;
        fBitIndex = 7;

        if ( fByteIndex == fBufferSize )
        {
            flush();
        }
    }
}

ofstream12::ofstream12( const char* aFileName, size_t aBufferSize )
{
    // set up buffer
    fBufferSize = aBufferSize;
    fBuffer = new byte[fBufferSize];

    // clear buffer
    init();
    
    // open associated output file, if specified
    open( aFileName );
}

ofstream12::~ofstream12()
{
    close();
    
    delete [] fBuffer;
}

void ofstream12::open( const char* aFileName )
{
    if ( aFileName )
        fOStream.open( aFileName,  ofstream::binary );
}

bool ofstream12::good() const
{
    return fOStream.good();
}

bool ofstream12::isOpen() const
{
    return fOStream.is_open();
}

void ofstream12::close()
{
    flush();
    fOStream.close();
}

void ofstream12::flush()
{
    // flush pending output, last byte may be filled 50%
    fOStream.write( (char*)fBuffer, fByteIndex + (fBitIndex % 7 ? 1 : 0) );
    init();
}

ofstream12& ofstream12::operator <<( size_t aValue )
{
    for ( size_t i = 0; i < 12; i++ )	// write 12 Bits
    {
        if ( aValue & 0x01 )	        // The current lowest bit is set.
            writeBit1();
        else
            writeBit0();
        aValue >>= 1;			        // aValue := aValue / 2
    }

    return *this;                       // return updated output stream
}
