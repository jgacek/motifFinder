/*Main.cpp for CS 466 Final Project
Jacob Gacek
Matt Schuele
Danny Gross
*/

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <vector>

#include "data_generator.h"


int main(int argc, char* argv[]){

	if(argc != 5){
		cout<<"./generate <ICPC> <ML> <SL> <SC>"<<endl;
		return - 1;
	}

	srand(time(NULL));

	float ICPC = atof(argv[1]);
	if(ICPC != 1 && ICPC != 1.5 && ICPC != 2){
		cout <<"Enter 1, 1.5, or 2 for ICPC"<<endl;
		return -1;
	}
	int ML = atoi(argv[2]);
	int SL = atoi(argv[3]);
	int SC = atoi(argv[4]);
	
	/*Step 2*/
	vector <string> sequences(SC);
	for(int i=0;i<SC;i++){
		MotifGenerator::generateSequence(sequences[i], SL);
	}
	/**for(int i=0;i<SC;i++){
		cout<<sequences[i]<<endl;
	}*/

	/*Step 3.1: Choose a p given your IPCP value*/
	/*Note: Following values taken from forum post by the TA*/
	
	/*creating a motif matrix of appropriate size and fill it with 0's*/
	vector<vector<int> > motif(ML, vector<int>(4));

	float p;
	if(ICPC == 1){
		p = 0.8105;
	}
	else if(ICPC == 1.5){
		p = 0.9245;
	}
	else{
		p = 1;
	}

	for(int i=0;i<ML;i++){
		motif[i] = MotifGenerator::generateMotif(p,SC);
		for(int j=0;j<4;j++){
			cout<<motif[i][j]<<"\t";
		}
		cout<<endl;
	}

	// Generate SC binding sites using motif
	vector<string> binding_sites (SC);
	for(int i = 0; i < SC; i++)
	{
		binding_sites[i] = MotifGenerator::generateBindingSite( motif, ML, SC );
	}

	// Plant binding sites in sequences
	vector<int> sites (SC);

	for(int i = 0; i < SC; i++)
	{
		MotifGenerator::plantBindingSites(sequences[i], binding_sites[i], SL, i, sites);
	}

	// Write sequences to FASTA file
	MotifGenerator::writeSequencesToFasta( SC, sequences );

	// Write site locations to file name "sites.txt"
	MotifGenerator::writeSitesToFile( sites, SC );

	// Write motif to file
	MotifGenerator::writeMotifToFile( motif, ML );

	// Write motif length to file
	MotifGenerator::writeToMotifLengthToFile( ML );

	
	return 0; //this value was too high before 
}
