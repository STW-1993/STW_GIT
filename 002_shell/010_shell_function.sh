#!/bin/bash

my_fun1()
{
	local a=1                             #localǰ׺����ı���Ϊ�ֲ�����
	echo "�����ҵĵ�һ��shell����"
	a=`expr ${a} + 1`
}
echo "����1��ʼ"
my_fun1
echo "${a}"
echo "����1����"

echo "----------------------------------"

my_fun2()
{
	a=`expr ${a} + 1`					  #û��ǰ׺����ı���Ϊ���ļ����ȫ�ֱ���������������
	echo "${a}"
	echo "�����ҵĵڶ���shell����"
	my_fun1
}
echo "����2��ʼ"
my_fun2
echo "${a}"
echo "����2����"














