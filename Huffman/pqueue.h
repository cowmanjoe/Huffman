#include "node.h"
#include <vector>

using namespace std; 

class PQueue {

	vector<Node*> nodes; 


	Node* removeLeast();
	int indexOfLeast();

public:
	PQueue(int[]); 
	~PQueue(); 

	vector<Node*> getNodesWithFrequency(int f); 

	Node* peekHighest(); 
};