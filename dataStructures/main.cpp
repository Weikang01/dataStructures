#include <iostream>
#include "binaryTree.h"

int main()
{
	binaryTree<int> t;
	t.add(2);
	t.add(10);
	t.add(1);
	t.add(3);
	t.inOrderTraverse();
	std::cin.get();
	return 0;
}