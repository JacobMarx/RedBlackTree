/*
	Created by Jacob Marx, 4/21/19.
*/

#include "Node.h"
#include "RBTree.h"

Tree::Tree() {
	root = NULL;
}

Tree::~Tree() {
	
}

bool Tree::isempty() const {
	if (!root) {
		return true;
	}
	return false;
}

void Tree::print(Node* node, int depth) const {
	/*
	Color stuff from 
	https://stackoverflow.com/questions/2616906/how-do-i-output-coloured-text-to-a-linux-terminal
	by Daniel Langar
	*/
	
	const std::string red("\033[0;31m");
	const std::string reset("\033[0m");
	
	if (node == NULL) return;
	
	print(node->right, depth + 1);
	
	int count = depth;
	while (count > 0) {
		std::cout << '\t';
		count--;
	}
	
	if (node->color = 2) {
	std::cout << red << node->data << reset << std::endl;
	}
	else {
		std::cout << node->data << std::endl;
	}
	
	print(node->left, depth + 1);
}


void Tree::push(int input) {
	//	Black height of tree increases 1
	if (!root) {
		root = new Node(input, 1);
	}
	else {
		push(root, input);
	}
}

void Tree::push(Node*& node, int input) {
	//	Standard BST insertion and node color is red
	if (node->left != NULL) {
		if (input < node->data) {
			push(node->left, input);
		}
	}
	if (node->right != NULL) {
		if (input > node->data) {
			push(node->right, input);
		}
	}
	if (node->left == NULL) {
		if (input < node->data) {
			node->left = new Node(input);
			node->left->parent = node;
			node-left->color = 2;
		}
	}
	if (node->right == NULL) {
		if (input > node->data) {
			node->right = new Node(input);
			node->right->parent = node;
			node->right->color = 2;
		}
	}
	
	//	If parent of new node's color is not black or new node is not root
	//		If new node's uncle is red
	//			Change color of parent and uncle to black
	//			Color of grandparent to red
	//			New node's 
}