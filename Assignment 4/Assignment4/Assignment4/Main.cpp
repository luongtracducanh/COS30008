
// COS30008, Problem Set 4, 2022

#include <iostream>

using namespace std;

//#define P1
//#define P2
//#define P3

#ifdef P1

#include "BinaryTreeNode.h"

// operator<: order strings in binary tree
bool operator<( const string& aLHS, const string& aRHS )
{
    return aLHS.compare( aRHS ) < 0;
}

void testBNode()
{
    using BTNode = BinaryTreeNode<string>;
    using BTTree = BTNode*;
    
    BTTree lRoot = &BTNode::NIL;
    
    cout << "Test BinaryTreeNode:" << endl;
    
    if ( lRoot->insert( "25" ) )
    {
        cerr << "This message must not appear! NIL cannot be used to insert elements." << endl;
    }
    else
    {
        cout << "lRoot is NIL; insert failed successfully." << endl;
    }

    try
    {
        cout << "Determining height of NIL." << endl;
        
        lRoot->height();

        cerr << "This message must not appear! NIL has no height." << endl;
    }
    catch (domain_error e)
    {
        cout << "Successfuly caught domain error: " << e.what() << endl;
    }
    
    string lValues[] = { "10", "15", "37", "10", "30", "65" };
    string l25( "25" );

    cout << "Insert of " << l25  << " as root." << endl;

    lRoot = new BTNode( std::move( l25 ) );

    if ( l25.empty() )
    {
        cout << "Successfully applied move constructor." << endl;
    }
    else
    {
        cerr << "This message must not appear! Move failed." << endl;
    }
    
    for ( const string& i : lValues )
    {
        if ( lRoot->insert( i ) )
        {
            cout << "Insert of " << i  << " succeeded." << endl;
        }
        else
        {
            cout << "Insert of " << i  << " failed (duplicate key)." << endl;
        }
    }

    try
    {
        cout << "Height of tree: " << lRoot->height() << endl;
    }
    catch (domain_error e)
    {
        cerr << "This message must not appear! lRoot is not NIL." << endl;
        cerr << e.what() << endl;
    }

    cout << "Delete binary tree" << endl;
    
    if ( !lRoot->empty() )
    {
        delete lRoot;
    }
    else
    {
        cerr << "This message must not appear!" << endl;
    }
        
    cout << "Test BinaryTreeNode completed." << endl;
}

#endif

#ifdef P2

#include "BinarySearchTree.h"

void testBinarySearchTree()
{
    using BSTree = BinarySearchTree<int>;

    cout << "Test Binary Search Tree:" << endl;

    BSTree lTree;
    int lValues[] = { 25, 10, 15, 37, 10, 30, 65 };

    try
    {
        lTree.height();
        
        cout << "Height on empty tree succeeded!" << endl;
    }
    catch (domain_error e)
    {
        cerr << "Error: " << e.what() << endl;
    }

    for ( const int& i : lValues )
    {
        if ( lTree.insert( i ) )
        {
            cout << "insert of " << i  << " succeeded." << endl;
        }
        else
        {
            cout << "insert of " << i  << " failed." << endl;
        }
    }

    cout << "Height of tree: " << lTree.height() << endl;
         
    cout << "Delete binary search tree now." << endl;

    for ( const int& i : lValues )
    {
        if ( lTree.remove( i ) )
        {
            cout << "remove of " << i  << " succeeded." << endl;
        }
        else
        {
            cout << "remove of " << i  << " failed." << endl;
        }
    }

    cout << "Test Binary Search Tree completed." << endl;
}

#endif

#ifdef P3
 
#include "BinarySearchTreeIterator.h"

void testIterator()
{
    using BSTree = BinarySearchTree<int>;

    cout << "Test Binary Search Tree Iterator DFS:" << endl;

    BSTree lTree;
    int lValues[] = { 25, 10, 15, 37, 10, 30, 65, 8 };

    for ( const int& i : lValues )
    {
        lTree.insert( i );
    }
    
    cout << "DFS:";
    
    for ( const auto& i : lTree )
    {
        cout << " " << i;
    }

    cout << endl;

    cout << "Test Binary Search Tree Iterator DFS completed." << endl;
}
        
#endif

int main()
{
#ifdef P1
    
    testBNode();
    
#endif

#ifdef P2
        
    testBinarySearchTree();
        
#endif

#ifdef P3
            
    testIterator();
            
#endif

    return 0;
}
