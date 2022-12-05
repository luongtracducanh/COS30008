
// COS30008, Tutorial 5, 2022

#ifdef _MSC_VER
// VS 2019 does not implement exception specification
#pragma warning( disable : 4290 )   
#endif

#include <iostream>

#define P1
#define P2
#define P3
#define P4

#include "DataWrapper.h"

using namespace std;

int main( int argc, char* argv[] )
{
    if ( argc != 2 )
    {
        cerr << "Arguments missing." << endl;
        cerr << "Usage: DataWrapper <filename>" << endl;
        
        return 1;
    }
        
#ifdef P1

    DataWrapper lData;
    
    if ( !lData.load( argv[1] ) )
    {
        cerr << "Cannot load data file " << argv[1] << endl;
        
        return 2;
    }
    
    cout << "Data loaded." << endl;

#endif
    
#ifdef P2
    
    cout << "Using basic indexer: " << endl;
    
    for ( size_t i = 0; i < lData.size(); i++ )
    {
        cout << lData[i].getAsChar();
    }

    cout << endl;

#endif

#ifdef P3
    
    cout << "Using lambda with identity mapping logic: " << endl;

    auto lIdentityMapper = [&lData] (size_t aIndex) throw(out_of_range) -> const char
    {
        if ( aIndex < lData.size() )
        {
            return lData[aIndex].getAsChar();
        }

        throw out_of_range( "Invalid index." );
    };
    
    for ( size_t i = 0; i < lData.size(); i++ )
    {
        cout << lData.get( i, lIdentityMapper );
    }

    cout << endl;

#endif

#ifdef P4
    
    cout << "Using lambda with ordered mapping logic: " << endl;

    auto lOrderedMapper = [&lData] (size_t aIndex) throw(out_of_range) -> const char
    {
        if ( aIndex < lData.size() )
        {
            for ( size_t i = 0; i < lData.size(); i++ )
            {
                if ( lData[i].fIndex == aIndex )
                {
                    return lData[i].getAsChar();
                }
            }
        }

        throw out_of_range( "Invalid index." );
    };
    
    for ( size_t i = 0; i < lData.size(); i++ )
    {
        cout << lData.get( i, lOrderedMapper );
    }

    cout << endl;

#endif
    
    return 0;
}
