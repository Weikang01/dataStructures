#pragma once
#include <ostream>

typedef int ElemType;
typedef int Status;

class sqStack
{
public:
	sqStack(int size, int inc);
	~sqStack();
	bool isEmpty();
	void clear();
	void push(ElemType e);
	ElemType pop();
	ElemType GetTop();
	friend std::ostream& operator<<(std::ostream& out, sqStack& const st);
private:
	ElemType* elem;
	int top;
	int size;
	int increment;
};
