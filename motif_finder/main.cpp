/*Main.cpp for CS 466 Final Project
Jacob Gacek
Matt Schuele
Danny Gross
*/

#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <cstdio>
#include <vector>
#include <unistd.h>
#include <time.h>
#include <sys/time.h>

#include "motif_finder.h"


int main(int argc,char* argv[]){

	//Not sure exactly how we want to pass in the argument but for now I 
	//am going to make it where you pass in the path from this directory
	//to the directory the data is located in
	if(argc != 2){
		cout<<"./find <path_to_data_directory>"<<endl;
		cout<<"type path as: '../data_sets/data_set_XX' where XX is an integer"<<endl; 
		return -1;
	}

	char* path = argv[1];
	if(chdir(path) == -1){
		cout<<"Failed to change current working directory to "<<path<<endl;
		return -1;
	}
	
	/**
	 * Create file stream to read from sequences.fa. If line starts with '>'
	 * ignore and go to next line. Add each DNA sequence to string vector 
	 * of sequences.
	 */
	
	ifstream se;
	se.open("sequences.fa",fstream::in);
	vector <string> sequences;
	string line;
	while(getline(se,line)){
		if(line[0] != '>'){
			sequences.push_back(line);
		}
	}
	se.close();

	/*Open up the motiflength.txt file to read*/
	se.open("motiflength.txt",fstream::in);
	getline(se,line);
	int ML = atoi(line.c_str());
	se.close();
	
	timespec endTime;
	timespec startTime;

	//This will not compile on versions of OS X < 10.12
	
	clock_gettime(CLOCK_MONOTONIC,&startTime);
	vector<int> motifSites = MotifFinder::findMotifSites(sequences,ML);
	clock_gettime(CLOCK_MONOTONIC,&endTime);
	double seconds = (endTime.tv_sec+(endTime.tv_nsec)*(1.0e-9)) - 
			 (startTime.tv_sec+(startTime.tv_nsec)*(1.0e-9));

	vector<vector<int> >motif = MotifFinder::generateMotifFromPositions(motifSites,ML,sequences.size(),sequences);	
	
	//Go back to directory where this main.cpp is found
	if(chdir("../../motif_finder/predicted_data_sets") == -1){
		cout<<"Failed to change current working directory to predicted_data_sets"<<endl;
		return -1;
	}
	
	int SC = sequences.size();
	MotifFinder::writeSitesToFile(motifSites,SC);

	MotifFinder::writeMotifToFile(motif,ML);

	MotifFinder::writeRunningTimeToFile(seconds);

	return 0; //His days of getting high are over
}
