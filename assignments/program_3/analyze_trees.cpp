#include<iostream>
#include<string>
#include<vector>
#include"avlTree.h"
//#include"bsTree.h"
#include"analyze_trees.h"

using namespace std;

void loadAVLTree(string filename){
	ifstream fin;
	fin.open(filename);

	avlTree A;

	string data;

	fin >> data;
	A.insert(data);
	while (!fin.eof()) {
		fin >> data;
		if (A.search(data)) {

		}
		else {
			A.insert(data);
		}
	}
}
