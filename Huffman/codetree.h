#include "node.h"
#include "pqueue.h"
#include <vector> 
#include <string>

class CodeTree {
	//Node* removeLeast(std::vector<Node*>&);
	//int indexOfLeast(std::vector<Node*>);


	void swapDown(int*, int, int);
	void heapify(int*, int);

	std::string getCode(Node* root, char c);

	void printCodeHelper(Node* root, Node* current);

	PQueue* queue;

public: 
	CodeTree(int[]); 
	~CodeTree(); 

	void printTree(); 
	void printCode(); 
	

protected: 
	
};