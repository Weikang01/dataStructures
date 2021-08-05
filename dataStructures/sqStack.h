#pragma once

typedef int ElemType;
typedef int Status;

class sqStack
{
public:
	sqStack(int size, int inc);
	~sqStack();
	bool isEmpty();
	void clear();
	bool push(ElemType e);
private:
	ElemType* elem;
	int top;
	int size;
	int increment;
};


