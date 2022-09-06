#!/bin/bash
function main() {
cd $1
files=(*)
reverse 
}

function reverse() {
len_file=${#files[*]}   
len_file=$((len_file - 1))
for (( idx=$len_file; idx>=0; idx-- )); do
	echo -n "${files[idx]} "  
done
}
main $1
