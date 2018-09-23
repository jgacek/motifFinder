#!/bin/bash
#script to run all other scripts

cd generator 
sh sequence_generator.sh
cd ../motif_finder
sh find_motifs.sh
cd ../evaluation_programs
sh all_overlaps.sh
cd ../evaluation_programs
sh all_entropies.sh
cd ../evaluation_scripts
sh running_time.sh
cd ../evaluation_scripts
sh overlaps.sh
cd ../evaluation_scripts
sh relative_entropy.sh
