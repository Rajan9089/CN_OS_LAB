echo hi user , welcome to electio
echo what is your age?
read age

if [ $age -ge 18 ]
then
	echo you can vote!
else
	echo sorry, you cannot!
fi



