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
	
	/* LL
	std::cout << "****************************" << std::endl;
	tree->push(4);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(2);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(6);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(3);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(1);
	tree->display();
	*/
	
	
	std::cout << "****************************" << std::endl;
	tree->push(23);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(54);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(12);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(34);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(27);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(11);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(7);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(47);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(39);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(20);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(59);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(15);
	tree->display();
	
	
	
	/*
	std::cout << "****************************" << std::endl;
	tree->push(4);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(2);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(6);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(1);
	tree->display();
	std::cout << "****************************" << std::endl;
	tree->push(3);
	tree->display();
	*/
	
}

