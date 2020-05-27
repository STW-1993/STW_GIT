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
	echo "使用了d选项"
	;;
	:)
	echo "No argument value for option $OPTARG"    #如果t、m、d后面没带参数，就会打印No argument value for option t\m\d
	;;
	?)                                             #  ?和:的位置不能随意调换，:)要再?)之上，不然:)就失去了作用
	echo "Unknown option $OPTARG"
	;;
	*)
	echo "Unknown error while processing options"
	;;
	esac
done


if [ -z ${tt} ]	                 #这里的${tt}可加可不加双引号，建议-z和-n都用双引号，这里只是示范作用
then
	echo "没使用t选项<no>"
fi

if [ -n "${tt}" ]                #注意：如果没有双引号的话，无论tt是否为空的字符串，都会进入if里，因为不加“”时该if语句等效于if [ -n ]，
						         #      shell 会把它当成if [ str1 ]来处理，-n自然不为空，所以为正
then
	echo "使用了t选项<yes>"
fi











