num=10
cnt=0
while [ $cnt -lt $num ]
do
	echo $cnt
	cnt=`expr $cnt + 1`
done



echo "Using while loop:"
count=1

while [ $count -le 10 ]
do
    echo $count
    count=$((count + 1))
done



echo "Using until loop:"
count=1

until [ $count -gt 10 ]
do
    echo $count
    count=$((count + 1))
done
