
// COS30008, Tutorial 7, 2022

#include "ofstream12.h"

#include <iostream>
#include <string>

using namespace std;

void write4096()
{
	cout << "Write 4096 codes" << endl;

	ofstream12 lWriter( "sample.lzw" );

	if ( !lWriter.good() )
	{
		cerr << "Error: Unable to open output file!" << endl;
		exit( 1 );
	}

	for ( size_t i = 4096; i > 0; )
	{
		lWriter << --i;
	}
}

int main()
{
	write4096();

	cout << "SUCCESS" << endl;

	return 0;
}
