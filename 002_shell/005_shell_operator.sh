#!/bin/bash
#原生bash不支持简单的数学运算，但是可以通过其他命令来实现，例如 awk 和 expr，expr 最常用。

val1=`expr 2 + 2`            #表达式和运算符之间要有空格，例如 2+2 是不对的，必须写成 2 + 2
val2=`expr 2+2`
echo "$val1"
echo "$val2"


a=10
b=20
echo "a=10 b=20"

val=`expr ${a} + ${b}`
echo "+= ${val}"

val=`expr ${a} - ${b}`
echo "-= ${val}"

val=`expr ${a} \* ${b}`
echo "*= ${val}"

val=`expr ${b} / ${a}`
echo "/= ${val}"

val=`expr ${b} % ${a}`
echo "%= ${val}"

if [ ${a}==${b} ]
then
	echo "a=b"
fi

if [ ${a} != ${b} ]
then
	echo "a!=b"
fi

echo "------------------------------------------------------"

if [ ${a} -eq ${b} ]
then
	echo "a=b"
else
	echo "a!=b"
fi

if [ ${a} -ne ${b} ]
then
	echo "a!=b"
else
	echo "a=b"
fi

if [ ${a} -gt ${b} ]
then
	echo "a>b"
else
	echo "a<=b"
fi

if [ ${a} -lt ${b} ]
then
	echo "a<b"
else
	echo "a>=b"
fi

if [ ${a} -ge ${b} ]
then
	echo "a>=b"
else
	echo "a<b"
fi

if [ ${a} -le ${b} ]
then
	echo "a<=b"
else
	echo "a>b"
fi

echo "------------------------------------------------------"

if [ ${a} != ${b} ]
then
	echo "a!=b"
else
	echo "a=b"
fi

if [ ${a} -lt 100 -a ${b} -gt 15 ]
then
	echo "true"
else
	echo "false"
fi

if [ ${a} -lt 100 -o ${b} -gt 100 ]
then
	echo "true"
else
	echo "false"
fi

if [ ${a} -lt 5 -o ${b} -gt 100 ]
then
	echo "true"
else
	echo "false"
fi

echo "------------------------------------------------------"

if [[ ${a} -lt 15 && ${b} -gt 15 ]]             #要使用两个中括号
then
	echo "true"
else
	echo "false"
fi

if [[ ${a} -lt 5 || ${b} -gt 100 ]]
then
	echo "true"
else
	echo "false"
fi

echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++"

string1="abcdef"
string2="ghijkl"

if [ ${a} = ${b} ]
then
	echo "true"
else
	echo "false"
fi

if [ ${a} != ${b} ]
then
	echo "true"
else
	echo "false"
fi

if [ -z ${a} ]
then
	echo "true"
else
	echo "false"
fi

if [ -n ${a} ]
then
	echo "true"
else
	echo "false"
fi

if [ ${a} ]
then
	echo "true"
else
	echo "false"
fi

echo "+++++++++++++++++++++++++++++++++++++++++++++++++++++++"

file="/work/huangzhiwei/test/002_shell"

if [ -r ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -w ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -x ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -f ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -d ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -s ${file} ]
then
	echo "true"
else
	echo "false"
fi

if [ -e ${file} ]
then
	echo "true"
else
	echo "false"
fi

















































