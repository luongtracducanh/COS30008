#pragma once

#include "DoublyLinkedList.h"
#include "DoublyLinkedListIterator.h"
#include <stdexcept>

template<typename T>
class List
{
private:
	// auxiliary definition to simplify node usage
	using Node = DoublyLinkedList<T>;

	Node* fRoot; // the first element in the list
	size_t fCount; // number of elements in the list

public:
	// auxiliary definition to simplify iterator usage
	using Iterator = DoublyLinkedListIterator<T>;

	~List()
	{
		while (fRoot != nullptr)
		{
			if (fRoot != &fRoot->getPrevious())
			{
				Node* lTemp = const_cast<Node*>(&fRoot->getPrevious());
				lTemp->isolate();
				delete lTemp;
			}
			else
			{
				delete fRoot;
				break;
			}
		}
	} // destructor - frees all nodes

	void remove(const T& aElement)
	{
		Node* lNode = fRoot;
		while (lNode != nullptr)
		{
			if (**lNode == aElement)
			{
				break;
			}
			if (lNode != &fRoot->getPrevious())
			{
				lNode = const_cast<Node*>(&lNode->getNext());
			}
			else
			{
				lNode = nullptr;
			}
		}
		if (lNode != nullptr)
		{
			if (fCount != 1)
			{
				if (lNode == fRoot)
				{
					fRoot = const_cast<Node*>(&fRoot->getNext());
				}
			}
			else
			{
				fRoot = nullptr;
			}
			lNode->isolate();
			delete lNode;
			fCount--;
		}
	} // remove first match from list

	// P1

	List(): fRoot(nullptr), fCount(0) {} // default constructor

	bool empty() const
	{
		return fRoot == nullptr;
	} // Is list empty?

	size_t size() const
	{
		return fCount;
	} // list size

	void push_front(const T& aElement)
	{
		if (empty())
		{
			fRoot = new Node(aElement);
		}
		else
		{
			Node* lNode = new Node(aElement);
			fRoot->push_front(*lNode);
			fRoot = lNode;
		}
		++fCount;
	} // adds aElement at front

	Iterator begin() const
	{
		return Iterator(fRoot).begin();
	} // return a forward iterator

	Iterator end() const
	{
		return Iterator(fRoot).end();
	} // return a forward end iterator

	Iterator rbegin() const
	{
		return Iterator(fRoot).rbegin();
	} // return a backwards iterator

	Iterator rend() const
	{
		return Iterator(fRoot).rend();
	} // return a backwards end iterator

	// P2

	void push_back(const T& aElement)
	{
		if (empty())
		{
			fRoot = new Node(aElement);
		}
		else
		{
			Node* lastNode = const_cast<Node*>(&fRoot->getPrevious());
			lastNode->push_back(*new Node(aElement));
		}
		++fCount;
	} // adds aElement at back

	// P3

	const T& operator[](size_t aIndex) const
	{
		if (aIndex > size() - 1)
		{
			throw std::out_of_range("Index out of bounds");
		}
		Iterator lIterator = Iterator(fRoot).begin();
		for (size_t i = 0; i < aIndex; i++)
		{
			++lIterator;
		}
		return *lIterator;
	} // list indexer

	// P4

	List(const List& aOtherList): fRoot(nullptr), fCount(0)
	{
		*this = aOtherList;
	} // copy constructor

	List& operator=(const List& aOtherList)
	{
		if (&aOtherList != this)
		{
			this->~List();
			if (aOtherList.fRoot == nullptr)
			{
				fRoot = nullptr;
			}
			else
			{
				fRoot = nullptr;
				fCount = 0;
				for (auto& payload : aOtherList)
				{
					push_back(payload);
				}
			}
		}
		return *this;
	} // assignment operator
	
	// P5

	// move features
	List(List&& aOtherList): fRoot(nullptr), fCount(0)
	{
		*this = std::move(aOtherList);
	} // move constructor

	List& operator=(List&& aOtherList)
	{
		if (&aOtherList != this)
		{
			this->~List();
			if (aOtherList.fRoot == nullptr)
			{
				fRoot = nullptr;
			}
			else
			{
				fRoot = aOtherList.fRoot;
				fCount = aOtherList.fCount;
				aOtherList.fRoot = nullptr;
				aOtherList.fCount = 0;
			}
		}
		return *this;
	} // move assignment operator

	void push_front(T&& aElement)
	{
		if (empty())
		{
			fRoot = new Node(std::move(aElement));
		}
		else
		{
			Node* lNode = new Node(std::move(aElement));
			fRoot->push_front(*lNode);
			fRoot = lNode;
		}
		++fCount;
	} // adds aElement at front

	void push_back(T&& aElement)
	{
		if (empty())
		{
			fRoot = new Node(aElement);
		}
		else
		{
			Node* lastNode = const_cast<Node*>(&fRoot->getPrevious());
			lastNode->push_back(*new Node(aElement));
		}
		++fCount;
	} // adds aElement at back
};
