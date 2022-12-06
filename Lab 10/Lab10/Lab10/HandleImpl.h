
// COS30008, Tutorial 10, 2022

#pragma once

#include <stdexcept>

#include <iostream>

template<class T>
class Handle
{
private:
	T* fPointer;
 	size_t* fCount;

	void addRef()
	{
		++*fCount;

        // debug message
        std::cout << "Add reference for " << std::hex << fPointer << ": " << *fCount << std::endl;
	}
	
	void releaseRef()
	{
        // small variation to lecture slides
        // debug message
        --*fCount;
        std::cout << "Release reference for " << std::hex << fPointer << ": " << *fCount << std::endl;

        if ( *fCount == 0 )
		{
            // debug message
            std::cout << "Destroy handle for " << std::hex << fPointer << ": " << *fCount << std::endl;
            
			delete fPointer;
			delete fCount;
		}
	}

public:
	
	Handle( T* aPointer = nullptr )
	{
		fPointer = aPointer;
		fCount = new size_t;
        // small variation to lecture slides
		*fCount = 0;
        addRef();
	}
	
	~Handle()
	{
		releaseRef();
	}

	Handle( const Handle<T>& aOtherHandle )
	{
	  fPointer = aOtherHandle.fPointer;
	  fCount = aOtherHandle.fCount;
	  addRef(); 						    // increment use
	}

	Handle& operator=( Handle<T>& aOtherHandle )
	{
		if ( &aOtherHandle != this )
		{ 
			aOtherHandle.addRef(); 		 	// increment use
	  		releaseRef();             		// release old handle
			fPointer = aOtherHandle.fPointer;
	 		fCount = aOtherHandle.fCount;
		}

		return *this;
	}

	T& operator*()
	{
	  if ( fPointer )
	    return *fPointer;
	  else
	    throw std::runtime_error( "Dereference of unbound handle!" );
	}

	T* operator->()
	{
	  if ( fPointer )
	    return fPointer;
	  else
	    throw std::runtime_error( "Access through unbound handle!" );
	}

};
