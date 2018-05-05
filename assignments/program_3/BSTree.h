#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <vector>

using namespace std;

struct bNode
{
	string data;
	bNode *left;
	bNode *right;
	bNode()
	{
		data = "";
		left = NULL;
		right = NULL;
	}
	bNode(string w)
	{
		data = w;
		left = NULL;
		right = NULL;
	}
};

class BSTree
{
private:
	bNode *root;
	int count(bNode *root);
	void insert(bNode *&root, bNode *&temp);
	void print_bNode(bNode *n, string label = "");
	bNode *minValuebNode(bNode *root);
	bNode *deletebNode(bNode *&root, string key);
	int height(bNode *root);
	void printGivenLevel(bNode *root, int level);
	void GraphVizGetIds(bNode *bNodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(bNode *bNodePtr, ofstream &VizOut);
public:
	BSTree();
	~BSTree();
	int count();
	void insert(string x);
	void deletebNode(string key);
	void minValue();
	int height(string key = "");
	string top();
	void printLevelOrder();
	void GraphVizOut(string filename);
};
