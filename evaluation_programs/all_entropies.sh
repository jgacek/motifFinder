#!/bin/bash
# Script to generate all relative_entropy.txt files

mkdir "../evaluation_data_uncombined/relative_entropies/"

for i in {1..70}
do
	./relative_entropy "../data_sets/data_set_${i}/motif.txt" "../predicted_data_sets/predicted_set_${i}/predictedmotif.txt"
	cp -R data/relative_entropy.txt "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
done