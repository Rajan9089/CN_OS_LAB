: '
echo -n "Enter a number: "
read n
temp=$n

rev=0

while [ $n -gt 0 ]
do 
	rem=$((n % 10))
	rev=$((rev * 10 + rem))
	n=$((n / 10))
done

# check if the number is a palindrome
if [ $temp -eq $rev ];
then
    echo "$temp is a palindrome number."
else
    echo "$temp is not a palindrome number."
fi
'

a=13
b=34
c=$((a + b))
echo $c

