#!/bin/bash
# Script to merge together data based on parameters

#need to make the directory if it doesn't exist and delete the files if they do
mkdir "../evaluation_data_sets/running_times/"
mkdir "../evaluation_data_uncombined/running_times/"
rm "../evaluation_data_sets/running_times/IPC2.txt"
rm "../evaluation_data_sets/running_times/ML8.txt"
rm "../evaluation_data_sets/running_times/SC10.txt"
rm "../evaluation_data_sets/running_times/IPC1_5.txt"
rm "../evaluation_data_sets/running_times/IPC1.txt"
rm "../evaluation_data_sets/running_times/ML6.txt"
rm "../evaluation_data_sets/running_times/ML7.txt"
rm "../evaluation_data_sets/running_times/SC5.txt"
rm "../evaluation_data_sets/running_times/SC20.txt"

for i in {1..10}
do
	#we want to copy over our running time (full) data for consistency sake first
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	#IPC = 2, ML = 8, SC = 10 CASE (DEFAULT)
	#cat will create the file if it does not already exist
	#sed will add a new line if it doesn't exist to the input files
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/IPC2.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/ML8.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/SC10.txt"
done
for i in {11..20}
do 
	#IPC = 1.5 CASE
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/IPC1_5.txt"
done
for i in {21..30}
do
	#IPC = 1 CASE
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/IPC1.txt"
done
for i in {31..40}
do 
	#ML = 6 CASE
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/ML6.txt"
done
for i in {41..50}
do
	#ML = 7 CASE
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/ML7.txt"
done
for i in {51..60}
do 
	#SC = 5 CASE
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/SC5.txt"
done
for i in {61..70}
do
	#SC = 20 CASE 
	cp -R "../predicted_data_sets/predicted_set_${i}/runningtime.txt" "../evaluation_data_uncombined/running_times/runningtime_${i}.txt"
	sed -i '' -e '$a\' "../predicted_data_sets/predicted_set_${i}/runningtime.txt"
	cat "../predicted_data_sets/predicted_set_${i}/runningtime.txt" >> "../evaluation_data_sets/running_times/SC20.txt"
done






