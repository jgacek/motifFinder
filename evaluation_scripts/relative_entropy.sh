#!/bin/bash
# Script to merge together data based on parameters

#need to make the directory if it doesn't exist and delete the files if they do
mkdir "../evaluation_data_sets/relative_entropies/"
rm "../evaluation_data_sets/relative_entropies/IPC2.txt"
rm "../evaluation_data_sets/relative_entropies/ML8.txt"
rm "../evaluation_data_sets/relative_entropies/SC10.txt"
rm "../evaluation_data_sets/relative_entropies/IPC1_5.txt"
rm "../evaluation_data_sets/relative_entropies/IPC1.txt"
rm "../evaluation_data_sets/relative_entropies/ML6.txt"
rm "../evaluation_data_sets/relative_entropies/ML7.txt"
rm "../evaluation_data_sets/relative_entropies/SC5.txt"
rm "../evaluation_data_sets/relative_entropies/SC20.txt"

for i in {1..10}
do
	#IPC = 2, ML = 8, SC = 10 CASE (DEFAULT)
	#cat will create the file if it does not already exist
	#sed will add a new line if it doesn't exist to the input files
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/IPC2.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/ML8.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/SC10.txt"
done
for i in {11..20}
do 
	#IPC = 1.5 CASE
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/IPC1_5.txt"
done
for i in {21..30}
do
	#IPC = 1 CASE
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/IPC1.txt"
done
for i in {31..40}
do 
	#ML = 6 CASE
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/ML6.txt"
done
for i in {41..50}
do
	#ML = 7 CASE
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/ML7.txt"
done
for i in {51..60}
do 
	#SC = 5 CASE
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/SC5.txt"
done
for i in {61..70}
do
	#SC = 20 CASE 
	sed -i '' -e '$a\' "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt"
	cat "../evaluation_data_uncombined/relative_entropies/relative_entropy_${i}.txt" >> "../evaluation_data_sets/relative_entropies/SC20.txt"
done






