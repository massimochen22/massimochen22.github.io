#!/bin/bash
path_name=$1
username=$2
n_files=0
traverse() {
        #$ ls -l /bin/ls | grep "^.\{10\} [0-9]\{1,\} root"

        if [ ! -d "$1" ]; then
                local file1=`ls -l $1` 
                local permission_check=`expr match "$file1" '\(^.r..r..r..\)'`
                local username_check=`expr match "$file1" "\(^.\{10\} [0-9]\{1,\} $username \)"`
                if [ "$permission_check" ] && [ "$username_check" ] ; then
                        local file_name=`expr match "$file1" '.*\( /.*/.*\)'`
                        local date1=`expr match "$file1" '.*\([a-zA-Z]\{3\}[ ]*[1-3]*[0-9][ ]*[0-9]*[:]*[0-9]\)'`
                        echo "File name:$file_name | Permission: ${permission_check:1} | Date created/modified: $date1"
                        ((n_files++))
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
traverse $path_name
echo "total files: $n_files"

