#include "ofstream12.h"
void ofstream12::init()
{
	for (size_t i = 0; i < fBufferSize; i++)
		fBuffer[i] = 0;

	fByteIndex = 0;
	fBitIndex = 7;
}

void ofstream12::completeWriteBit()
{
	if (--fBitIndex < 0) {
		if (fByteIndex >= fBufferSize - 1) flush();
		else fByteIndex++;
		fBitIndex = 7;
	}
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

ofstream12::ofstream12(const char* aFileName, size_t aBufferSize) : fBufferSize(aBufferSize), fBuffer(new byte[aBufferSize])
{
	init();
	open(aFileName);
}

ofstream12::~ofstream12()
{
	flush();
	close();
	delete[] fBuffer;
}

void ofstream12::open(const char* aFileName)
{
	fOStream.open(aFileName);
}

void ofstream12::close()
{
	fOStream.close();
}

bool ofstream12::good() const
{
	return fOStream.good();
}

bool ofstream12::isOpen() const
{
	return fOStream.is_open();
}

void ofstream12::flush()
{
	for (size_t i = 0; i <= fByteIndex; i++)
		fOStream << fBuffer[i];

	init();
}

ofstream12& ofstream12::operator<<(size_t aValue)
{
	for (int i = 0; i < 12; i++) {
		if (aValue & 0x1) {
			writeBit1();
		}
		else writeBit0();
		aValue /= 2;
	}
	return *this;
}
