#include "codetree.h"
#include <vector>

using namespace std; 
	
	
CodeTree::CodeTree(int freq[]) {
	vector<Node*> characters;

	// Insert nodes with corresponding frequencies into characters vector
	for (unsigned int i = 0; i < sizeof(freq) / sizeof(freq[0]); i++) {
		Node* node = new Node; 
		node->freq = freq[i]; 
		char* c = new char; 
		*c = (char)i; 
		node->ch = c; 
		characters.push_back(node);
	}

	while (characters.size() > 1) {
		int li = indexOfLeast(characters);
		// TODO: erase least 2 elements
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
int indexOfLeast(vector<Node*> nodes) {
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

	
	
