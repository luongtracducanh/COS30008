#include "DoublyLinkedList.h";

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(const T& aPayload) : fNext(), fPrevious()
{
	
}

template <typename T>
DoublyLinkedList<T>::DoublyLinkedList(T&& aPayload) :fNext(), fPrevious()
{
	
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::push_front(DoublyLinkedList& aNode)
{
	DoublyLinkedList root = new DoublyLinkedList(aNode);
	DoublyLinkedList node = new DoublyLinkedList(aNode);
	root->push_front(*node);
	root = node;
	
}

template <typename T>
DoublyLinkedList<T>& DoublyLinkedList<T>::push_back(DoublyLinkedList& aNode)
{
	DoublyLinkedList root = new DoublyLinkedList(aNode);
	DoublyLinkedList node = new DoublyLinkedList(aNode);
	root->push_back(*node);
	root = node;
}

template <typename T>
void DoublyLinkedList<T>::isolate()
{
	// remove a node from the list
	// unplug fNext and fPrevious, pointing next and previous to itself

}

template <typename T>
void DoublyLinkedList<T>::swap(DoublyLinkedList& aNode)
{
	// swap the values of 2 nodes
}

template <typename T>
const T& DoublyLinkedList<T>::operator*() const
{
	return operator*();
}

template <typename T>
const T& DoublyLinkedList<T>::getPayload() const
{
	return getPayload();
}

template <typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::getNext() const
{
	return getNext();
}

template <typename T>
const DoublyLinkedList<T>& DoublyLinkedList<T>::getPrevious() const
{
	return getPrevious();
}

// bi-directional iterator for the linked list