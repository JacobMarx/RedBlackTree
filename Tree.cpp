/*
	Created by Jacob Marx, 4/21/19.
*/

#include "Node.h"
#include "Tree.h"

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

Node* Tree::getRoot() {
	return root;
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
	
	if (node->color == 2) {
	std::cout << red << node->data << reset << std::endl;
	}
	else {
		std::cout << node->data << std::endl;
	}
	
	print(node->left, depth + 1);
}

void Tree::display() {
	int depth = 0;
	print(root, depth);
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
			node->left->color = 2;
		}
	}
	if (node->right == NULL) {
		if (input > node->data) {
			node->right = new Node(input);
			node->right->parent = node;
			node->right->color = 2;
		}
	}
	
	reColor(node);
	
}

void Tree::reColor(Node*) {
	// Sets grandparent of node as node
	if (node->parent->parent != NULL) {
		Node* gParent = node->parent->parent;
	}
	// Sets uncle of node as node
	if (node->parent->parent->left != NULL) {
		if (node->parent->parent->left == node->parent) {
			if (node->parent->parent->right != NULL) {
				Node* uncle = node->parent->parent->right;
			}
		}
	}
	else if (node->parent->parent->right != NULL) {
		if (node->parent->parent->right == node->parent) {
			if (node->parent->parent->left != NULL) {
				Node* uncle = node->parent->parent->left;
			}
		}
	}
	// If parent of new node's color is not black or new node is not root
	if (node->parent->color != 1) {
	// If new node's uncle is red
		if (uncle != NULL) {
			if (uncle->color == 2) {
				// Change color of parent and uncle to black
				node->parent->color = 1;
				uncle->color = 1;
				// Color of grandparent to red
				gParent->color = 2;
				// New node's 
				if (gParent != NULL) {
					reColor(gParent);
				}
			}
		}
	// If new node's uncle is black
		if (uncle != NULL) {
			if (uncle->color == 1) {
				// Left left case
				if (gParent->left != NULL && node->parent->left != NULL) {
					if (gParent->left == node->parent && parent->left == node) {
						// Right rotate gParent
						if (node->parent->right != NULL) {
							gParent->left = node->parent->right;
						}
						else {
							gParent->left == NULL;
						}
						node->parent->right = gParent;
						gparent->parent = node->parent;
						// Swap colors of gParent and parent
						int gcolor = gParent->color;
						gParent->color = node->parent->color;
						node->parent->color = gcolor;
					}
				}
				//Left right case
				if (gParent->left != NULL && node->parent->right != NULL) {
					if (gParent->left == node->parent && node->parent->right == node) {
						// Left rotate parent
						gParent->left = node;
						
						// Apply left left case
					}
				}
				//Right right case
				if (gParent->right != NULL && node->parent->right != NULL) {
					if (gParent->right == node->parent && node->parent->right == node) {
						// Stuff
					}
				}
				// Right left case
				if (gParent->right != NULL && node->parent->left != NULL) {
					if (gParent->right == node->parent && node->parent->left == node) {
						// Stuff
					}
				}
			}
		}
	}

}