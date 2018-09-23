#!/bin/bash
# Data generating script

for i in {1..10}
do
	./generate 2 8 500 10
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {11..20}
do 
	./generate 1.5 8 500 10
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {21..30}
do
	./generate 1 8 500 10
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {31..40}
do 
	./generate 2 6 500 10
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {41..50}
do
	./generate 2 7 500 10
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {51..60}
do 
	./generate 2 8 500 5
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done
for i in {61..70}
do
	./generate 2 8 500 20
	rm -rf "../data_sets/data_set_${i}/"
	mkdir "../data_sets/data_set_${i}/"
	cp -R data_set/. "../data_sets/data_set_${i}/"
	sleep 1
done






