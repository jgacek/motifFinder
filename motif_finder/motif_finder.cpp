#include "motif_finder.h"

int printNumbers=0;

void MotifFinder::writeRunningTimeToFile(double seconds){

	ofstream my_file;
	my_file.open("runningtime.txt");

	if(!my_file.is_open()){ cout<<"Failed to open runningtime.txt"; exit(1); }
	my_file<<seconds<<" seconds";

	my_file.close();

}

void MotifFinder::writeSitesToFile(const vector<int> & sites,int SC){
	
	ofstream my_file;
	my_file.open("predictedsites.txt");

	if(!my_file.is_open()){ cout<<"Failed to open sites.txt"; exit(1); }

	for(int i=0;i<SC;i++){
		my_file << sites[i] <<"\n";
	}

	my_file.close();
}

void MotifFinder::writeMotifToFile(vector<vector<int> >motif,int ML){
	
	ofstream my_file;
	my_file.open("predictedmotif.txt");
	
	if(!my_file.is_open()){ cout<<"Failed to open predictedmotifs.txt";exit(1); }

	my_file<<">MOTIF\t"<<ML<<endl;
	for(int i=0;i<ML;i++){
		for(int j=0;j<4;j++){
			my_file<<motif[i][j]<<"\t";
		}
		my_file<<"\n";
	}

	my_file<<"<";
	my_file.close();
}

/**
 * Given some positions and DNA sequences it will assign it a score based on 
 * the motif finding slides
 *
 * @param motif
 *    a vector of vectors of ints that represent what we are trying to score
 * 
 * @param rows
 *    the number of rows you want to score (the letter k from slides)
 *
 * @return score
 *    The score of the matrix
 */
float MotifFinder::motifScore(vector<vector<int> > & motif,int ML){
	
	//Useful number for figuring out percentages later	
	float total = 0.0;
	for(int i=0;i<4;i++){
		total += motif[0][i];
	}
	
	float result = 0.0;
	float background = 0.25;
	/**if(printNumbers){
		for(int i=0;i<ML;i++){
			for(int j=0;j<4;j++){
				cout<<motif[i][j]<<'\t';
			}
			cout<<endl;
		}
		cout<<endl;
	}*/
	for(int i=0;i<ML;i++){
		for(int j=0;j<4;j++){
			float percentage = (((float)motif[i][j])/total);
			if(percentage == 0.0){/*Or else log2 will return inf*/
				continue;
			}
			float log = log2(percentage/background);
			/**if(printNumbers){
				cout<<"percentage: "<<percentage<<endl;
				cout<<"log: "<<log<<endl;
				cout<<percentage*log<<endl;
			}*/
			result = result + (float)(percentage*log);
		}
	}
	//if(printNumbers){printNumbers=0;}
	//cout<<"result is: "<<result<<endl;
	return result;
}

/**
 * This function is used to create a motif given a position matrix
 *
 * @param sequences
 *    The starting position at each DNA sequence
 *
 * @param ML
 *    The length of motif we desire to make
 *
 * @param amount
 *    The amount of sequences from the sequences vector we wish to load into 
 *    the motif
 * 
 * @param sequences
 *    The set of DNA sequences we are using
 *
 * @return motif
 *    A vector of vectors of ints represeting the motif
 */
vector<vector<int> > MotifFinder::generateMotifFromPositions(vector<int> & positions,int ML,int amount,const vector<string> &sequences)
{
	vector<vector<int> >motif(ML,vector<int>(4));
	for(int i=0;i<ML;i++){
		for(int j=0;j<4;j++){
			motif[i][j]=0;
		}
	}

	for(int i=0;i<amount;i++){
		int position = positions[i];
		string fullString = sequences[i];
		string subSeq = fullString.substr(position,ML);
		for(int j=0;j<ML;j++){
			if(subSeq[j] == 'A'){
				motif[j][0]++;
			}
			else if(subSeq[j] == 'C'){
				motif[j][1]++;
			}
			else if(subSeq[j] == 'G'){
				motif[j][2]++;
			}
			else if(subSeq[j] == 'T'){
				motif[j][3]++;
			}
			else{
				cout<<"current character was not any of A,C,G,T"<<endl;
			}
		}
	}
	return motif;
}

/**
 * The bread and butter of out greedy algorithm
 * 
 * @param sequences
 *    A vector of strings where each element represents a DNA sequence
 *
 * @param ML
 *    The length of the desired motif we are trying to find
 *
 * @return
 *    A vector of ints that represents the position of the first character
 *    where the motif is found in every sequence. This will be useful for out
 *    predictedSites.txt file
 */

vector<int> MotifFinder::findMotifSites(vector<string> & sequences,int ML)
{
	int numberOfSequences = sequences.size();
	vector<vector<int> >bestSites(1);
	bestSites[0] = vector<int>(numberOfSequences);
	for(int i=0;i<numberOfSequences;i++){
		bestSites[0][i]=0;
	}
	vector<vector<int> >bestMotif = generateMotifFromPositions(bestSites[0],ML,2,sequences);

	vector<int>currentSites(numberOfSequences);
	for(int i=0;i<numberOfSequences;i++){
		currentSites[i]=0;
	}

	//Get the length of the DNA sequences
	int sequenceLength = sequences[0].size();

	//This outer for loop iterates through ever k-mer in the first sequence
	for(int i = 0;i<(sequenceLength-ML+1);i++){
		currentSites[0] = i;
		//Iterates through every k-mer in the second sequence
		for(int j = 0;j<(sequenceLength-ML+1);j++){
			currentSites[1] = j;
			//cout<<"we are at "<<currentSites[1]<<endl;
			vector<vector<int> >tryMotif = generateMotifFromPositions(currentSites,ML,2,sequences);
			if(motifScore(tryMotif,ML) > motifScore(bestMotif,ML)){
				bestSites.resize(1);
				bestSites[0][0] = i;
				bestSites[0][1] = j;
				bestMotif = generateMotifFromPositions(bestSites[0],ML,2,sequences);
			}
			else if(motifScore(tryMotif,ML) == motifScore(bestMotif,ML)){
				bestSites.push_back(vector<int>(numberOfSequences));
				bestSites[bestSites.size()-1][0] = i;
				bestSites[bestSites.size()-1][1] = j;
				//cout<<i<<" "<<j<<" stored at position "<<bestSites.size()-1<<endl;
			}
			else{/*do nothing*/}
		}
	}
	currentSites[0] = bestSites[0][0];
	currentSites[1] = bestSites[0][1];
	//Now we must iterate through the rest of the rows
	for(size_t k=0;k<bestSites.size();k++){
		currentSites[0] = bestSites[k][0];
		currentSites[1] = bestSites[k][1];
		for(int i=2;i<numberOfSequences;i++){
			bestMotif = generateMotifFromPositions(bestSites[k],ML,i+1,sequences);
			for(int j=0;j<(sequenceLength-ML+1);j++){
				currentSites[i] = j;
				vector<vector<int> >tryMotif = generateMotifFromPositions(currentSites,ML,i+1,sequences);
				if(motifScore(tryMotif,ML) >= motifScore(bestMotif,ML)){
					bestSites[k][i] = j;
					bestMotif = generateMotifFromPositions(bestSites[k],ML,i+1,sequences);
				}
			}
			currentSites[i] = bestSites[k][i];
		}
	}
	float bestOfTheBest=0.0;
	int bestPosition=0;
	for(size_t i=0;i<bestSites.size();i++){
		bestMotif = generateMotifFromPositions(bestSites[i],ML,numberOfSequences,sequences);
		float thisScore = motifScore(bestMotif,ML);
		if(thisScore > bestOfTheBest){
			bestOfTheBest = thisScore;
			bestPosition = i;
		}
	}
	
	return bestSites[bestPosition];
}


