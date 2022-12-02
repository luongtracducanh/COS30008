
// COS30008, Final Exam, 2022

#include <iostream>
#include <string>
#include <stdexcept>

using namespace std;

//#define P1
//#define P2
//#define P3
//#define P4

// Test keys
string s1( "This" );
string s2( "is" );
string s3( "a" );
string s4( "ternary" );
string s5( "tree" );
string s6( "in" );
string s7( "action." );
string s8( "It" );
string s9( "works!" );

#ifdef P1

#include "TernaryTree.h"

void runP1()
{
    cout << "Test Problem 1:" << endl;

    using S3Tree = TernaryTree<string>;
    
    cout << "Setting up ternary tree..." << endl;
    
    S3Tree root( s1 );
    S3Tree* nA = new S3Tree( s2 );
    S3Tree* nB = new S3Tree( s5 );
    S3Tree* nC = new S3Tree( s7 );
    S3Tree nAA( s3 );
    S3Tree nAAC( s4 );
    S3Tree nBB( s6 );
    S3Tree nCB( s8 );
    S3Tree nCC( s9 );

    nAA.addRight( nAAC );
    nA->addLeft( nAA );
    
    nB->addMiddle( nBB );
    
    nC->addMiddle( nCB );
    nC->addRight( nCC );
    
    root.addLeft( *nA );
    root.addMiddle( *nB );
    root.addRight( *nC );
    
    try
    {
        root.addRight( *nC );
        
        cerr << "Error: Non-empty subtree overridden." << endl;
    }
    catch (std::domain_error e)
    {
        cout << "Successfully caught: " << e.what() << endl;
    }

    cout << "Testing basic ternary tree logic ..." << endl;

    cout << "Is NIL empty? " << (S3Tree::NIL.empty() ? "Yes" : "No") << endl;
    cout << "Is root empty? " << (root.empty() ? "Yes" : "No") << endl;

    try
    {
        cout << "Height of root is: " << root.height() << endl;
        
        S3Tree::NIL.height();
        
        cerr << "Error: NIL has no height." << endl;
    }
    catch (std::domain_error e)
    {
        cout << "Successfully caught: " << e.what() << endl;
    }

    cout << "Tearing down ternary tree..." << endl;

    nC->removeRight();
    nC->removeMiddle();
    nB->removeMiddle();
    nAA.removeRight();
    nA->removeLeft();

    try
    {
        nA->removeLeft();

        cerr << "Error: Empty subtree removed." << endl;
    }
    catch (std::domain_error e)
    {
        cout << "Successfully caught: " << e.what() << endl;
    }

    cout << "Nodes nA, nB, nC get destroyed by destructor." << endl;
    
    cout << "Test Problem 1 complete." << endl;
}

#endif

#ifdef P2

#include "TernaryTree.h"

void runP2()
{
    cout << "Test Problem 2:" << endl;

    using S3Tree = TernaryTree<string>;
    
    S3Tree root( s1 );
    S3Tree* nA = new S3Tree( s2 );
    S3Tree* nB = new S3Tree( s5 );
    S3Tree* nC = new S3Tree( s7 );
    S3Tree* nAA = new S3Tree( s3 );
    S3Tree* nAAC = new S3Tree( s4 );
    S3Tree* nBB = new S3Tree( s6 );
    S3Tree* nCB = new S3Tree( s8 );
    S3Tree* nCC = new S3Tree( s9 );

    nAA->addRight( *nAAC );
    nA->addLeft( *nAA );
    
    nB->addMiddle( *nBB );
    
    nC->addMiddle( *nCB );
    nC->addRight( *nCC );
    
    root.addLeft( *nA );
    root.addMiddle( *nB );
    root.addRight( *nC );

    S3Tree copy = root;
    
    const S3Tree* lLeft;
    const S3Tree* lRight;

    lLeft = &copy.getLeft().getLeft().getRight();
    lRight = &root.getLeft().getLeft().getRight();

    if ( lLeft == lRight )
    {
        cerr << "Error: Shallow copy detected." << endl;
    }
    else
    {
        cout << "Copy constructor appears to work properly." << endl;
    }

    lLeft = &copy.getMiddle().getLeft();
    lRight = &root.getMiddle().getRight();

    if ( lLeft != lRight )
    {
        cerr << "Error: Copy does not preserve tree structure." << endl;
    }
    else
    {
        if ( !lLeft->empty() )
        {
            cerr << "Error: NIL not preserved." << endl;
        }
        else
        {
            cout << "Copy constructor preserves tree structure." << endl;
        }
    }
    
    root = copy;

    lLeft = &copy.getLeft().getLeft().getRight();
    lRight = &root.getLeft().getLeft().getRight();

    if ( lLeft == lRight )
    {
        cerr << "Error: Shallow copy detected." << endl;
    }
    else
    {
        cout << "Assignment appears to work properly." << endl;
    }

    lLeft = &copy.getMiddle().getLeft();
    lRight = &root.getMiddle().getRight();

    if ( lLeft != lRight )
    {
        cerr << "Error: Assignment does not preserve tree structure." << endl;
    }
    else
    {
        if ( !lLeft->empty() )
        {
            cerr << "Error: NIL not preserved." << endl;
        }
        else
        {
            cout << "Assignment preserves tree structure." << endl;
        }
    }
    
    try
    {
        root = S3Tree::NIL;
        
        cerr << "Error: Copy of NIL! You should not see this message." << endl;
    }
    catch (domain_error e)
    {
        cout << "Successfully caught: " << e.what() << endl;
    }
    
    S3Tree* clone = root.clone();

    lLeft = &clone->getLeft().getLeft().getRight();
    lRight = &root.getLeft().getLeft().getRight();

    if ( lLeft == lRight )
    {
        cerr << "Error: Shallow copy detected." << endl;
    }
    else
    {
        cout << "Clone appears to work properly." << endl;
    }

    delete clone;

    cout << "Trees root and copy get deleted next." << endl;
    cout << "Test Problem 2 complete." << endl;
}

#endif

#ifdef P3

#include "TernaryTree.h"

void runP3()
{
    cout << "Test Problem 3:" << endl;

    using S3Tree = TernaryTree<string>;
    
    S3Tree root( string( "This" ) );
    S3Tree* nA = new S3Tree( s2 );
    S3Tree* nB = new S3Tree( s5 );
    S3Tree* nC = new S3Tree( s7 );
    S3Tree* nAA = new S3Tree( s3 );
    S3Tree* nAAC = new S3Tree( s4 );
    S3Tree* nBB = new S3Tree( s6 );
    S3Tree* nCB = new S3Tree( "It" );
    S3Tree* nCC = new S3Tree( s9 );

    nAA->addRight( *nAAC );
    nA->addLeft( *nAA );
    
    nB->addMiddle( *nBB );
    
    nC->addMiddle( *nCB );
    nC->addRight( *nCC );
    
    root.addLeft( *nA );
    root.addMiddle( *nB );
    root.addRight( *nC );

    S3Tree copy = std::move(root);
    
    if ( root.leaf() )
    {
        cout << "std::move makes root a leaf node." << endl;
    }
    else
    {
        cerr << "Error: You should not see this message as root must become a leaf node." << endl;
    }
    
    cout << "The payload of tree: " << *copy << endl;
    cout << "The payload of tree.getLeft().getLeft().getRight():\t" << *copy.getLeft().getLeft().getRight() << endl;
    cout << "The payload of tree.getRight():\t" << *copy.getRight() << endl;

    root = std::move(copy);
        
    if ( copy.leaf() )
    {
        cout << "std::move makes copy a leaf node." << endl;
    }
    else
    {
        cerr << "Error: You should not see this message as copy must become a leaf node." << endl;
    }

    cout << "The payload of tree: " << *root << endl;
    cout << "The payload of tree.getLeft().getLeft().getRight():\t" << *root.getLeft().getLeft().getRight() << endl;
    cout << "The payload of tree.getRight():\t" << *root.getRight() << endl;

    try
    {
        root = std::move(S3Tree::NIL);
        
        cerr << "Error: Move of NIL! You should not see this message." << endl;
    }
    catch (domain_error e)
    {
        cout << "Successfully caught: " << e.what() << endl;
    }
    
    cout << "Test Problem 3 complete." << endl;
}

#endif

#ifdef P4

#include "TernaryTreePrefixIterator.h"

void runP4()
{
    cout << "Test Problem 4:" << endl;

    using S3Tree = TernaryTree<string>;
    
    S3Tree root( s1 );
    S3Tree* nA = new S3Tree( s2 );
    S3Tree* nB = new S3Tree( s5 );
    S3Tree* nC = new S3Tree( s7 );
    S3Tree* nAA = new S3Tree( s3 );
    S3Tree* nAAC = new S3Tree( s4 );
    S3Tree* nBB = new S3Tree( s6 );
    S3Tree* nCB = new S3Tree( s8 );
    S3Tree* nCC = new S3Tree( s9 );

    nAA->addRight( *nAAC );
    nA->addLeft( *nAA );
    
    nB->addMiddle( *nBB );
    
    nC->addMiddle( *nCB );
    nC->addRight( *nCC );
    
    root.addLeft( *nA );
    root.addMiddle( *nB );
    root.addRight( *nC );

    cout << "Test prefix iterator:";
    
    for ( const string& k : root )
    {
        cout << ' ' << k;
    }
    
    cout << endl;
    
    cout << "Test Problem 4 complete." << endl;
}

#endif

int main()
{
#ifdef P1
    runP1();
#endif

#ifdef P2
    runP2();
#endif

#ifdef P3
    runP3();
#endif

#ifdef P4
    runP4();
#endif

    return 0;
}

