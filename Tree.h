/*
	Created by Jacob Marx, 4/21/19.
*/

#ifndef TREE_H
#define TREE_H

#include <iostream>
#include "Node.h"

class Tree {
	
public:
	//Constructors
	Tree();
	~Tree();
	
	//Member Functions
	bool isempty() const;
	int pop();
	Node* getRoot();
	
	void display();
	void remove(int);
	void push(int);
	void reColor(Node*);

private:
	// Private Members
	Node* root;
	
	// Private Functions
	void push(Node*&, int);
	void print(Node*, int) const;
	
};

#endif