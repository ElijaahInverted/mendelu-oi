#!/bin/bash

read -p "Zadej a: " a

if [ "$a" -lt 100 ]; then
    echo "a je mensi nez 100"
elif [ "$a" -eq 100 ]; then
    echo "a se rovna 100"
else
    echo "a je vetsi nez 100"
fi