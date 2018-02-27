/*
@FileName: BSTree.h
@Author: Jackson Tran
@Description: This is a header file that implements a struct for creating
nodes to hold integers and also implements a class for creating a binary
search tree.
@Course: 3013 Agorithms
@Semester: Spring 2018
@Date: February 2018
*/


#pragma once
#include<iostream>
#include<string>
#include<fstream>

using namespace std;


//************************************************************************
// Creates nodes to hold data and be utilized in a Binary Search Tree(BST)
//************************************************************************
struct node
{
	int data;
	node *left;
	node *right;
	node()
	{
		data = -1;
		left = NULL;
		right = NULL;
	}
	node(int x)
	{
		data = x;
		left = NULL;
		right = NULL;
	}
};

//************************************************************************
// BST class with prototype methods
//************************************************************************
class BSTree
{
private:
	node * root;
	int count(node *);
	void insert(node *&root, node *&temp);
	void print_node(node *n, string label = "");
	node *minValueNode(node *root);
	node *deleteNode(node *&root, int key);
	int height(node *root);
	void printGivenLevel(node *root, int level);
	void GraphVizGetIds(node *nodePtr, ofstream &VizOut);
	void GraphVizMakeConnections(node *nodePtr, ofstream &VizOut);

public:
	BSTree();
	~BSTree();
	int count();
	void insert(int);
	void deleteNode(int);
	void minValue();
	int height(int);
	int top();
	void printLevelOrder();
	void GraphVizOut(string filename);
};

