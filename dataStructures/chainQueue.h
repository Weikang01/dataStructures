#pragma once
#include <ostream>

template<typename ElemType>
class chQueue
{
	struct Node
	{
		ElemType value;
		Node* next = nullptr;
		Node(ElemType v) noexcept
			:value(v)
		{}
		~Node() noexcept
		{
			delete next;
		}
	};
public:
	chQueue() noexcept
		:front(nullptr), rear(nullptr), length(0)
	{}
	chQueue(const chQueue& q) noexcept
	{
		if (this == q)
			return;
		this->front = q.front;
		this->rear = q.rear;
		this->length = q.length;
	}
	~chQueue() noexcept
	{
		free(front);
		free(rear);
	}
	void push(ElemType e) noexcept
	{
		Node* node = new Node(e);
		if (front == nullptr)
		{
			front = node;
			rear = node;
		}
		else
		{
			rear->next = node;
			rear = node;
		}
		length++;
	}
	ElemType pop() noexcept
	{
		if (front == nullptr) return NULL;
		ElemType v = front->value;
		front = front->next;
		length--;
		return v;
	}
	friend std::ostream& operator<<(std::ostream& out, const chQueue<ElemType>& q)
	{
		if (q.front == nullptr)
		{
			out << "[]";
			return out;
		}
		chQueue::Node* cur = q.front;
		out << "[ ";
		while (cur->next != nullptr)
		{
			out << cur->value << ", ";
			cur = cur->next;
		}
		out << cur->value << " ]";
		return out;
	}
	unsigned int size()
	{
		return length;
	}
private:
	Node* front;
	Node* rear;
	unsigned int length;
};

