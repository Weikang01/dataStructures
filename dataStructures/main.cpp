#include "sqStack.h"
#include <iostream>

int main()
{
	sqStack st(5, 5);
	st.push(10);
	st.push(8);
	std::cout << st << std::endl;

	std::cin.get();
	return 0;
}