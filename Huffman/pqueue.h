#include "node.h"
#include <vector>

using namespace std; 

class PQueue {

	vector<Node*> nodes; 


	Node* removeLeast(std::vector<Node*>&);
	int indexOfLeast(std::vector<Node*>);

public:
	PQueue(int[]); 
	~PQueue(); 

	Node* peekHighest(); 
};