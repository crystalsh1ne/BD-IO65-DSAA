#!/bin/bash
touch test.txt
echo "" > test.txt
x="1"
echo "Для першої програми: " >> test.txt
for n in 1 2 3 10 20 30 50 100; do
    echo "$n $x" | ./1 >> test.txt
done

echo "Для другої програми: " >> test.txt
for n in 1 2 3 10 20 30 50 100; do
    echo "$n $x" | ./2 >> test.txt
done
