#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
#include"analyze_trees.cpp"

using namespace std;

//Use vector to hold the words read in
void loadVector(vector<string> & v, string filename) {
	ifstream fin;
	fin.open(filename);
	string word;
	while (!fin.eof()) {
		fin >> word;
		v.push_back(word);
	}
	fin.close();
}


//Randomly choose a file to get a word from and return it
string grabWord(vector<string> v1, vector<string> v2, vector<string> v3, vector<string> v4, vector<string>v5)
{
	int randomNum1 = (rand() % 5) + 1;//Randomly determine which file to pick from
	int randomNum2;//Randomly choose a word from the file chosen
	string data;//String received from the randomly chosen file

	if (randomNum1 == 1) {
		randomNum2 = rand() & v1.size();
		return data = v1[randomNum2];
	}
	else if (randomNum1 == 2) {
		randomNum2 = rand() % v2.size();
		return data = v2[randomNum2];
	}
	else if (randomNum1 == 3) {
		randomNum2 = rand() % v3.size();
		return data = v3[randomNum2];
	}
	else if (randomNum1 == 4) {
		randomNum2 = rand() % v4.size();
		return data = v4[randomNum2];
	}
	else {
		randomNum2 = rand() % v5.size();
		return data = v5[randomNum2];
	}
} 

//Use the grabWord function and create a line of words with 3, 4, or 5
//words on it and save the word into the tenthousandwords.txt file
void createWordLine(vector<string> v1, vector<string> v2, vector<string> v3, vector<string> v4, vector<string>v5, int n) {
	ofstream fout;
	fout.open("tenthousandwords.txt");
	vector<string> uniqueWords;

	if (!fout)
		cout << "Error!" << endl;

	string word;//String to hold the random word chosen

	int i = 0;
	while (i < n) {
		int numWords = (rand() % 5) + 3;//Each line will be 3-5 words

		if (numWords == 3)
		{
			for (int i = 1; i <= 3; i++) {
				word = grabWord(v1, v2, v3, v4, v5);
				if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
					uniqueWords.push_back(word);
					fout << word << " ";
				}
			}
		}
		else if (numWords == 4)
		{
			for (int i = 1; i <= 4; i++) {
				word = grabWord(v1, v2, v3, v4, v5);
				if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
					uniqueWords.push_back(word);
					fout << word << " ";
				}
			}
		}
		else
		{
			for (int i = 1; i <= 5; i++) {
				word = grabWord(v1, v2, v3, v4, v5);
				if (find(uniqueWords.begin(), uniqueWords.end(), word) == uniqueWords.end()) {
					uniqueWords.push_back(word);
					fout << word << " ";
				}
			}
		}
		fout << endl;
		i++;
	}
	fout.close();
}

int main() {
	srand(2342);

	//Vectors to hold the words being read in
	vector <string> adj;
	vector <string> adv;
	vector <string> ani;
	vector <string> nouns;
	vector <string> verbs;

	ifstream fin;
	string word;

	loadVector(adj, "adjectives.txt");
	loadVector(adv, "adverbs.txt");
	loadVector(ani, "animals.txt");
	loadVector(nouns, "nouns.txt");
	loadVector(verbs, "verbs.txt");


	//I should be 10000, but it will be a small number for testing purposes
	createWordLine(adj, adv, ani, nouns, verbs, 5);





	// Show a graphviz linked version of the tree. 
	//A.graphVizOut("avlTree_viz.txt");
	return 0;
}
