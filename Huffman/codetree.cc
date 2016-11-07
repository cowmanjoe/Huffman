#include "codetree.h"
#include <iostream>
#include <vector>

using namespace std; 
	
	
CodeTree::CodeTree(int freq[]) {

	for (int i = 0; i < 256; i++) {
		cout << "freq[" << i << "] = " << freq[i] << "ch = " << (char) i << endl; 
	}

	// Insert nodes with corresponding frequencies into queue vector
	for (int i = 0; i < 256; i++) {
		if (freq[i] > 0) {
			Node* node = new Node; 
			node->freq = freq[i]; 
			char* c = new char; 
			char x = (char) i;
			*c = x; 
			node->ch = c; 
			queue.push_back(node);
			cout << "Pushed node with frequency " << node->freq << " and char " << *(node->ch) << endl; 
		}
	}

	while (queue.size() > 1) {
		Node* a = removeLeast(queue); 
		Node* b = removeLeast(queue); 
		//cout << "removed node a with ch = " << *(a->ch) << " and b with ch = " << *(b->ch) << endl; 


		Node* p = new Node; 
		p->freq = a->freq + b->freq; 
		p->left = a; 
		p->right = b; 
		queue.push_back(p); 
		cout << "Added node with frequency " << p->freq << endl; //" with p->left->ch = " << *(a->ch) << " and p->right->ch = " << *(b->ch) << endl;
		
	}
	cout << "abcd\n"; 

	cout << "\"o\" = " << getCode(queue[0], 'o') << endl; 
	cout << "\"m\" = " << getCode(queue[0], 'm') << endl; 


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
Node* CodeTree::removeLeast(vector<Node*> & nodes) {
	int index = indexOfLeast(nodes); 
	cout << "index = " << index << endl; 
	cout << "nodes.size() before = " << nodes.size() << endl; 
	Node* n = new Node; 
	n->ch = nodes[index]->ch;
	n->freq = nodes[index]->freq; 
	n->left = nodes[index]->left;
	n->right = nodes[index]->right; 
	nodes.erase(nodes.begin() + index); 
	cout << "nodes.size() after = " << nodes.size() << endl; 
	return n; 
}
	
// Checks whether the char is somewhere in the tree rooted 
// at Node root
bool containsChar(Node* root, char c) {
	if (root->ch) return *(root->ch) == c; 
	return containsChar(root->left, c) || containsChar(root->right, c);  
}
	
// returns the code associated with a char on its final
// recursive call. Returns -1 if it fails to find the char
int getCodeHelper(Node* root, char c, int acc) {
	if (root->ch) return acc; 
	if (containsChar(root->left, c)) 
		return getCodeHelper(root->left, c, (acc << 1));
	if (containsChar(root->right, c))
		return getCodeHelper(root->right, c, (acc << 1) + 1); 
	else return -1; 
}

// Gets the code associated with a char in the tree with 
// root at root. Returns -1 if the tree does not contain 
// the char
int CodeTree::getCode(Node* root, char c) {
	if (containsChar(root, c))
		return getCodeHelper(root, c, 0); 
	else 
		return -1; 
}