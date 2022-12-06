
// COS30008, Doubly-linked Nodes, Tutorial 9, 2022

#pragma once

template<typename T>
class DoublyLinkedList
{
private:
    
    T fPayload;
    DoublyLinkedList* fNext;
    DoublyLinkedList* fPrevious;
    
public:
    
    // l-value constructor
    explicit DoublyLinkedList( const T& aPayload ) :
        fPayload(aPayload),
        fNext(this),
        fPrevious(this)
    {}
    
    // r-value constructor
    explicit DoublyLinkedList( T&& aPayload ) :
        fPayload(std::move(aPayload)),
        fNext(this),
        fPrevious(this)
    {}
    
    DoublyLinkedList& push_front( DoublyLinkedList& aNode )
    {
        aNode.fNext = this;                     // make this the forward pointer of aNode
        
        aNode.fPrevious = fPrevious;            // make this's backward pointer aNode's
        fPrevious->fNext = &aNode;              // tie back to Node
        
        fPrevious = &aNode;                     // this' backward pointer becomes aNode
        
        return aNode;                           // last node inserted
    }
    
    DoublyLinkedList& push_back( DoublyLinkedList& aNode )
    {
        aNode.fPrevious = this;                 // make this the backwards pointer of aNode
        
        aNode.fNext = fNext;                    // make this's forward pointer aNode's
        fNext->fPrevious = &aNode;              // tie back to Node
        
        fNext = &aNode;                         // this' forward pointer becomes aNode
        
        return aNode;                           // last node inserted
    }
    
    void isolate()
    {
        fPrevious->fNext = fNext;               // unlink previous
        fNext->fPrevious = fPrevious;           // unlink next
        
        fPrevious = this;                       // isolate this node
        fNext = this;
    }
    
    void swap( DoublyLinkedList& aNode )
    {
        std::swap( fPayload, aNode.fPayload );  // exchange list elements
    }
    
    const T& operator*() const                  // dereference operator
    {
        return getPayload();
    }
    
    const T& getPayload() const
    {
        return fPayload;
    }
    
    const DoublyLinkedList& getNext() const
    {
        return *fNext;
    }

    const DoublyLinkedList& getPrevious() const
    {
        return *fPrevious;
    }
};
