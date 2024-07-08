echo enter a number: 
read n

first=0
second=1
echo Fibonacii Series: 
echo -n "$first "
echo -n "$second "  

i=2
while [ $i -lt $n ]
do
	sum=$((first + second))
	echo -n "$sum "
	first=$second
	second=$sum
	i=$((i + 1))
done

#!/bin/bash

echo -n "This is "
echo "a single line."

