#!/bin/bash

for f in "$@"; do
    if [ -e "$f" ]; then
        echo "Soubor existuje: $f"
        file "$f"
    else
        echo "Soubor neexistuje: $f"
    fi
done