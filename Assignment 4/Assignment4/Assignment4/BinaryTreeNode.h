#pragma once
#include <stdexcept>
#include <algorithm>
using namespace std;
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
		if (empty())
		{
			throw domain_error("Empty tree encountered");
		}
		if (right->empty())
		{
			return key;
		}
		return right->findMax();
	}
	const T& findMin() const
	{
		if (empty())
		{
			throw domain_error("Empty tree encountered");
		}
		if (left->empty())
		{
			return key;
		}
		return left->findMin();
	}
	bool remove(const T& aKey, BTreeNode aParent)
	{
        BTreeNode x = this;
        BTreeNode y = aParent;
        while (!x->empty())
        {
            if (aKey == x->key)
            {
                break;
            }
            y = x;
            x = aKey < x->key ? x->left : x->right;
        }
        if (x->empty())
        {
            return false;
        }

        if (!x->left->empty())
        {
            const T& lKey = x->left->findMax();
            x->key = lKey;
            x->left->remove(lKey, x);
        }
        else
        {
            if (!x->right->empty())
            {
                const T& lKey = x->right->findMin();
                x->key = lKey;
                x->right->remove(lKey, x);
            }
            else
            {
                if (y != &NIL)
                {
                    if (y->left == x)
                    {
                        y->left = &NIL;
                    }
                    else
                    {
                        y->right = &NIL;
                    }
                }
                delete x;
            }
        }
        return true;
	}

	BinaryTreeNode(): key(T()), left(&NIL), right(&NIL){}
	BinaryTreeNode(const T& aKey): key(aKey), left(&NIL), right(&NIL){}
	BinaryTreeNode(T&& aKey): key(move(aKey)), left(&NIL), right(&NIL){}
	~BinaryTreeNode()
	{
		if (!left->empty())
		{
			delete left;
		}
		if (!right->empty())
		{
			delete right;
		}
	}

	bool empty() const
	{
		return this == &NIL;
	}
	bool leaf() const
	{
		return left->empty() && right->empty();
	}
	size_t height() const
	{
		if (empty())
		{
			throw domain_error("Empty tree encountered");
		}
		if (leaf())
		{
			return 0;
		}
		const int left_height = left->empty() ? 1 : left->height() + 1;
		const int right_height = right->empty() ? 1 : right->height() + 1;
		return max(left_height, right_height);
	}
	bool insert(const T& aKey)
	{
		if (empty())
		{
			return false;
		}
		if (aKey > key)
		{
			if (right->empty())
			{
				right = new BNode(aKey);
			}
			else
			{
				return right->insert(aKey);
			}
			return true;
		}
		if (aKey < key)
		{
			if (left->empty())
			{
				left = new BNode(aKey);
			}
			else
			{
				return left->insert(aKey);
			}
			return true;
		}
		return false;
	}
};
template<typename T>
BinaryTreeNode<T> BinaryTreeNode<T>::NIL;