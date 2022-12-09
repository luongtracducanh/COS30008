
// COS30008, Problem Set 4, Problem 3, 2022

#pragma once

#include "BinarySearchTree.h"

#include <stack>

template<typename T>
class BinarySearchTreeIterator
{
private:
    
    using BSTree = BinarySearchTree<T>;
    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
    using BTNStack = std::stack<BTreeNode>;

    const BSTree& fBSTree;
    BTNStack fStack;
    
    void pushLeft( BTreeNode aNode )
    {
        while ( !aNode->empty() )                               // 4
        {
            fStack.push( aNode );                               // 3
            aNode = aNode->left;                                // 3(10)
        }
    }
    
public:
    
    using Iterator = BinarySearchTreeIterator<T>;
    
    BinarySearchTreeIterator( const BSTree& aBSTree ) :
        fBSTree(aBSTree)                                        // 2
    {
        pushLeft( fBSTree.fRoot );                              // 4(6)
    }

    const T& operator*() const
    {
        return fStack.top()->key;                               // (6)
    }

    Iterator& operator++()
    {
        BTreeNode lNode = fStack.top()->right;                  // 6
        
        fStack.pop();                                           // 2
        
        pushLeft( lNode );                                      // 4
        
        return *this;                                           // 2(14)
    }

    Iterator operator++(int)
    {
        Iterator old = *this;                                   // 3
        
        ++(*this);                                              // 3
        
        return old;                                             // 2(8)
    }

    bool operator==( const Iterator& aOtherIter ) const
    {
        return
            &fBSTree == &aOtherIter.fBSTree &&                  // 6
            fStack.size() == aOtherIter.fStack.size();          // 6(12)
    }

    bool operator!=( const Iterator& aOtherIter ) const
    {
        return !(*this == aOtherIter);                          // (4)
    }
    
    Iterator begin() const
    {
        Iterator iter = *this;                                  // 4
        
        iter.fStack = BTNStack();                               // 4
        iter.pushLeft( iter.fRoot );                            // 6
        
        return iter;                                            // 2(16)
    }
    
    Iterator end() const
    {
        Iterator iter = *this;                                  // 4
        
        iter.fStack = BTNStack();                               // 4
        
        return iter;                                            // 2(10)
    }
};                                                              // 10+6+6+14+8+12+4+16+10 = 86+(8)=94
