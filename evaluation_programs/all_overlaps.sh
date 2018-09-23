#!/bin/bash
# Script to generate all overlaps.txt files

mkdir "../evaluation_data_uncombined/overlaps/"

for i in {1..70}
do
	./overlap "../data_sets/data_set_${i}/sites.txt" "../predicted_data_sets/predicted_set_${i}/predictedsites.txt"
	cp -R data/overlap.txt "../evaluation_data_uncombined/overlaps/overlap${i}.txt"
done