#!/bin/bash

for f in "$@"; do
    if [ -d "$f" ]; then
        echo "It's a directory"
    elif [ -f "$f" ]; then
        wc -l "$f"
    else
        echo "Neplatny parametr"
    fi
done