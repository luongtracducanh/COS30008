
// COS30008, List, Problem Set 3, 2022

#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

#include <stdexcept>

template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot;	// the first element in the list
	size_t fCount;	// number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
    using Iterator = DoublyLinkedListIterator<T>;

	~List()                                                             // destructor - frees all nodes
    {
        while ( fRoot != nullptr )
        {
            if ( fRoot != &fRoot->getPrevious() )                       // more than one element
            {
                Node* lTemp = const_cast<Node*>(&fRoot->getPrevious()); // select last
                
                lTemp->isolate();                                       // remove from list
                delete lTemp;                                           // free
            }
            else
            {
                delete fRoot;                                           // free last
                break;                                                  // stop loop
            }
        }
    }

    void remove( const T& aElement )	                                // remove first match from list
    {
        Node* lNode = fRoot;                                            // start at first
        
        while ( lNode != nullptr )                                      // Are there still nodes available?
        {
            if ( **lNode == aElement )                                  // Have we found the node?
            {
                break;                                                  // stop the search
            }

            if ( lNode != &fRoot->getPrevious() )                       // not reached last
            {
                lNode = const_cast<Node*>(&lNode->getNext());           // go to next
            }
            else
            {
                lNode = nullptr;                                        // stop search
            }
        }
        
        // At this point we have either reached the end or found the node.
        if ( lNode != nullptr )                                         // We have found the node.
        {
            if ( fCount != 1 )                                          // not the last element
            {
                if ( lNode == fRoot )
                {
                    fRoot = const_cast<Node*>(&fRoot->getNext());       // make next root
                }
            }
            else
            {
                fRoot = nullptr;                                        // list becomes empty
            }
            
            lNode->isolate();                                           // isolate node
            delete lNode;                                               // release node's memory
            fCount--;                                                   // decrement count
        }
    }

	//////////////////////////////////////////////////////////////////
    //// PS3
    //////////////////////////////////////////////////////////////////
    
	// P1

    List() :                                         					        // default constructor
        fRoot(nullptr),                                                         // 2
        fCount(0)                                                               // 2(4)
    {}

	bool empty() const	                                                        // Is list empty?
	{
    	return fRoot == nullptr;										        // (4)
	}

	size_t size() const                		                                    // list size
	{
    	return fCount;													        // (2)
	}

	void push_front( const T& aElement )	                                    // adds aElement at front
	{
    	Node* lNewElement = new Node( aElement );                               // 6

    	if ( fRoot == nullptr )                                                 // 4
    	{
        	fRoot = lNewElement;										        // 2
    	}
    	else
    	{
        	fRoot->push_front( *lNewElement );                                  // 6
        	fRoot = lNewElement;										        // 2
    	}

    	fCount++;                                                               // 2(22)
	}

    Iterator begin() const                                                      // return a forward iterator
    {
        return Iterator( fRoot );										        // (4)
    }

    Iterator end() const                                                        // return a forward end iterator
    {
        return begin().end();											        // (4)
    }

    Iterator rbegin() const                                                     // return a backwards iterator
    {
        return begin().rbegin();										        // (4)
    }

    Iterator rend() const                                                       // return a backwards end iterator
    {
        return begin().rend();											        // (4)
    }
                                                                                // P1 = 4+4+2+22+4+4+4+4=(48)

	// P2
	
	void push_back( const T& aElement )                                         // adds aElement at back
    {
        Node* lNewElement = new Node( aElement );                               // 6

        if ( fRoot == nullptr )                                                 // 4
        {
            fRoot = lNewElement;										        // 2
        }
        else
        {
            fRoot->push_front( *lNewElement );                                  // 14
        }

        fCount++;                                                               // 2(28)
    }

	// P3

    const T& operator[]( size_t aIndex ) const	                                // list indexer
    {
        if ( aIndex < fCount )                                                  // 4
        {
            const Node* lNode = fRoot;                                          // 6
            while ( aIndex )                                                    // 2
            {
                // No
                aIndex--;                                                       // 2
                lNode = &lNode->getNext();                                      // 4
            }
            // Yes
            return **lNode;                                                     // 4
        }
        else
        {
            throw std::out_of_range( "Index out of bounds." );                   // 4(26)
        }
    }

	// P4
	
    List( const List& aOtherList ) :                                            // copy constructor
        fRoot(nullptr),                                                         // 2
        fCount(0)                                                               // 2
    {
        *this = aOtherList;                                                     // 8(12)
    }

    List& operator=( const List& aOtherList )                                   // assignment operator
    {
        if ( this != &aOtherList )                                              // 4
        {
            // delete
            this->~List();                                                      // 4

            fRoot = nullptr;                                                    // 2
            fCount = 0;                                                         // 2
            
            // copy
            for ( const auto& e : aOtherList )
            {
                push_back( e );
            }                                                                   // 4
        }
            
        return *this;                                                           // 2(18)
     }																	        // P4 = 12+18 = (30)
    
	// P5

	// move features
    
    List( List&& aOtherList ) :                                                 // move constructor
        fRoot(nullptr),                                                         // 2
        fCount(0)                                                               // 2
    {
        *this = std::move(aOtherList) ;                                         // 6(10)
    }
    
    List& operator=( List&& aOtherList )                                        // move assignment operator
    {
        if ( this != &aOtherList )                                              // 4
        {
            // delete
            this->~List();                                                      // 6

            // move (steal memory)
            fRoot = aOtherList.fRoot;                                           // 3
            fCount = aOtherList.fCount;                                         // 3
            aOtherList.fRoot = nullptr;                                         // 2
            aOtherList.fCount = 0;                                              // 2
        }

        return *this;                                                           // 2(22)
    }

    void push_front( T&& aElement )
    {
        Node* lNewElement = new Node( std::move(aElement) );                    // (5)

        if ( fRoot == nullptr )
        {
            fRoot = lNewElement;
        }
        else
        {
            fRoot->push_front( *lNewElement );
            fRoot = lNewElement;
        }

        fCount++;
    }
    
    void push_back( T&& aElement )
    {
        Node* lNewElement = new Node( std::move(aElement) );                    // (5)

        if ( fRoot == nullptr )
        {
            fRoot = lNewElement;
        }
        else
        {
            fRoot->push_front( *lNewElement );
        }

        fCount++;
    }
                                                                                // P5 = 10+22+5+5 = (42)
};

