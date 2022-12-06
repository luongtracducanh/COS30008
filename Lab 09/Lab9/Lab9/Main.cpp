
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#include <iostream>

#include <string>

using namespace std;

//#define P1
//#define P2
//#define P3
//#define P4
//#define P5

#ifdef P1

#include "DoublyLinkedList.h"

void test1()
{
    using StringNode = DoublyLinkedList<string>;

    cout << "Test:" << endl;
    cout << "\tpush_front()\n"
         << "\toperator*()\n"
         << "\tgetPrevious()\n"
         << "\tgetNext()" << endl;

    string s2( "Two" );
    string s3( "Three" );
    
    StringNode n1( "One" );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( "Four" );
    
    n1.push_front( n4 );
    n1.push_front( n3 );
    n1.push_front( n2 );
    
    cout << "The nodes (forwards):" << endl;
    
    const StringNode* pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getNext();
    } while ( pn != &n1 );
    
    cout << "The nodes (backwards):" << endl;

    pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getPrevious();
    } while ( pn != &n1 );
}

#endif

#ifdef P2

#include "DoublyLinkedList.h"

void test2()
{
    using StringNode = DoublyLinkedList<string>;
    
    cout << "Test:" << endl;
    cout << "\tpush_back()" << endl;

    string s2( "Two" );
    string s3( "Three" );
    
    StringNode n1( "One" );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( "Four" );
    
    n1.push_back( n4 );
    n1.push_back( n3 );
    n1.push_back( n2 );
        
    const StringNode* pn = &n1;
    
    cout << "The nodes (forwards):" << endl;

    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getNext();
    } while ( pn != &n1 );
        
    cout << "The nodes (backwards):" << endl;

    pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getPrevious();
    } while ( pn != &n1 );
}

#endif

#ifdef P3

#include "DoublyLinkedList.h"

void test3()
{
    using StringNode = DoublyLinkedList<string>;
    
    cout << "Test:" << endl;
    cout << "\tisolate()" << endl;

    string s2( "Two" );
    string s3( "Three" );
    
    StringNode n1( "One" );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( "Four" );
    
    n1.push_front( n4 );
    n1.push_front( n3 );
    n1.push_front( n2 );
    
    cout << "The nodes (forwards):" << endl;
    
    const StringNode* pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getNext();
    } while ( pn != &n1 );
    
    cout << "isolate " << *n3 << endl;
    
    n3.isolate();
    
    cout << "The nodes (backwards):" << endl;

    pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getPrevious();
    } while ( pn != &n1 );
}

#endif

#ifdef P4

#include "DoublyLinkedList.h"

void test4()
{
    using StringNode = DoublyLinkedList<string>;
    
    cout << "Test:" << endl;
    cout << "\tswap()" << endl;

    string s2( "Two" );
    string s3( "Three" );
    
    StringNode n1( "One" );
    StringNode n2( s2 );
    StringNode n3( s3 );
    StringNode n4( "Four" );

    n1.push_front( n4 );
    n1.push_front( n3 );
    n1.push_front( n2 );
    
    cout << "The nodes (forwards):" << endl;
    
    const StringNode* pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getNext();
    } while ( pn != &n1 );
    
    cout << "swap " << *n3 << " <=> " << *n1 << endl;
    
    n3.swap( n1 );
    
    cout << "The nodes (forwards):" << endl;

    pn = &n1;
    
    do
    {
        cout << "(";
        cout << *(pn->getPrevious());
        cout << "," << **pn << ",";
        cout << *(pn->getNext());
        cout << ")" << endl;
        
        pn = &pn->getNext();
    } while ( pn != &n1 );
}

#endif

#ifdef P5

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"

void test5()
{
    using StringNode = DoublyLinkedList<string>;
    using StringIterator = DoublyLinkedListIterator<string>;

    StringNode n1( "One" );
    StringNode n2( "Two" );
    StringNode n3( "Three" );
    StringNode n4( "Four" );
    StringNode n5( "Five" );
    StringNode n6( "Six" );
    
    n1.push_back( n6 );
    n1.push_back( n5 );
    n1.push_back( n4 );
    n1.push_back( n3 );
    n1.push_back( n2 );
    
    StringIterator iter( &n1 );
    
    iter++;
    
    cout << "Forward iteration I:" << endl;
    for ( --iter; iter != iter.end(); iter++ )
        cout << *iter << endl;
    
    cout << "Backward iteration I:" << endl;
    for ( --iter; iter != iter.rend(); iter-- )
        cout << *iter << endl;
    
    cout << "Forward iteration II:" << endl;
    for ( iter = iter.begin(); iter != iter.end(); ++iter )
        cout << *iter << endl;
    
    cout << "Backward iteration II:" << endl;
    for ( iter = iter.rbegin(); iter != iter.rend(); --iter )
        cout << *iter << endl;
    
    StringIterator iter2( nullptr );

    cout << "Iterator tests:" << endl;

    if ( iter2 == iter2.end() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    if ( iter2.begin() == iter2.end() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
    
    if ( iter2.rbegin() == iter2.rend() )
        cout << "Yes" << endl;
    else
        cout << "No" << endl;
}

#endif


int main()
{
#ifdef P1
    test1();
#endif

#ifdef P2
    test2();
#endif
    
#ifdef P3
    test3();
#endif

#ifdef P4
    test4();
#endif
    
#ifdef P5
    test5();
#endif
    
    return 0;
}
