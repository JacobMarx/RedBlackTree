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
	//std::cout << "Enter: " << node->data << std::endl;
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
			std::cout << "New Node: " << node->left->data << std::endl << std::endl;
			setFam(node->left);
		}
	}
	if (node->right == NULL) {
		if (input > node->data) {
			node->right = new Node(input);
			node->right->parent = node;
			node->right->color = 2;
			std::cout << "New Node: " << node->right->data << std::endl << std::endl;
			setFam(node->right);
		}
	}	
}

void Tree::setFam(Node* node) {
	// Saved pointers
	Node* g = NULL;
	Node* u = NULL;
	Node* p = NULL;
	
	// Sets grandparent of node as node
	if (node->parent != NULL && node->parent->parent != NULL) {
		g = node->parent->parent;
	}
	// Sets u of node as node
	if (node->parent != NULL && node->parent->parent != NULL && node->parent->parent->left != NULL) {
		if (node->parent->parent->left == node->parent) {
			if (node->parent->parent->right != NULL) {
				u = node->parent->parent->right;
			}
		}
	}
	if (node->parent != NULL && node->parent->parent != NULL && node->parent->parent->right != NULL) {
		if (node->parent->parent->right == node->parent) {
			if (node->parent->parent->left != NULL) {
				u = node->parent->parent->left;
			}
		}
	}
	if (node->parent != NULL) {
		p = node->parent;
	}
	
	if (u == NULL) {
		return;
	}
	else {
		getCase(node, p, g, u);
	}
}

int Tree::getCase(Node* node, Node* p, Node* g, Node* u) {
	if (p->color != 1 || node != root) {
		if (u->color == 2) {
			p->color = 1;
			u->color = 1;
			// Color of grandparent to red
			g->color = 2;
			setFam(g); 
		}
		else {
			// Left left case
			if (g->left != NULL && p->left != NULL 
			&& g->left == p && p->left == node) {
					lLeft(node, p, g, u);
			}
			//Left right case
			if (g->left != NULL && p->right != NULL 
			&& g->left == p && p->right == node) {
				lRight(node, p, g, u);
			}
			//Right right case
			if (g->right != NULL && p->right != NULL 
			&& g->right == p && p->right == node) {
				rRight(node, p, g, u);
			}
			// Right left case
			if (g->right != NULL && p->left != NULL 
			&& g->right == p && p->left == node) {
				rLeft(node, p, g, u);
			}
		}
	}
}

void Tree::lLeft(Node* node, Node* p, Node* g, Node* u) {
	// Left Left

	// Right rotate g
	std::cout << "Rr case" << std::endl;
	if (p->right != NULL) {
		g->left = p->right;
	}
	else {
		g->left == NULL;
	}
	p->right = g;
	if (g->parent != NULL) {
		if (g->parent->left != NULL) {
			if (g->parent->left == g) {
				g->parent->left = p;
				p->parent = g->parent;
			}
		}
		else {
			g->parent->right = p;
			p->parent = g->parent;
		}
	}
	if (g == root) {
		root = p;
	}
	g->parent = p;
	// Swap colors of g and parent
	int gcolor = g->color;
	g->color = p->color;
	p->color = gcolor;	
	std::cout << "G color: " << g->color << std::endl << "P color: " << p->color << std::endl;
}

void Tree::lRight(Node* node, Node* p, Node* g, Node* u) {
	// Left Right

	// Left rotate parent
	std::cout << "Lr case" << std::endl;
	g->left = node;
	p->parent = node;
	if (node->left != NULL) {
		p->right = node->left;
	}
	else {
		p->right = NULL;
	}
	node->left = p;
	p = g;
	// Apply left left case
	lLeft(node, p, g, u);
}

void Tree::rRight(Node* node, Node* p, Node* g, Node* u) {
	// Right Right
	
	// Left rotate g
	std::cout << "Rr case" << std::endl;
	if (p->left != NULL) {
		g->right = p->left;
	}
	else {
		g->right = NULL;
	}
	p->left = g;
	if (g->parent != NULL) {
		if (g->parent->left != NULL && g->parent->left == g) {
			g->parent->left = p;
		}
		else {
			g->parent->right = p;
		}
	}
	else {
		p->parent = NULL;
	}
	p->parent = g->parent;
	g->parent = p;
	if (g == root) {
		root = p;
	}
	// Swap color of g and p
	int gcolor = g->color;
	g->color = p->color;
	p->color = gcolor;
	std::cout << "G color: " << g->color << std::endl << "P color: " << p->color << std::endl;
}

void Tree::rLeft(Node* node, Node* p, Node* g, Node* u) {
	// Right Left
	
	// Right rotate p
	std::cout << "Rl case" << std::endl;
	g->right = node;
	if (node->right != NULL) {
		p->left = node->right;
	}
	else {
		p->left = NULL;
	}
	p = g;
	p->parent = node;
	// Apply right right case
	rRight(node, p, g, u);
}

/*
void Tree::reColor(Node* node, Node* p, Node* g, Node* u) {
	// Saved pointers
	Node* g = NULL;
	Node* u = NULL;
	Node* p = NULL;
	
	// Sets grandparent of node as node
	if (node->parent != NULL && node->parent->parent != NULL) {
		g = node->parent->parent;
	}
	// Sets u of node as node
	if (node->parent != NULL && node->parent->parent != NULL && node->parent->parent->left != NULL) {
		if (node->parent->parent->left == node->parent) {
			if (node->parent->parent->right != NULL) {
				u = node->parent->parent->right;
			}
		}
	}
	if (node->parent != NULL && node->parent->parent != NULL && node->parent->parent->right != NULL) {
		if (node->parent->parent->right == node->parent) {
			if (node->parent->parent->left != NULL) {
				u = node->parent->parent->left;
			}
		}
	}
	if (node->parent != NULL) {
		p = node->parent;
	}
	//if (node->parent != NULL) {
		// If parent of new node's color is not black or new node is not root
		if (node->parent->color != 1) {
		// If new node's u is red
			//if (u != NULL) {
				if (u->color == 2) {
					// Change color of parent and u to black
					node->parent->color = 1;
					u->color = 1;
					// Color of grandparent to red
					g->color = 2;
					// New node's 
					//if (g != NULL) {
						setFam(g); // do set fam or whatever ***********************
					//}
				}
			//}
		// If new node's u is black
			//if (u != NULL) {
				if (u->color == 1) {
					// Left left case
					if (g->left != NULL && node->parent->left != NULL 
					&& g->left == node->parent && p->left == node) {
							lLeft(node, p, g, u);
					}
					//Left right case
					if (g->left != NULL && node->parent->right != NULL 
					&& g->left == node->parent && node->parent->right == node) {
						lRight(node, p, g, u);
					}
					//Right right case
					if (g->right != NULL && node->parent->right != NULL 
					&& g->right == node->parent && node->parent->right == node) {
						rRight(node, p, g, u);
					}
					// Right left case
					if (g->right != NULL && node->parent->left != NULL 
					&& g->right == node->parent && node->parent->left == node) {
						rLeft(node, p, g, u);
					}
				}
			//}
		}
	//}
}
*/