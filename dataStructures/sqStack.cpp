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

void sqStack::push(ElemType e)
{
	if (top >= size)
	{
		ElemType* newbase = new ElemType[size + increment];
		for (size_t i = 0; i < size; i++) newbase[i] = elem[i];
		elem = newbase;
		size += increment;
	}
	elem[top++] = e;
}

ElemType sqStack::pop()
{
	if (top == 0)
		return NULL;
	return elem[top--];
}

ElemType sqStack::GetTop()
{
	if (top == 0) return NULL;
	return elem[top-1];
}

std::ostream& operator<<(std::ostream& out, sqStack& const st)
{
	if (st.top == 0)
	{
		out << "[]";
		return out;
	}
	out << "[ ";
	for (size_t i = 0; i < st.top - 1; i++)
	{
		out << st.elem[i] << ", ";
	}
	out << st.elem[st.top - 1] << " ]";
	return out;
}
