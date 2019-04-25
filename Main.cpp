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
	
	tree->push(34);
	tree->push(45);
	tree->push(23);
	tree->push(56);
	tree->push(39);
	
	tree->display();
}

