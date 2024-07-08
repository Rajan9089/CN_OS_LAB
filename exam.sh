: '
echo enter str1
read s1
echo enter str2
read s2 
a=`expr $s1 = $s2`
echo $a
'

: '
echo enter str1
read s1
echo enter str2
read s2
if [ $s1 = $s2 ]
then
	echo same
else
	echo not same
fi
'

: '
echo enter a num
read x
if [ `expr $x % 2` -eq 0 ]
then
	echo $x is even
else
	echo $x is odd
fi
'

: '
echo -n "enter year (yyyy) : "
read y
p=`expr $y % 4`
q=`expr $y % 100`
z=`expr $y % 400`
if [ $p -eq 0 -a $q -ne 0 -o $z -eq 0 ]
then
	echo $y is a leap year
else
	echo $y is not a leap year
fi
'



