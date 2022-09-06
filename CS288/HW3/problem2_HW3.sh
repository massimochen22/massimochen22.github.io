#!/bin/bash

mkdir html_files

for i in {A..Z}; do 
	for x in {A..Z}; do
		wget https://en.wikipedia.org/wiki/$i$x -O html_files/$i$x.html

	done
done

html2text html_files/*.html > html_to_txt.txt 

grep -o "\s[a-zA-Z]\{1,\}\s" html_to_txt.txt | sort | uniq -c | sort -nr | head -5
