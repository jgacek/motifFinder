#ifndef EFINDER_H
#define EFINDER_H

//includes
#include <iostream>
#include <string>
#include <vector>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <math.h>

using namespace std;

//Add on to .h file as we need to
class MotifFinder{
	public:
		static void writeRunningTimeToFile(double seconds);
		static void writeSitesToFile(const vector<int> &sites,int SC);
		static void writeMotifToFile(vector<vector<int> >motif,int ML);
		static float motifScore(vector<vector<int> > & motif,int rows);
		static vector<vector<int> >generateMotifFromPositions(vector<int> & positions,int ML,int amount,const vector<string> & sequences);
		static vector<int> findMotifSites(vector<string> &  sequences, int ML);

	private:
};
#endif
