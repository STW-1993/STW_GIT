#!/bin/bash

my_fun1()
{
	local a=1                             #local前缀定义的变量为局部变量
	echo "这是我的第一个shell函数"
	a=`expr ${a} + 1`
}
echo "函数1开始"
my_fun1
echo "${a}"
echo "函数1结束"

echo "----------------------------------"

my_fun2()
{
	a=`expr ${a} + 1`					  #没有前缀定义的变量为本文件里的全局变量（环境变量）
	echo "${a}"
	echo "这是我的第二个shell函数"
	my_fun1
}
echo "函数2开始"
my_fun2
echo "${a}"
echo "函数2结束"














