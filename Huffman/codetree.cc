#include "codetree.h"
#include <iostream>
#include <vector>

using namespace std; 
	
	
CodeTree::CodeTree(int freq[]) {
	vector<Node*> characters;

	// Insert nodes with corresponding frequencies into characters vector
	for (unsigned int i = 0; i < 256; i++) {
		Node* node = new Node; 
		node->freq = freq[i]; 
		char* c = new char; 
		*c = (char)i; 
		node->ch = c; 
		characters.push_back(node);
		cout << "Pushed node with frequency " << node->freq << " and char " << *(node->ch) << endl; 
	}

	while (characters.size() > 1) {
		Node* a = removeLeast(characters); 
		Node* b = removeLeast(characters); 
		
		Node* p = new Node; 
		p->freq = a->freq + b->freq; 
		p->left = a; 
		p->right = b; 
		characters.push_back(p); 
		cout << "Added node with frequency " << p->freq << "with p->left->ch = " << *(a->ch) << " and p->right->ch = " << *(b->ch) << endl;
		
	}


}

CodeTree::~CodeTree()
{
}

void CodeTree::printTree()
{
}

void CodeTree::printCode()
{
}


// PRE:  subtrees rooted at leftChild and rightChild of i are heaps.
// POST: subtree rooted at i is a heap.
void CodeTree::swapDown(int* heap, int i, int size) {
	int leftChild = 2 * i + 1;
	int rightChild = 2 * i + 2;
	int min = i;
	// find who holds smallest element of i and its two children
	if (leftChild < size && heap[leftChild] < heap[min])
		min = leftChild;
	if (rightChild < size && heap[rightChild] < heap[min])
		min = rightChild;
	// if a child holds smallest element, swap i's element to that child
	// and recurse.
	if (min != i) {
		swap(heap[i], heap[min]);
		swapDown(heap, min, size);
	}
}

//PRE:  The capacity of the array pointed to by heap is at least size.
//POST: The first size elements of heap are a heap.
void CodeTree::heapify(int* heap, int size) {
	for (int i = (size - 2) / 2; i >= 0; i--)
		swapDown(heap, i, size);
}


// Finds the index of the node with the least frequency
int CodeTree::indexOfLeast(vector<Node*> nodes) {
	int index = 0; 
	// Set least to the frequency of the first element
	int least = nodes[0]->freq; 

	for (int i = 1; i < nodes.size(); i++) {
		if (nodes[i]->freq < least) {
			index = i; 
			least = nodes[i]->freq; 
		}
	}
	return index; 
}

// Removes the node in the vector with the least frequency 
// and returns a copy of it 
Node* CodeTree::removeLeast(vector<Node*> nodes) {
	int index = indexOfLeast(nodes); 
	Node* n = new Node; 
	n->ch = nodes[index]->ch;
	n->freq = nodes[index]->freq; 
	n->left = nodes[index]->left;
	n->right = nodes[index]->right; 
	nodes.erase(nodes.begin() + index); 
	return n; 
}
	
	
