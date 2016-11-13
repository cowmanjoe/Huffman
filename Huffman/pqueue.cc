#include "pqueue.h"
#include <iostream> 

using namespace std; 

PQueue::PQueue(int freq[]) {
	// Insert nodes with corresponding frequencies into queue vector
	for (int i = 0; i < 256; i++) {
		if (freq[i] > 0) {
			Node* node = new Node;
			node->freq = freq[i];
			char* c = new char;
			char x = (char)i;
			*c = x;
			node->ch = c;
			node->left = NULL;
			node->right = NULL;
			nodes.push_back(node);
			cout << "Pushed node with frequency " << node->freq << " and char " << *(node->ch) << endl;
		}
	}

	while (nodes.size() > 1) {
		Node* a = removeLeast();
		Node* b = removeLeast();
		//cout << "removed node a with ch = " << *(a->ch) << " and b with ch = " << *(b->ch) << endl; 


		Node* p = new Node;
		p->freq = a->freq + b->freq;
		p->ch = NULL;
		p->left = a;
		p->right = b;
		nodes.push_back(p);
		cout << "Added node with frequency " << p->freq << endl; //" with p->left->ch = " << *(a->ch) << " and p->right->ch = " << *(b->ch) << endl;

	}
}

Node* PQueue::peekHighest() {
	if (nodes.size() > 0) return nodes[0]; 
	return NULL; 
}


vector<Node*> getNodesHelper(int f, Node* node) {
	if (node != NULL) {
		vector<Node*> ans; 
		if (node->freq == f) { 
			ans.push_back(node); 
			return ans;
		}
		else if (node->freq > f) {
			vector<Node*> leftNodes = getNodesHelper(f, node->left); 
			vector<Node*> rightNodes = getNodesHelper(f, node->right); 
			ans.insert(ans.end(), leftNodes.begin(), leftNodes.end());
			ans.insert(ans.end(), rightNodes.begin(), rightNodes.end());
			return ans;
		}
	}
	return vector<Node*>(); 
}


// Returns a vector containing all the nodes with the given frequency
vector<Node*> PQueue::getNodesWithFrequency(int f) {
	if (nodes.size() > 0) {
		return getNodesHelper(f, nodes[0]); 
	}
	return vector<Node*>(); 
}


// Finds the index of the node with the least frequency
// REQUIRES: at least one node in the nodes vector
int PQueue::indexOfLeast() {
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
// REQUIRES: at least 1 node in the nodes vector
Node* PQueue::removeLeast() {
	int index = indexOfLeast();
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