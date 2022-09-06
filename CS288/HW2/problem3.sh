#!/bin/bash
files=($*) 
len_file=${#files[*]}


for (( x=0; x<len_file-1; x++ )); do

   for (( y=0; y<len_file-x-1; y++ )); do
      if (( files[y] > files[y+1] )); then
         tmp=${files[y]}
         files[y]=${files[y+1]}
         files[y+1]=$tmp
      fi
   done

done


for (( idx=0; idx<$len_file; idx++)); do
        echo -n "${files[idx]} "  
done

echo ""
