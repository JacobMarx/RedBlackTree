/*
	Created by Jacob Marx, 4/21/19.
	This program creates a red black tree you can
	add and delete nodes to.
*/

#include <iostream>
#include <cstring>
#include <fstream>
#include "Node.h"
#include "Tree.h"

bool getInput(Tree*, char*);
char* clear(char*);

void build();
void getInput(Tree*);
void enter(Tree* tree);
void help();

int main() {
	Tree* tree = new Tree();
	bool stop = false;
	
	while (stop == false) {
		//std::cout << "Would you like to input a file or through the console?" << std::endl;
		char* in = new char[20];
		clear(in);
		//std::cin >> in;
		if (tree->isempty() == true) {
			std::cout << "You do not have a tree would you like to create one? (yes or no)" << std::endl;
			std::cin >> in;
			if (strcmp(in, "yes") == 0) {
				enter(tree);
				clear(in);
				tree->display();
			}
		}
		else {
			std::cout << "Would you like to 'add', 'read', 'print', or 'quit'?" << std::endl;
			std::cin >> in;
			if (strcmp(in, "add") == 0) {
				getInput(tree);
				clear(in);
				tree->display();
			}
			/*
			else if (strcmp(in, "remove") == 0) {
				std::cout << "What number would you like to remove from the tree?" << std::endl;
				std::cin >> in;
				int input = 0;
				int index = 0;
				while (true) { // Gage did this
					char current = in[index++];
					if (current == '\0') {
						break;
					} else if (current == ',') {
						tree->push(input);
						input = 0;
						continue;
					}
					int digit = current - '0';
					input = input * 10 + digit;
				}
				tree->remove(input);
				clear(in);
			}
			*/
			else if (strcmp(in, "read") == 0) {
				clear(in);
				std::cout << "What is the name of the file?" << std::endl;
				std::cin >> in;
				getInput(tree, in);
			}
			else if (strcmp(in, "print") == 0) {
				tree->display(); 
				clear(in);
			}
			else if (strcmp(in, "quit") == 0) {
				stop = true;
				// Need to delete tree
				break;
			}
			else {
				std::cout << "You did not enter a valid input. If you would like help enter 'help'." 
				<< std::endl;
				std::cin >> in;
				if (strcmp(in, "help") == 0) {
					help();
				}
				else {
					continue;
				}
			}
		}
		
	}
	
	/*
	tree->push(12);
	tree->push(6);
	tree->push(3);
	tree->push(9);
	tree->push(16);
	tree->push(1);
	tree->push(45);
	tree->push(23);
	tree->push(34);
	tree->push(19);
	tree->push(4);
	tree->push(21);
	tree->push(25);
	tree->push(15);
	*/
	
	//tree->display();
	return 0;
}

void enter(Tree* tree) {
	char* in = new char[20];
	clear(in);
	std::cout << "Would you like to 'add' one number, or 'read' in from a file" << std::endl;
	std::cin >> in;
	if (strcmp(in, "add") == 0) {
		getInput(tree);
	}
	else if (strcmp(in, "read") == 0) {
		clear(in);
		std::cout << "What is the name of the file?" << std::endl;
		std::cin >> in;
		getInput(tree, in);
	}
}

void help() {
	std::cout << "********************HELP********************" << std::endl 
	<< std::endl << "COMMANDS:" << std::endl 
	<< "\t" << "'add' = Allows you to add to the tree." << std::endl 
	<< "\t" << "'read' = Insert numbers from a file into the tree." << std::endl 
	<< "\t" << "'print' = Visually print the tree." << std::endl 
	<< "\t" << "'quit' = Stops the program." << std::endl << std::endl
	<< "********************************************" << std::endl;
}

bool getInput(Tree* tree, char* fileName) {
	std::ifstream file;
	//std::cout << "goon" << std::endl;
	file.open(fileName);
	if (file.is_open()) {
		//char* in = new char[1000];
		char* in = new char[4000];
		int input = 0;
		int index = 0;
		//std::cout << file.get() << std::endl;
		//file.unget();
		file >> in;
		while (true) { // Gage did this
			char current = in[index++];
			if (current == '\0') {
				break;
			} else if (current == ',') {
				tree->push(input);
				//std::cout << "Input: " << input << std::endl;
				input = 0;
				continue;
			}
			int digit = current - '0';
			input = input * 10 + digit;
		}
		//std::cout << "Input: " << input << std::endl;
		if (input <= 1000 && input >= 1) {
			tree->push(input);
		}
		return true;
	}
	return false;
}

void getInput(Tree* tree) {
	while (true) {
		int input = 0;
		//std::cout << "ghflkfjlj\n";
		std::cout << "What value do you want to add?" << std::endl;
		std::cin >> input;
		if (input <= 1000 && input >= 1) {
			//std::cout << input << std::endl;
			tree->push(input);
			//std::cout << "goon\n";
		}
		//std::cin.unget();
		//std::cout << "Whitespace: " << int(std::cin.get()) << std::endl;
		//std::cin.unget();
		if (std::cin.get() == '\n' || std::cin.get() == ' ') {
			//std::cout << "hi\n";
			break;
		}
	}
	//std::cout << "Left function" << std::endl;
}

char* clear(char* arr) {
	for (int i = 0; i <= 20; i++) {
		arr[i] = '\0';
	}
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
	
	/*
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
	*/
	
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

