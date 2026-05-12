#!/bin/bash
count=0

while true; do
read -p "Zadej cislo: " num
if [ "$num" -eq 0 ]; then
    break
fi
if [ "$num" -gt 50 ]; then
    count=$((count + 1))
fi
done
echo "vetsi nez 50: $count"