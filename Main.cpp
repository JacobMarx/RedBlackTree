/*
	Created by Jacob Marx, 4/21/19.
	This program creates a red black tree you can
	add and delete nodes to.
*/

#include <iostream>
#include "Node.h"
#include "Tree.h"

void build();

int main() {
	build();
	return 0;
}

void build() {
	Tree* tree = new Tree();
	
	tree->push(3);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(5);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(2);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(4);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(6);
	tree->display();
}

