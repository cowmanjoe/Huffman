#include "node.h"
#include <vector> 

class CodeTree {

public: 
	CodeTree(int[]); 
	~CodeTree(); 

	void printTree(); 
	void printCode(); 
	

protected: 

	void swapDown(int*, int, int); 
	void heapify(int*, int); 

	std::vector<Node*> queue;
};