
// COS30008, Problem Set 4, Problem 1, 2022

#pragma once

#include <stdexcept>
#include <algorithm>

template<typename T>
struct BinaryTreeNode
{
    using BNode = BinaryTreeNode<T>;
    using BTreeNode = BNode*;
    
    T key;
    BTreeNode left;
    BTreeNode right;
    
    static BNode NIL;
    
    const T& findMax() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return right->empty() ? key : right->findMax();
    }

    const T& findMin() const
    {
        if ( empty() )
        {
            throw std::domain_error( "Empty tree encountered." );
        }
        
        return left->empty() ? key : left->findMin();
    }

    bool remove( const T& aKey, BTreeNode aParent )
    {
        BTreeNode x = this;
        BTreeNode y = aParent;

        while ( !x->empty() )
        {
            if ( aKey == x->key )
            {
                break;
            }

            y = x;                                      // new parent
            
            x = aKey < x->key ? x->left : x->right;
        }

        if ( x->empty() )
        {
            return false;                               // delete failed
        }
        
        if ( !x->left->empty() )
        {
            const T& lKey = x->left->findMax();         // find max to left
            x->key = lKey;
            x->left->remove( lKey, x );
        }
        else
        {
            if ( !x->right->empty() )
            {
                const T& lKey = x->right->findMin();    // find min to right
                x->key = lKey;
                x->right->remove( lKey, x );
            }
            else
            {
                if ( y != &NIL )                        // y can be NIL
                {
                    if ( y->left == x )
                    {
                        y->left = &NIL;
                    }
                    else
                    {
                        y->right = &NIL;
                    }
                }
                
                delete x;                               // free deleted node
            }
        }

        return true;
    }

    // PS4 starts here
    
    BinaryTreeNode() :
        key(T()),                                                   // 2
        left(&NIL),                                                 // 2
        right(&NIL)                                                 // 2(6)
    {}
    
    BinaryTreeNode( const T& aKey ) :
        key(aKey),                                                  // 2
        left(&NIL),                                                 // 2
        right(&NIL)                                                 // 2(6)
    {}

    BinaryTreeNode( T&& aKey ) :
        key(std::move(aKey)),                                       // 4
        left(&NIL),                                                 // 2
        right(&NIL)                                                 // 2(8)
    {}

    ~BinaryTreeNode()
    {
        if ( !left->empty() )                                       // 6
        {
            delete left;                                            // 2
        }

        if ( !right->empty() )                                      // 6
        {
            delete right;                                           // 2(16)
        }
    }
    
    bool empty() const
    {
        return this == &NIL;                                        // (4)
    }

    bool leaf() const
    {
        return left->empty() && right->empty();                     // (6)
    }

    size_t height() const
    {
        if ( empty() )                                              // 4
        {
            throw std::domain_error( "Empty tree encountered" );    // 4
        }

        if ( leaf() )                                               // 4
        {
            return 0;                                               // 2
        }
        else
        {
            size_t lHeightLeft = 0;
            size_t lHeightRight = 0;
            
            if ( !left->empty() )                                   // 4
            {
                lHeightLeft = left->height();                       // 4
            }

            if ( !right->empty() )                                  // 4
            {
                lHeightRight = right->height();                     // 4
            }

            return max( lHeightLeft, lHeightRight ) + 1;            // 8(38)
        }
    }

    bool insert( const T& aKey )
    {
        BTreeNode x = this;
        BTreeNode y = &NIL;
     
        while ( !x->empty() )
        {
            y = x;
            
            if ( aKey == x->key )
            {
                return false;         // duplicate key - error
            }

            x = aKey < x->key ? x->left : x->right;
        }

        BTreeNode z = new BNode( aKey );

        if ( y->empty() )
        {
            return false;           // insert failed (NIL)
        }
        else
        {
            if ( aKey < y->key )
            {
                y->left = z;
            }
            else
            {
                y->right = z;
            }
        }
        
        return true;                 // insert succeeded
    }                                                               // (10) - lecture slide
};                                                                  // 6+6+8+16+4+6+38+10 = 94

template<typename T>
BinaryTreeNode<T> BinaryTreeNode<T>::NIL;
