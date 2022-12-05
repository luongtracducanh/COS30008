#pragma once
template<typename T>
class DoublyLinkedList
{
private:

	T fPayload; // payload
	DoublyLinkedList* fNext; // next element
	DoublyLinkedList* fPrevious; // previous element

public:

	explicit DoublyLinkedList(const T& aPayload); // l-value constructor
	explicit DoublyLinkedList(T&& aPayload); // r-value constructor

	// aNode becomes previous of this
	DoublyLinkedList& push_front(DoublyLinkedList& aNode);
	// aNode becomes next of this
	DoublyLinkedList& push_back(DoublyLinkedList& aNode);
	void isolate(); // removes this node
	void swap(DoublyLinkedList& aNode); // exchange payloads
	// dereference operator, payload
	const T& operator*() const;
	// returns constant reference to paylod
	const T& getPayload() const;
	// returns constant reference to next
	const DoublyLinkedList& getNext() const;
	// returns constant reference to previous
	const DoublyLinkedList& getPrevious() const;
};