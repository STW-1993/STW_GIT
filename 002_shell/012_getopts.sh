#!/bin/bash

while getopts ":t:m:d" optname
do
	case $optname in
	t)
	tt=${OPTARG}
	echo "${tt}"
	;;
	m)
	mm=${OPTARG}
	echo "${mm}"
	;;
	d)
	echo "ʹ����dѡ��"
	;;
	:)
	echo "No argument value for option $OPTARG"    #���t��m��d����û���������ͻ��ӡNo argument value for option t\m\d
	;;
	?)                                             #  ?��:��λ�ò������������:)Ҫ��?)֮�ϣ���Ȼ:)��ʧȥ������
	echo "Unknown option $OPTARG"
	;;
	*)
	echo "Unknown error while processing options"
	;;
	esac
done


if [ -z ${tt} ]	                 #�����${tt}�ɼӿɲ���˫���ţ�����-z��-n����˫���ţ�����ֻ��ʾ������
then
	echo "ûʹ��tѡ��<no>"
fi

if [ -n "${tt}" ]                #ע�⣺���û��˫���ŵĻ�������tt�Ƿ�Ϊ�յ��ַ������������if���Ϊ���ӡ���ʱ��if����Ч��if [ -n ]��
						         #      shell ���������if [ str1 ]������-n��Ȼ��Ϊ�գ�����Ϊ��
then
	echo "ʹ����tѡ��<yes>"
fi











