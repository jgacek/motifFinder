/*Main.cpp for CS 466 Final Project
Jacob Gacek
Matt Schuele
Danny Gross
*/

#include <vector>
#include <fstream>
#include <cstdio>
#include <cstdlib>
#include <iostream>


using namespace std;


int main (int argc, char * argv[]) {

	//run with ./overlap <correct overlaps.txt> <predicted overlaps.txt> 

	if (argc != 3) {
		cout << "bleh" << endl;
		return -1;
	}

	string correctSitesFilePath = argv[1];
	string predictedSitesFilePath = argv[2];

	ifstream correctSites;
	correctSites.open(correctSitesFilePath);

	if (!correctSites.is_open()) {

		cout << "bad path to correct sites file" << endl;
		return -1;
	}

	ifstream predictedSites;
	predictedSites.open(predictedSitesFilePath);

	if (!predictedSites.is_open()) {

		cout << "bad path to predicted sites file" << endl;
		return -1;

	}

	int readVal;

	vector<int> realVals;
	vector<int> predictedVals;

	while (correctSites >> readVal) {

		realVals.push_back(readVal);

	}

	correctSites.close();

	while (predictedSites >> readVal) {

		predictedVals.push_back(readVal);

	}

	predictedSites.close();

	int overlap_count = 0; 

	if (realVals.size() != predictedVals.size()) {

		cout << "data sizes did not match" << endl;
		return -1;
	}


	for (int i = 0; i < (int)realVals.size(); i++) {

		if (realVals[i] == predictedVals[i]){

			overlap_count++;

		}

	}

	ofstream output;
	output.open("data/overlap.txt");

	if (!output.is_open()) {


		cout << "Could not open output" << endl;
		return -1;

	}

	output << overlap_count;

	output.close();

	return 0;

}
