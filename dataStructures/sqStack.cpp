#include "sqStack.h"
#include <stdexcept>

sqStack::sqStack(int size, int inc)
	:elem(new ElemType[size]), top(0), size(size), increment(inc)
{}

sqStack::~sqStack()
{
	free(elem);
}

bool sqStack::isEmpty()
{
	return top != 0;
}

void sqStack::clear()
{
	if (top == 0) return;
	size = 0;
	top = 0;
}

bool sqStack::push(ElemType e)
{
	if (top >= size)
	{
		ElemType* newbase = new ElemType[size + increment];
		for (size_t i = 0; i < size; i++) newbase[i] = elem[i];
		elem = newbase;
		size += increment;
	}

	return false;
}

