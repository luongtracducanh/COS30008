
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

#include "DoublyLinkedList.h"

template<typename T>
class DoublyLinkedListIterator
{
private:
	enum class States { BEFORE, DATA , AFTER };

	using Node = DoublyLinkedList<T>;

	const Node* fRoot;

    States fState;
    const Node* fCurrent;
    
public:
    
	using Iterator = DoublyLinkedListIterator<T>;

	DoublyLinkedListIterator( const Node* aRoot )
    {
        fRoot = aRoot;
        fCurrent = fRoot;
        
        if ( fCurrent != nullptr )
        {
            fState = States::DATA;
        }
        else
        {
            // empty doubly linked list of nodes
            fState = States::AFTER;
        }
    }
	
	const T& operator*() const	        // dereference
    {
        return **fCurrent;
    }
    
	Iterator& operator++()				// prefix increment
    {
        switch ( fState )
        {
            case States::BEFORE:
                
                fCurrent = fRoot;   // set to first element
                
                if ( fCurrent == nullptr )
                {
                    fState = States::AFTER;
                }
                else
                {
                    fState = States::DATA;
                }
                
                break;

            case States::DATA:

                // Is current previous of root (last element forward)?
                // Current cannot be nullptr as we are in state DATA.
                if ( fCurrent == &fRoot->getPrevious() )
                {
                    // Yes, we are done
                    fCurrent = nullptr;
                    fState = States::AFTER;
                }
                else
                {
                    // No, we can advance
                    fCurrent = &fCurrent->getNext();
                }
                
                break;
                
            default:
                
                break;
        }
        
        return *this;
    }
    
	Iterator operator++(int)			// postfix increment
    {
        Iterator temp = *this;
        
        ++(*this);
        
        return temp;
    }
    
	Iterator& operator--()				// prefix decrement
    {
        switch ( fState )
        {
            case States::AFTER:
                
                fCurrent = fRoot;
                
                if ( fCurrent == nullptr )
                {
                    fState = States::BEFORE;
                }
                else
                {
                    fCurrent = &fCurrent->getPrevious();    // set to last element
                    fState = States::DATA;
                }
                
                break;

            case States::DATA:

                // Is current root (last element backwards)?
                // Current cannot be nullptr as we are in state DATA.

                if ( fCurrent == fRoot )
                {
                    // Yes, we are done
                    fCurrent = nullptr;
                    fState = States::BEFORE;
                }
                else
                {
                    // No, we can advance
                    fCurrent = &fCurrent->getPrevious();
                }

                break;
                
            default:
                
                break;
        }
        
        return *this;
    }
    
	Iterator operator--(int)			// postfix decrement
    {
        Iterator temp = *this;
        
        --(*this);
        
        return temp;
    }

	bool operator==( const Iterator& aOtherIter ) const
    {
        return
            fRoot == aOtherIter.fRoot &&
            fCurrent == aOtherIter.fCurrent &&
            fState == aOtherIter.fState;
    }
    
	bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);
    }

    Iterator begin() const
    {
        return ++(rend());
    }
    
    Iterator end() const
    {
        Iterator iter = *this;
        
        iter.fCurrent = nullptr;
        iter.fState = States::AFTER;
        
        return iter;
    }
    
    Iterator rbegin() const
    {
        return --(end());
    }
    
    Iterator rend() const
    {
        Iterator iter = *this;
        
        iter.fCurrent = nullptr;
        iter.fState = States::BEFORE;
        
        return iter;
    }
};
