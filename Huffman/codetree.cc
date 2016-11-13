#include "codetree.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std; 


void printChar(int ch) {
	if (ch < 16) {
		std::cout << "x0" << std::hex << ch;
	}
	else if (ch < 32 || ch > 126) {
		std::cout << "x" << std::hex << ch;
	}
	else {
		std::cout << "\"" << (char)ch << "\"";
	}
}

// Constructor for CodeTree which populates the queue vector 
// with nodes according to the freq array given, then applies 
// the huffman algorithm to it until there is only a single node 
// remaining in the vector
CodeTree::CodeTree(int freq[]) {
	queue = new PQueue(freq); 

}

CodeTree::~CodeTree()
{
}

// Checks whether the char is somewhere in the tree rooted 
// at Node root
bool containsChar(Node* root, char c) {
	if (root->ch) return *(root->ch) == c; 
	return containsChar(root->left, c) || containsChar(root->right, c);  
}
	
// helper for getCode function
string getCodeHelper(Node* root, char c, string acc) {
	if (root->ch) return acc; 
	// check if it is in the left child 
	if (containsChar(root->left, c)) {
		acc += '0'; 
		return getCodeHelper(root->left, c, acc);
	}
	// Assume it is in the right child 
	else {
		acc += '1';
		return getCodeHelper(root->right, c, acc);
	}
}

// Gets the code associated with a char in the tree with 
// root at root. Returns -1 if the tree does not contain 
// the char
string CodeTree::getCode(Node* root, char c) {
	if (containsChar(root, c))
		return getCodeHelper(root, c, ""); 
	else 
		return ""; 
}

void CodeTree::printCodeHelper(Node* root, Node* current) {
	if (current == NULL) return;
	if (current->ch) {
		printChar((int)*(current->ch));
		cout << ":" << getCode(root, *(current->ch)) << endl;
	}
	printCodeHelper(root, current->left); 
	printCodeHelper(root, current->right); 
}

void CodeTree::printTree()
{
}
/*
void CodeTree::printCode()
{
	Node* n = queue->peekHighest();
	if (n != NULL)
		printCodeHelper(n, n); 
}
*/

void CodeTree::printCode()
{
	Node* n = queue->peekHighest(); 
	if (n != NULL) {
		int highestFreq = n->freq; 
		for (int i = highestFreq; i > 0; i--) {
			vector<Node*> nodes = queue->getNodesWithFrequency(i); 
			for (vector<Node*>::iterator it = nodes.begin(); it != nodes.end(); it++) {
				if ((*it)->ch) {
					printChar((int)*((*it)->ch));
					cout << ":" << getCode(n, *((*it)->ch)) << endl; 
				}
			}
		}
	}
}