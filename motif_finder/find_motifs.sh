#!/bin/bash
# Data finding script

for i in {1..70}
do
	./find "../data_sets/data_set_${i}/"
	rm -rf "../predicted_data_sets/predicted_set_${i}/"
	mkdir "../predicted_data_sets/predicted_set_${i}/"
	cp -R predicted_data_sets/. "../predicted_data_sets/predicted_set_${i}/"
done
