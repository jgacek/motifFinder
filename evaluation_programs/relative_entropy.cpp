#include <string>
#include <iostream>
#include <cstdlib>
#include <fstream>
#include <stdio.h>
#include <cmath>

using namespace std;

double qa;
double qc;
double qt;
double qg;
double total_information_content = 0.0;

int main( int argc, char * argv[] )
{
    // args: motif.txt predictedmotif.txt
    if( argc != 3 )
    {
        cout << "Usage: ./relative_entropy motif.txt predictedmotif.txt\n";
        exit(1);
    }

    // Calculate probabilities for each position
    ifstream motif ( argv[1] );
    if (!motif.is_open()) {cout << "Fail!" << endl;}
    ifstream predictedmotif ( argv[2] );
    if (!predictedmotif.is_open()) {cout << "Fail!" << endl;}

    string line_true;
    string line_predicted;
    double total_information_content = 0;

    while( getline( motif, line_true) && getline(predictedmotif, line_predicted))
    {

        int line_true_a = 0;
        int line_true_c = 0;
        int line_true_g = 0;
        int line_true_t = 0;

        int line_predicted_a = 0;
        int line_predicted_c = 0;
        int line_predicted_g = 0;
        int line_predicted_t = 0;

            // Ignore first and last line
        if( line_true.at(0) != '>' && line_true.at(0) != '<' && line_predicted.at(0) != '>' && line_predicted.at(0) != '<')
        {   
            // 0 = A, 1 = C, 2 = G, 3 = T
            int val_id_true = 0;
            int val_id_predict = 0;
            int total_true = 0;
            int total_predicted = 0;
            double qa, qg, qt, qc;
            double wa, wg, wt, wc;
            for(int i = 0; i < (int) line_true.size(); i++)
            {
                string val;
                while( line_true.at(i) != '\t' )
                {
                    val = val + line_true.at(i);
                    i++;
                }

                size_t s;
                int _val = stoi( val, &s );

                if( val_id_true == 0 )
                {
                    line_true_a += _val;
                }
                else if( val_id_true == 1 )
                {
                    line_true_c += _val;
                }
                else if( val_id_true == 2 )
                {
                    line_true_g += _val;
                }
                else if( val_id_true == 3 )
                {
                    line_true_t += _val;
                }

                total_true += _val;

                val_id_true++;

            }

            for(int i = 0; i < (int) line_predicted.size(); i++)
            {
                string val;
                while( line_predicted.at(i) != '\t' )
                {
                    val = val + line_predicted.at(i);
                    i++;
                }

                size_t s;
                int _val = stoi( val, &s );
               
                if( val_id_predict == 0 )
                {
                    line_predicted_a += _val;
                }
                else if( val_id_predict == 1 )
                {
                    line_predicted_c += _val;
                }
                else if( val_id_predict == 2 )
                {
                    line_predicted_g += _val;
                }
                else if( val_id_predict == 3 )
                {
                    line_predicted_t += _val;
                }

                total_predicted += _val;

                val_id_predict++;

            }


            qa = (double) line_true_a / total_true;
            qc = (double) line_true_c / total_true;
            qg = (double) line_true_g / total_true;
            qt = (double) line_true_t / total_true;

            wa =  (double) line_predicted_a / (double) total_predicted;
            wc = (double) line_predicted_c / (double) total_predicted;
            wg = (double) line_predicted_g / (double) total_predicted;
            wt = (double) line_predicted_t / (double) total_predicted;
            
            double line_information_content = 0.0;

            if( wa != 0 )
            {
                line_information_content += wa * log2( wa / qa );
            }
            if( wc != 0 )
            {
                line_information_content += wc * log2( wc / qc );
            }
            if( wg != 0 )
            {
                line_information_content += wg * log2( wg / qg );
            }
            if( wt != 0 )
            {
                line_information_content += wt * log2( wt / qt );
            }

            total_information_content += line_information_content;

        }

    }

    motif.close();
    predictedmotif.close();

    ofstream output;
    output.open("data/relative_entropy.txt");

    output << "Relative entropy: " << total_information_content << "\n";

    output.close();

    return 0;
}
