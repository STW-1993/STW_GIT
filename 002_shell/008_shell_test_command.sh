#!/bin/bash

num1=100
num2=200

if test ${num1} -eq ${num2}
then
	echo "���������"
else
	echo "�����������"
fi

return1=$[num1+num2]                      #�����������л�������������
return2=${num1+num2}		              #�������򲻻��������
echo "return1Ϊ:${return1}"
echo "return2Ϊ:${return2}"

cd /bin
if test -e ./bash
then
	echo "�ļ�����"
else
	echo "�ļ�������"
fi

echo "----------------------------------"

cd /bin
if test -e ./bash -o -e ./nofile
then
	echo "������һ���ļ�����"
else
	echo "�ļ���������"
fi


