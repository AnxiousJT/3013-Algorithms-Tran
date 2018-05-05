#include<iostream>
#include<fstream>
#include<string>
#include<vector>

#include"graph.h"

using namespace std;


void randomEdges(graph &g, int numEdges) {
	int r1, r2;
	latlon from;
	latlon to;
	double d;
	for (int i = 0; i<numEdges; i++) {
		r1 = rand() % g.vertexList.size();
		r2 = rand() % g.vertexList.size();
		from = g.vertexList[r1]->loc;
		to = g.vertexList[r2]->loc;
		d = distanceEarth(from.lat, from.lon, to.lat, to.lon);
		g.addEdge(r1, r2, (int)d, true);
	}
}



/**
* Function Name: initUSC (initial United States City)
*	Sets the first vertex to the initial United States city chosen. 
*	Choices are:
*	Lebanon, Kansas
*	Miami, Florida
*	Dallas, Texas
*	Boston Massachusetts
*	Portland, Oregon
*
*	Params: latlon ll, string c, string s
*
*	Returns: vertex*
*/
vertex* initUSC(latlon ll, string c, string s) {
	vertex* start = nullptr;
	




	return start;
}

/**
* Function Name: initPRC (initial Puerto Rico city)
*	Sets the first vertex to the initial Puerto Rico City. 
*	Use San Juan, Puerto Rico. Stay in Puerto Rico.
*
*	Params: latlon ll, string city, string state
*
*	Returns: vertex*
*/

vertex* initPRC(latlon, string city, string state) {
	vertex* start = nullptr;



	return start;
}


int main(int argc, char ** argv)
{
	ofstream output;
	output.open("results.txt");

	string city;
	string state;
	string county;
	int maxEdges = 3;
	int loop = 1;
	graph G;

	if (argc > 1 && argc < 3) 
	{
		state = argv[1];
	}
	else
	{
		cout << "./executablename state(All for each starting locations)" << endl;
		exit(0);
	}

	if (state == "All") 
	{
		loop = 6;
	}

	for (int l = 0; l < loop; l++) 
	{
		
		double distance = 0;
		int edges = 0;
		graph G;



		if (loop == 6) {
			if (l == 0)
				state = "KS";
			else if (l == 1)
				state = "FL";
			else if (l == 2)
				state = "TX";
			else if (l == 3)
				state = "MA";
			else if (l == 4)
				state = "PR";
		}


	}







	G = loadGraphCSV("filtered_cities.csv");

	G.printGraph();









	system("pause");
	return 0;
}
