#include "data_generator.h"

/**
 * Function call to generate a random DNA sequence
 * 
 * @param sequence
 *    A pointer to an empty string we will store our sequence
 * 
 * @param length
 *    The desired length of our randomly generated sequence
 */
void MotifGenerator::generateSequence(string & sequence, int length){
	for(int i=0;i<length;i++){
		int random_var = (rand()%4);
		switch(random_var){
			case 0:
				sequence.push_back('A');
				break;
			case 1:
				sequence.push_back('C');
				break;
			case 2:
				sequence.push_back('G');
				break;
			case 3:
				sequence.push_back('T');
				break;
			default:
				cout<<"We are in the default case"<<endl;
				cout<<"Exiting program"<<endl;
				exit(1);
		}
	}
}

/**
 * Call this funciton to create a PWM that will represent a given motif
 *
 *
 */

vector<int> MotifGenerator::generateMotif(float p,int sequenceCount){
	vector<int> result (4);
	for(int i=0;i<4;i++){
		result[i] = 0;
	}
	int preferredPosition;
	int unpreferredOne;
	int unpreferredTwo;
	int unpreferredThree;
	/*Choose a preferred nucleotide*/
	/**for(int i=0;i<sequenceCount;i++){
		int randomVar = (rand()%4);
		result[randomVar]++;
	}*/
	int randomVar = (rand()%4);
	switch(randomVar){
		case 0:
			//Charater 'A' will be preffered
			preferredPosition = 0;
			unpreferredOne = 1;
			unpreferredTwo = 2;
			unpreferredThree = 3;
			break;
		case 1:
			//Character 'C' will be preferred
			preferredPosition = 1;
			unpreferredOne = 2;
			unpreferredTwo = 3;
			unpreferredThree = 0;
			break;
		case 2:
			//Character 'G' will be preferred
			preferredPosition = 2;
			unpreferredOne = 3;
			unpreferredTwo = 0;
			unpreferredThree = 1;
			break;
		case 3:
			//Character 'T' will be preferred
			preferredPosition = 3;
			unpreferredOne = 0;
			unpreferredTwo = 1;
			unpreferredThree = 2;
			break;
		default:
			cout<<"generateMotif default case"<<endl;
			cout<<"exiting program"<<endl;
			exit(1);
	}
	/*After picking out the preferred characters, we can start to fill*/
	/*our matrix up with the preferref character apperaing more than the*/
	/*others in each row*/
	//cout<<"preferred position is "<<preferredPosition<<endl;
	for(int i=0;i<sequenceCount;i++){
		randomVar = (rand()%10000);
		if(randomVar < (p*10000)){
			result[preferredPosition]++;
		}
		else{
			randomVar = rand()%3;
			//cout<<"incrementing position "<<randomVar<<endl;
			switch(randomVar){
				case 0:
					result[unpreferredOne]++;
					break;
				case 1:
					result[unpreferredTwo]++;
					break;
				case 2:
					result[unpreferredThree]++;
					break;
				default:
					cout<<"should not be here"<<endl;
					exit(1);
			}
		}
	}
	
	return result;
}

/**
*	Function that generates a binding site given a motif
*
*	@param motif
*		A pointer to previously generated random motif
*
*	@param ML
*		integer motif length
*
*	@param SC
*		integer sequence count
*/
string MotifGenerator::generateBindingSite( vector<vector<int> > & motif, int ML, int SC )
{
	string binding_site;
	for(int i = 0; i < ML; i++)
	{
		int random_var = rand() % SC;
		// Set up ranges for random assignment
		int A_lim = motif[i][0];
		int C_lim = A_lim + motif[i][1];
		int G_lim = C_lim + motif[i][2];
		int T_lim = G_lim + motif[i][3];

		if( random_var >= 0 && random_var < A_lim )
		{
			binding_site.push_back('A');
		}
		else if( random_var >= A_lim && random_var < C_lim )
		{
			binding_site.push_back('C');
		}
		else if( random_var >= C_lim && random_var < G_lim )
		{
			binding_site.push_back('G');
		}
		else if( random_var >= G_lim && random_var < T_lim )
		{
			binding_site.push_back('T');
		}
		else
		{
			cout << "Error with motif" << endl;
			exit(1);
		}
	}

	cout << "Site: " << binding_site << endl;
	return binding_site;
}

/**
*	Function that plants a randomly generated binding site into a sequence
*
*	@param sequence
*		Previously genereted string pointer to sequence
*
*	@param binding_site
*		Previously genereted string pointer to binding site
*
*	@param SL
*		integer sequence length
*
*	@param pos
*		integer position of current sequence in sequences array
*
*	@param sites[]
*		int array of randomly chosen sites
*/
void MotifGenerator::plantBindingSites( string & sequence, string binding_site, int SL, int pos, vector<int> & sites)
{
	size_t rand_start_pos = rand() % ( SL - binding_site.size() + 1 );
	sites[pos] = rand_start_pos;
	sequence.replace( rand_start_pos, (size_t) binding_site.size(), binding_site );
}


/**
*	Function to write the SC generated sequences to a FASTA file
*
*	@param SC
*		integer sequence count
*
*	@param sequences
*		string array of sequence to be written to FASTA file
*/
void MotifGenerator::writeSequencesToFasta( int SC, const vector<string> &  sequences)
{
	// File name: "sequences.fa"
	ofstream my_file;
	my_file.open("data_set/sequences.fa");

	if (!my_file.is_open()) { cout << "Failed to open sequences.fa"; exit(1); }

	for(int i = 0; i < SC; i++)
	{
		my_file << ">seq" << i << "\n" << sequences[i] << "\n";
	}

	my_file.close();
}

/**
*	Function to write location of randomly placed binding sites to file
*
*	FORMAT: each line corresponding to sequence number n will have site start location
*		Ex: (line 0): 2
*			(line 1): 4
*			...
*			(line n): 3
*
*	@param sites[]
*		integer array with site locations
*
*	@param SC
*		integer sequence count
*/
void MotifGenerator::writeSitesToFile(const vector<int> & sites, int SC )
{
	ofstream my_file;
	my_file.open("data_set/sites.txt");

	if (!my_file.is_open()) { cout << "Failed to open sites.txt"; exit(1); }

	for(int i = 0; i < SC; i++)
	{
		my_file << sites[i] << "\n";
	}

	my_file.close();
}

void MotifGenerator::writeMotifToFile(vector<vector<int> > motif, int ML )
{
	ofstream my_file;
	my_file.open( "data_set/motif.txt" );
	my_file << ">MOTIF\t" << ML << endl;
	for(int i = 0; i < ML; i++)
	{
		for(int j = 0; j < 4; j++)
		{
			my_file << motif[i][j] << "\t";
		}

		my_file << "\n";
	}

	my_file << "<";
	my_file.close();
}

void MotifGenerator::writeToMotifLengthToFile( int ML )
{
	ofstream my_file;
	my_file.open( "data_set/motiflength.txt" );
	my_file << ML;
	my_file.close();
}
