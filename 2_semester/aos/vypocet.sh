#!/bin/bash

read -p 'A: ' a
read -p 'B: ' b

if [ "$1" = "s" ]; then
    echo "addition: $((a + b))"
elif [ "$1" = "n" ]; then
    echo "multiplication: $((a * b))"
else
    echo "The first argument is missing: s/n (sečti/násob)"
fi