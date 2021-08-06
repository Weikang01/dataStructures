#include <iostream>
#include "chainQueue.h"


int main()
{
	chQueue<int> q;
	q.push(12);
	q.push(1);
	q.push(5);
	std::cout << q << std::endl;
	std::cin.get();
	return 0;
}