#!/bin/bash

dir=./maps-intermediate/mouli_maps
i=1
green_color="\e[1;32m"
red_color="\e[1;31m"
blank_color="\e[0m"

echo "Are your BSQ'd maps the same as the mouli's?"

for filepath in "$dir"/*
do
    filename=$(basename $filepath)
    run="./bsq $dir/$filename > map_test"
    eval "$run"
    run="cmp -s map_test $dir"
    run+="_solved/$filename"
    eval "$run"
    o_val=$?
    output="($i / 39) "
    if [ $o_val -eq 0 ]
    then
        output+="$green_color"
    else
        output+="$red_color"
    fi
    output+="$filename$blank_color"
    echo -e "$output"
    ((i++))
done
