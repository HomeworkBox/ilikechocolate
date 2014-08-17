#!/bin/bash

for dir in $(find /cs/student/ -mindepth 1 -maxdepth 1 -type d)
do
  if [ -r $dir/public_html/index.html ]; then
    username=$(echo $dir | cut -d'/' -f4)
    result=$(finger -ms $username 2>&1 1>/dev/null | wc -l) 
    if [ $result -eq 0 ]; then
		fullname_raw=$( finger $username | head -n 1 | cut -d':' -f3 )
		echo "$username |$fullname_raw"
    fi
  fi
done

exit 1

# Tyler Weimin Ouyang Aug 8 2014