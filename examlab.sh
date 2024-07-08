#echo enter m1:
#read m1
#echo enter m2:
#read m2
#total=`expr $m1 + $m2`
#echo totasum = $total
#avg=`expr $total / 5 `
#echo totalavg is = $avg


: '
echo enter n1 n2 n3
read n1 n2 n3
if [ $n1 -gt $n2 ] && [ $n1 -gt $n3 ]
then
	echo $n1 is greater
elif [ $n2 -gt $n1 ] && [ $n2 -gt $n3 ]
then
	echo $n2 is greater
else
	echo $n3 is greater
fi
'

: '
echo enter two strings
read a b
a=$a$b
echo concatenated string is : $a
'

: '
echo enter two number
read a b
echo "what do you want to do? (1 to 4) "
echo 1 = sum
echo 2 = difference
echo 3 = product
echo 4 = quotient
echo enter your choice
read n
case $n in 
	1)echo the sum of $a and $b is `expr $a + $b`;;
	2)echo the difference of $a and $b is `expr $a - $b`;;
	3)echo the product of $a and $b is `expr $a \* $b`;;
	4)echo the quotient of $a and $b is `expr $a / $b`;;
	*)echo invalid input
esac
'



