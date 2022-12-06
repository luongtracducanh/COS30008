
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
    
    BTree();                                        // sentinel constructor

    // tree manipulator auxiliaries
    void attach( BTree<T>** aNode, const BTree<T>& aBTree );
    const BTree<T>& aBTree detach( BTree<T>** aNode );

public:
    static BTree<T> NIL;                          	// Empty BTree
    
    BTree( const T& aKey );                         // BTree leaf
    BTree( T&& aKey );                              // BTree leaf

    BTree( const BTree& aOtherBTree );              // copy constructor
    BTree( BTree&& aOtherBTree );                   // move constructor
    
    virtual ~BTree();                               // destructor
    
    BTree& operator=( const BTree& aOtherBTree );   // copy assignment operator
    BTree& operator=( BTree&& aOtherBTree );        // move assignment operator
    
# ifdef HasCopySemantics
    virtual BTree* clone() const;                   // clone a tree
#endif
    
    bool empty() const;                             // is tree empty
    const T& operator*() const;                     // get key (node value)
    
    const BTree& left() const;
    const BTree& right() const;
    
    // tree manipulators
    void attachLeft( const BTree<T>& aBTree );
    void attachRight( const BTree<T>& aBTree );
    const BTree& detachLeft();
    const BTree& detachRight();
};

template<class T>
BTree<T> BTree<T>::NIL;
