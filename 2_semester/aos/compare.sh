#!/bin/bash

read -p 'Enter number: ' a

if [ $a -lt 100 ]; then
    echo 'a is lesser than 100'
elif [ $a -eq 100 ]; then
    echo 'a is equal 100'
else 
    echo 'a is greater than 100'
fi