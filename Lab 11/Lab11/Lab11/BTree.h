
// COS30008, Tutorial 11, 2022

#pragma once

#include <stdexcept>
#include <algorithm>

template<typename T>
class BTree
{
private:
    T fKey;                                         // T() for empty BTree
    BTree<T>* fLeft;
    BTree<T>* fRight;
    
    BTree() :                                       // sentinel constructor
        fKey(T()),
        fLeft(&NIL),
        fRight(&NIL)
    {}
    
    void attach( BTree<T>** aNode, const BTree<T>& aBTree )
    {
        if ( (*aNode)->empty() )
        {
            *aNode = const_cast<BTree<T>*>(&aBTree);
        }
        else
        {
            throw std::domain_error( "Illegal subtree operation." );
        }
    }
    
    const BTree<T>& detach( BTree<T>** aNode )
    {
        if ( !(*aNode)->empty() )
        {
            BTree<T>* Result = *aNode;              // obtain reference to subtree
            *aNode= &NIL;                           // set to NIL
            return *Result;                         // return subtree (reference)
        }
        else
        {
            throw std::domain_error( "Illegal subtree operation." );
        }
    }

public:
    static BTree<T> NIL;                            // Empty BTree
    
    BTree( const T& aKey ) :                        // BTree leaf
        fKey(aKey),
        fLeft(&NIL),
        fRight(&NIL)
    {}
    
    BTree( T&& aKey ) :                             // BTree leaf
        fKey(std::move(aKey)),
        fLeft(&NIL),
        fRight(&NIL)
    {}

    BTree( const BTree& aOtherBTree ) :             // copy constructor
        BTree()
    {
        *this = aOtherBTree;                        // use copy assignment
    }

    BTree( BTree&& aOtherBTree ) :                  // move constructor
        BTree()
    {
        *this = std::move(aOtherBTree);             // use move assignment
    }
    
    virtual ~BTree()                                // destructor
    {
        if ( !left().empty() )
        {
            delete fLeft;
        }

        if ( !right().empty() )
        {
            delete fRight;
        }
    }
    
    BTree& operator=( const BTree& aOtherBTree )    // copy assignment operator
    {
        if ( !aOtherBTree.empty() )
        {
            if ( this != &aOtherBTree )
            {
                fKey = aOtherBTree.fKey;

                fLeft = aOtherBTree.left().clone();
                fRight = aOtherBTree.right().clone();
            }
            
            return *this;
        }
        else
        {
            throw std::domain_error( "Illegal binary tree operation." );
        }
    }
    
    BTree& operator=( BTree&& aOtherBTree )         // move assignment operator
    {
        if ( !aOtherBTree.empty() )
        {
            if ( this != &aOtherBTree )
            {
                this->~BTree();
                
                fKey = std::move(aOtherBTree.fKey);
                
                fLeft = const_cast<BTree<T>*>(&aOtherBTree.detachLeft());
                fRight = const_cast<BTree<T>*>(&aOtherBTree.detachRight());
            }
            
            return *this;
        }
        else
        {
            throw std::domain_error( "Illegal binary tree operation." );
        }
    }

#ifdef HasCopySemantics

    virtual BTree* clone() const                    // clone a tree
    {
        if ( !empty() )
        {
            return new BTree( *this );              // return new object
        }
        else
        {
            // remove constness
            return const_cast<BTree<T>*>(this);     // no clone
        }
    }
    
#endif
    
    bool empty() const                              // is tree empty
    {
        return this == &NIL;
    }
    
    const T& operator*() const                      // get key (node value)
    {
        return fKey;
    }
    
    const BTree& left() const
    {
        return *fLeft;
    }
    
    const BTree& right() const
    {
        return *fRight;
    }
    
    // tree manipulators
    void attachLeft( const BTree<T>& aBTree )
    {
        attach( &fLeft, aBTree );
    }

    void attachRight( const BTree<T>& aBTree )
    {
        attach( &fRight, aBTree );
    }
    
    const BTree& detachLeft()
    {
        return detach( &fLeft );
    }

    const BTree& detachRight()
    {
        return detach( &fRight );
    }
};

template<class T>
BTree<T> BTree<T>::NIL;
