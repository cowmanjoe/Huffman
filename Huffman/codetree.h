#include "node.h"
#include <vector> 

class CodeTree {

public: 
	CodeTree(int[]); 
	~CodeTree(); 

	void printTree(); 
	void printCode(); 
	

protected: 
	Node* removeLeast(std::vector<Node*>); 
	int indexOfLeast(std::vector<Node*>); 


	void swapDown(int*, int, int); 
	void heapify(int*, int); 

	std::vector<Node*> queue;
};