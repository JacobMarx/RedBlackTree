/*
	Created by Jacob Marx, 4/21/19.
*/

#ifndef RBTREE_H
#define RBTREE_H

#include <iostream>

class RBTree {
	
public:
	//Constructors
	Tree();
	~Tree();
	
	//Member Functions
	bool isempty() const;
	int pop();
	
	void display();
	void remove(int);
	void push(int);

private:
	// Private Members
	Node* root;
	
	// Private Functions
	void push(Node*&, int);
	void print(Node*, int) cons
	
};

#endif RBTREE_H