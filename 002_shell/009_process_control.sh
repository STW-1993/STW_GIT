#!/bin/bash

a=10
b=20

echo "-----------------------\ifelse------------------------------"

if [ ${a} == ${b} ]
then
	echo "a等于b"
elif [ ${a} -gt ${b} ]
then
	echo "a大于b"
elif [ ${a} -lt ${b} ]
then
	echo "a小于b"
else
	echo "没有符合的条件"
fi

echo "-----------------------\iftest------------------------------"

num1=$[ 10 * 50 ]
num2=$[ 10 * 10 ]

echo "$[num1]"
echo "$[num2]"
if test ${num1} -gt ${num2}
then
	echo "num1大于num2"
else
	echo "num1不大于num2"
fi

echo "-----------------------\for---------------------------------"

for i in 1 2 3 4 5 6 7 8 9
do
	echo "The value is :${i}"
done

for i in "This is a test!" 1 2 3 4 5 test     #注意打印出来的结果
do
	echo "${i}"
done

echo "-----------------------\while-------------------------------"

n=10

while((${n} < 20))     #需要两个小括号，不然会报错
do
	echo "${n}"
	let "n++"          #不可以使用${n}、$n这样的调用，会导致语法错误 
done

echo "按下<CTRL-D>退出"
echo -n "输入你喜欢的网站名："

while read name
do
	echo "是的！${name}是一个好网站！"
done

echo "-----------------------\until-------------------------------"

g=0;

until [  ${g} -gt 10 ]
do
	echo "${g}"
	g=`expr ${g} + 1`
done

echo "-----------------------\case--------------------------------"

echo "输入1到4之间的数字："
read aNum
echo "你输入的数字为：${aNum}"
case ${aNum} in
	1)
	echo "数字确实是：1"
	;;
	2)
	echo "数字确实是：2"
	;;
	3)
	echo "数字确实是：3"
	;;
	4)
	echo "数字确实是：4"
	;;
	*)
	echo "数字不是1到4之间的数"
	;;
esac



























