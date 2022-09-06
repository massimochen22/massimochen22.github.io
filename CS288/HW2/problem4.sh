#!/bin/bash

cd /bin
files=(*)
declare -A array

for char in {z..a}; do
	count=0
	for file in ${files[*]}; do
		temp="${file:0:1}"
		
		if [[ $temp == $char ]]; then
			(( count++ ))	
		fi
	done		 

	array[$char]=$count

done 

for key in {a..z}; do 
	echo "${array[$key]} $key"
done 
