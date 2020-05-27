#!/bin/bash

num1=100
num2=200

if test ${num1} -eq ${num2}
then
	echo "两个数相等"
else
	echo "两个数不相等"
fi

return1=$[num1+num2]                      #中括号里会进行基本的算数运算
return2=${num1+num2}		              #大括号则不会进行运算
echo "return1为:${return1}"
echo "return2为:${return2}"

cd /bin
if test -e ./bash
then
	echo "文件存在"
else
	echo "文件不存在"
fi

echo "----------------------------------"

cd /bin
if test -e ./bash -o -e ./nofile
then
	echo "至少有一个文件存在"
else
	echo "文件都不存在"
fi


