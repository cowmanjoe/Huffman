#include "node.h"
#include <vector> 
#include <string>

class CodeTree {

public: 
	CodeTree(int[]); 
	~CodeTree(); 

	void printTree(); 
	void printCode(); 
	

protected: 
	Node* removeLeast(std::vector<Node*>&); 
	int indexOfLeast(std::vector<Node*>); 


	void swapDown(int*, int, int); 
	void heapify(int*, int); 

	std::string getCode(Node* root, char c); 

	

	std::vector<Node*> queue;
};