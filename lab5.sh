
echo Enter two number
read a b
echo "what do you want to do?(1 to 4)"
echo 1=sum
echo 2=Difference
echo 3=product
echo 4=Quotient
echo Enter your choice
read n
case $n in
	1)echo The sum of $a and $b is `expr $a + $b`;;
	2)echo The Difference of $a and $b is `expr $a - $b`;;
	3)echo The product of $a and $b is `expr $a \* $b`;;
	4)echo The Quotient of $a and $b is `expr $a / $b`;;
	*)echo Invalid input
esac


: '
echo "1)Monday"
echo "2)Tuesday"
echo "3)wednesday"
echo "4)Thursday"
echo "5)Friday"
echo "6)Saturday"
echo "7)Sunday"
echo Enter a Day number
read n
case $n in
	1)echo Monday;;
	2)echo Tuesday;;
	3)echo Wednesday;;
	4)echo Thursday;;
	5)echo Friday;;
	6)echo Saturday;;
	7)echo Sunday;;
	*)echo Invalid Input
esac
'

