#include "codetree.h"
#include <vector>

using std::vector;
class CodeTree {
	
	
	CodeTree::CodeTree(int freq[]) {
		int freqHeap[256]; 

		for (unsigned int i = 0; i < sizeof(freq) / sizeof(freq[0]); i++) {
			freqHeap[i] = freq[i]; 
		}

		heapify(freqHeap, 256); 

		for (unsigned int i = 0; i < sizeof(freq) / sizeof(freq[0]); i++) {
			Node* node = new Node; 
			node->freq = freq[i]; 
			
			characters.push_back(node);
			abc = 2; 
		}




	}

	int CodeTree::abcd() {

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
			std::swap(heap[i], heap[min]);
			swapDown(heap, min, size);
		}
	}

	//PRE:  The capacity of the array pointed to by heap is at least size.
	//POST: The first size elements of heap are a heap.
	void CodeTree::heapify(int* heap, int size) {
		for (int i = (size - 2) / 2; i >= 0; i--)
			swapDown(heap, i, size);
	}


	
};