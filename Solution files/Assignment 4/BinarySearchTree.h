
// COS30008, Problem Set 4, Problem 2, 2022

#pragma once

#include "BinaryTreeNode.h"

#include <stdexcept>

// Problem 3 requirement
template<typename T>
class BinarySearchTreeIterator;

template<typename T>
class BinarySearchTree
{
private:

    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
  
    BTreeNode fRoot;
    
public:

    BinarySearchTree()
    {
        fRoot = &BNode::NIL;                                    // (4)
    }

    ~BinarySearchTree()
    {
        if ( !empty() )                                         // 4
        {
            delete fRoot;                                       // 2(6)
        }
    }

    bool empty() const
    {
        return fRoot == &BNode::NIL;                            // (6)
    }
    
    size_t height() const
    {
        // The empty tree has no height.
        if ( empty() )
        {
            throw std::domain_error( "Empty tree has no height." );
        }
        
        return fRoot->height();                                 // (4)
    }
    
    bool insert( const T& aKey )
    {
        if ( empty() )                                          // 4
        {
            fRoot = new BNode( aKey );                          // 6

            return true;                                        // 2
        }
        else
        {
            return fRoot->insert( aKey );                       // 4(16)
        }
    }

    bool remove( const T& aKey )
    {
        if ( empty() )
        {
            throw std::domain_error( "remove(): NIL encountered." );
        }
        
        if ( fRoot->leaf() )
        {
            // last node
            if ( fRoot->key == aKey )
            {
                delete fRoot;
                fRoot = &BNode::NIL;
                
                return true;
            }
            
            return false;
        }
        else
        {
            return fRoot->remove( aKey, &BNode::NIL );          // (6)
        }
    }                                                           // 4+6+6+4+16+6= 42

    // Problem 3 methods
    
    using Iterator = BinarySearchTreeIterator<T>;

    // Allow iterator to access private member variables
    friend class BinarySearchTreeIterator<T>;
    
    Iterator begin() const
    {
        return Iterator( *this );                               // (4)
    }
    
    Iterator end() const
    {
        return begin().end();                                   // (4)
    }
};                                                              // 4+4= 8
