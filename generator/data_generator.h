#ifndef EMOTIF_H
#define EMOTIF_H

#include <string>
#include <iostream>
#include <ctime>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <vector>

using namespace std;

class MotifGenerator{
	public:
		static void generateSequence(string & sequence, int length); //pass by reference, not pointer
		static void  generateMotif(vector<vector<int> > ,float p);
		static vector<int>  generateMotif(float p,int sequenceCount);
		static string  generateBindingSite( vector<vector<int> > & motif, int ML, int SC );
		static void  plantBindingSites(string & sequence, string binding_site, int SL, int pos, vector<int> & sites);
		static void  writeSequencesToFasta( int SC, const vector<string> & sequences); /*this doesn't have to be const
		 or a reference, but it will run faster as a reference
		(since it is a complex object, not a simple type) and const is better style*/
		static void  writeSitesToFile(const vector<int> & sites, int SC );
		static void writeMotifToFile(vector<vector<int> > motif, int ML );
		static void writeToMotifLengthToFile( int ML );
	private:
};
#endif
