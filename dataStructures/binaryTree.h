#pragma once
#include <iostream>
#include <sstream>

template<typename T, bool (comp) (T a, T b) = [](T a, T b) {return a > b; } >
class binaryTree
{
public:
	enum class TraversalOrder
	{
		inOrder,
		preOrder,
		postOrder
	};
private:
	struct Node
	{
		T value;
		struct Node* lchild = nullptr;
		struct Node* rchild = nullptr;
		Node() = default;
		Node(T val)
			:value(val)
		{}
	};
public:
	binaryTree()
	{}

	~binaryTree()
	{
		Node* parent = root;
		Node* left   = root->lchild;
		Node* right  = root->rchild;

		free(parent);
	}
	void add(T val)
	{
		if (root == nullptr)
			root = new Node(val);
		else
		{
			Node* cur = root;

			while (cur != nullptr)
			{
				if (comp(val, cur->value))
				{
					if (cur->rchild != nullptr)
					{
						cur = cur->rchild;
						continue;
					}
					else
					{
						cur->rchild = new Node(val);
						return;
					}
				}
				else
				{
					if (cur->lchild != nullptr)
					{
						cur = cur->lchild;
						continue;
					}
					else
					{
						cur->lchild = new Node(val);
						return;
					}
				}
			}
		}
	}

	void inOrderTraverse() 
	{
		std::stringstream oss;
		Node* cur = root;

		// TODO: traverse



		std::cout << oss.str() << std::endl;
	}

	void preOrderTraverse() 
	{}

	void postOrderTraverse() 
	{}

	void traverse(const TraversalOrder order) 
	{
		switch (order)
		{
		case TraversalOrder::inOrder:
			inOrderTraverse();
			return;
		case TraversalOrder::preOrder:
			preOrderTraverse();
			return;
		case TraversalOrder::postOrder:
			postOrderTraverse();
			return;
		}
	}
private:

private:
	Node* root = nullptr;
};