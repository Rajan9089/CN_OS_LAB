: '
for var in 0 1 2 3 4 5 6 7 8 9
do
   echo $var
done
'


: '
echo program for prime number
echo enter a number
read n
flag=1
i=2
while [ $i -le $((n/2)) ]
do
	if [ $((n % i)) -eq 0 ]
	then
		flag=0
		break
	fi
	i=$((i + 1))
done


if [ $flag -eq 1 ]
then
	echo $n is prime
else
	echo $n is not a prime number
fi
'


#!/bin/bash

echo "Enter a number: "
read num

is_prime=1

for ( (i=2; i -le $((num/2)); i++) )
do
    if [ $((num % i)) -eq 0 ]
    then
        is_prime=0
        break
    fi
done

if [ $is_prime -eq 1 ]
then
    echo "$num is prime."
else
    echo "$num is not prime."
fi

