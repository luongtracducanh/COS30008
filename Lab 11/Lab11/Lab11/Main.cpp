
// COS30008, Tutorial 11, 2022

#include <iostream>
#include <string>

using namespace std;

//#define P1
//#define P2
//#define P3


#ifdef P1

#include "BTree.h"

void testBasicOperations()
{
    cout << "Test basic semantics." << endl;
    
    using StringBTree = BTree<string>;

    string s1( "A" );
    string s2( "B" );
    string s3( "AA" );

    StringBTree root( "Hello World!" );
    StringBTree nodeA( s1 );
    StringBTree nodeB( s2 );
    StringBTree nodeAA( s3 );
    StringBTree nodeBB( "BB" );

    root.attachLeft( nodeA );
    root.attachRight( nodeB );
    const_cast<StringBTree&>(root.left()).attachLeft( nodeAA );
    const_cast<StringBTree&>(root.right()).attachRight( nodeBB );

    cout << "root:       " << *root << endl;
    cout << "root->L:    " << *root.left() << endl;
    cout << "root->R:    " << *root.right() << endl;
    cout << "root->L->L: " << *root.left().left() << endl;
    cout << "root->R->R: " << *root.right().right() << endl;
    
    const_cast<StringBTree&>(root.right()).detachRight();
    const_cast<StringBTree&>(root.left()).detachLeft();
    root.detachRight();
    root.detachLeft();

    cout << "All trees are going to be deleted now!" << endl;
}

#endif

#ifdef P2

#define HasCopySemantics

#include "BTree.h"

void testCopyControl()
{
    cout << "Test copy semantics." << endl;

    using StringBTree = BTree<string>;

    string s1( "A" );
    string s2( "B" );
    string s3( "AA" );

    StringBTree root( "Hello World!" );
    StringBTree nodeA( s1 );
    StringBTree nodeB( s2 );
    StringBTree nodeAA( s3 );
    StringBTree nodeBB( "BB" );

    root.attachLeft( *(new StringBTree( nodeA )) );
    root.attachRight( *(new StringBTree( nodeB )) );
    const_cast<StringBTree&>(root.left()).attachLeft( *(new StringBTree( nodeAA )) );
    const_cast<StringBTree&>(root.right()).attachRight( *(new StringBTree( nodeBB )) );

    cout << "root:       " << *root << endl;
    cout << "root->L:    " << *root.left() << endl;
    cout << "root->R:    " << *root.right() << endl;
    cout << "root->L->L: " << *root.left().left() << endl;
    cout << "root->R->R: " << *root.right().right() << endl;
    
    try
    {
        StringBTree nil_copy = StringBTree::NIL;
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }

    StringBTree copy = root;
    
    cout << "copy:       " << *copy << endl;
    cout << "copy->L:    " << *copy.left() << endl;
    cout << "copy->R:    " << *copy.right() << endl;
    cout << "copy->L->L: " << *copy.left().left() << endl;
    cout << "copy->R->R: " << *copy.right().right() << endl;

    try
    {
        StringBTree nil_copy( "Empty" );

        nil_copy = StringBTree::NIL;
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }

    StringBTree root1( "Empty" );

    root1 = copy;

    cout << "root1:       " << *root1 << endl;
    cout << "root1->L:    " << *root1.left() << endl;
    cout << "root1->R:    " << *root1.right() << endl;
    cout << "root1->L->L: " << *root1.left().left() << endl;
    cout << "root1->R->R: " << *root1.right().right() << endl;
    
    StringBTree* clone = root1.clone();
    
    cout << "clone:       " << **clone << endl;
    cout << "clone->L:    " << *clone->left() << endl;
    cout << "clone->R:    " << *clone->right() << endl;
    cout << "clone->L->L: " << *clone->left().left() << endl;
    cout << "clone->R->R: " << *clone->right().right() << endl;
    
    cout << "All trees are going to be deleted now!" << endl;
    
    delete clone;
}


#endif

#ifdef P3

#define HasCopySemantics

#include "BTree.h"

void testMoveControl()
{
    cout << "Test move semantics." << endl;

    using StringBTree = BTree<string>;

    string s1( "A" );
    string s2( "B" );
    string s3( "AA" );

    StringBTree root( "Hello World!" );
    StringBTree nodeA( s1 );
    StringBTree nodeB( s2 );
    StringBTree nodeAA( s3 );
    StringBTree nodeBB( "BB" );

    root.attachLeft( *(new StringBTree( nodeA )) );
    root.attachRight( *(new StringBTree( nodeB )) );
    const_cast<StringBTree&>(root.left()).attachLeft( *(new StringBTree( nodeAA )) );
    const_cast<StringBTree&>(root.right()).attachRight( *(new StringBTree( nodeBB )) );

    cout << "root:       " << *root << endl;
    cout << "root->L:    " << *root.left() << endl;
    cout << "root->R:    " << *root.right() << endl;
    cout << "root->L->L: " << *root.left().left() << endl;
    cout << "root->R->R: " << *root.right().right() << endl;

    try
    {
        StringBTree nil_copy = std::move(StringBTree::NIL);
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }

    StringBTree copy = std::move(root);
    
    cout << "root:       " << *root << endl;
    cout << "copy:       " << *copy << endl;
    cout << "copy->L:    " << *copy.left() << endl;
    cout << "copy->R:    " << *copy.right() << endl;
    cout << "copy->L->L: " << *copy.left().left() << endl;
    cout << "copy->R->R: " << *copy.right().right() << endl;

    try
    {
        StringBTree nil_copy( "Empty" );

        nil_copy = StringBTree::NIL;
    }
    catch (domain_error e)
    {
        cout << e.what() << endl;
    }

    StringBTree root1( "Empty" );

    root1 = std::move(copy);

    cout << "copy:        " << *copy << endl;
    cout << "root1:       " << *root1 << endl;
    cout << "root1->L:    " << *root1.left() << endl;
    cout << "root1->R:    " << *root1.right() << endl;
    cout << "root1->L->L: " << *root1.left().left() << endl;
    cout << "root1->R->R: " << *root1.right().right() << endl;

    cout << "All trees are going to be deleted now!" << endl;
}


#endif

int main()
{
#ifdef P1
            
    testBasicOperations();
    
#endif

#ifdef P2
                
    testCopyControl();
        
#endif

#ifdef P3
                    
    testMoveControl();
            
#endif

    return 0;
}
