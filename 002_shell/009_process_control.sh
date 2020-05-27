#!/bin/bash

a=10
b=20

echo "-----------------------\ifelse------------------------------"

if [ ${a} == ${b} ]
then
	echo "a����b"
elif [ ${a} -gt ${b} ]
then
	echo "a����b"
elif [ ${a} -lt ${b} ]
then
	echo "aС��b"
else
	echo "û�з��ϵ�����"
fi

echo "-----------------------\iftest------------------------------"

num1=$[ 10 * 50 ]
num2=$[ 10 * 10 ]

echo "$[num1]"
echo "$[num2]"
if test ${num1} -gt ${num2}
then
	echo "num1����num2"
else
	echo "num1������num2"
fi

echo "-----------------------\for---------------------------------"

for i in 1 2 3 4 5 6 7 8 9
do
	echo "The value is :${i}"
done

for i in "This is a test!" 1 2 3 4 5 test     #ע���ӡ�����Ľ��
do
	echo "${i}"
done

echo "-----------------------\while-------------------------------"

n=10

while((${n} < 20))     #��Ҫ����С���ţ���Ȼ�ᱨ��
do
	echo "${n}"
	let "n++"          #������ʹ��${n}��$n�����ĵ��ã��ᵼ���﷨���� 
done

echo "����<CTRL-D>�˳�"
echo -n "������ϲ������վ����"

while read name
do
	echo "�ǵģ�${name}��һ������վ��"
done

echo "-----------------------\until-------------------------------"

g=0;

until [  ${g} -gt 10 ]
do
	echo "${g}"
	g=`expr ${g} + 1`
done

echo "-----------------------\case--------------------------------"

echo "����1��4֮������֣�"
read aNum
echo "�����������Ϊ��${aNum}"
case ${aNum} in
	1)
	echo "����ȷʵ�ǣ�1"
	;;
	2)
	echo "����ȷʵ�ǣ�2"
	;;
	3)
	echo "����ȷʵ�ǣ�3"
	;;
	4)
	echo "����ȷʵ�ǣ�4"
	;;
	*)
	echo "���ֲ���1��4֮�����"
	;;
esac



























