#!/bin/bash
echo -n "Enter a path"
read path
if [ -d $path ]; then
	echo "directory"
elif [ -f $path ]; then
	echo "is a file"
	val=$( du -b $path | cut -f1 ) 
	if [ $val -lt 102400 ]; then 
		echo "small file"
	elif [ $val -lt 1048576 ]; then
		echo "medium file"
	else
		echo "large file" 
	fi
else
	echo "no"
fi
