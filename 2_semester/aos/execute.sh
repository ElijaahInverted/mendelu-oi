#!/bin/bash
for x in "$@"
do
    if [ -e "$x" ]; then
        file "$x";
    else
        echo "File $x is missing.";
    fi
done