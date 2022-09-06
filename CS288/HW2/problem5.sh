#!/bin/bash
traverse() {
	echo $1
	if [ ! -d "$1" ]; then
		val=$( du -b $1 | cut -f1 )
		if [ $val -eq 0 ]; then
			rm $1
		fi
		return
	fi
	if [ `ls "$1" | wc -l` -eq 0 ]; then   
		return
	fi
	local entries=("$1"/*)
	local entry
	for entry in "${entries[@]}"
	do
		traverse "$entry"
	done
}

if [ $# = 0 ]; then
	value="${PWD##*/}"
	cd ..
	traverse  "$value"
else
  	traverse "$1"
fi

