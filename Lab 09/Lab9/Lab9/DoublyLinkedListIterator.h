#pragma once
#include "DoublyLinkedList.h"
template<typename T>
class DoublyLinkedListIterator
{
private:
	enum class States { BEFORE, DATA, AFTER }; // iterator states
	using Node = DoublyLinkedList<T>;
	const Node* fRoot; // doubly-linked list
	States fState; // iterator state
	const Node* fCurrent; // iterator position

public:

	using Iterator = DoublyLinkedListIterator<T>;
	DoublyLinkedListIterator(const Node* aRoot); // constructor
	const T& operator*() const; // dereference
	Iterator& operator++(); // prefix increment
	Iterator operator++(int); // postfix increment
	Iterator& operator--(); // prefix decrement
	Iterator operator--(int); // postfix decrement
	bool operator==(const Iterator& aOtherIter) const; // equivalence
	bool operator!=(const Iterator& aOtherIter) const; // not equal
	Iterator begin() const; // first element forward
	Iterator end() const; // after last element forward
	Iterator rbegin() const; // first element backwards
	Iterator rend() const; // before first element backwards
};