#expr 12 + 8


echo enter two numbers
read x
read y
#sum=`expr $x + $y`
echo summation is `expr $x + $y`


#expr 12 \* 3

n=`expr 2 + 3 + 4`
echo $n

echo "The number of parameters are: $#"
echo "The parameters are $*"
echo "the $1 $2"
echo "The shell scripts command is: $0"


c=1.2
d=4.6
echo $c + $d | bc
#expr 12 \* 3


a=13
b=23
s=`echo $a + $b | bc`
echo sum of two number is $s

let "n1 = 2";echo $n1
#let a1 = 5 b1 = 6 su = a1 + b1; echo $su
#!/bin/bash
#function F1()
#{
#	echo 'I like bash programming'
#}

#F1()

