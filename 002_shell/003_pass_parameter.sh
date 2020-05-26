#!/bin/bash

echo "File name of execution: $0"
echo "First parameter:        $1"
echo "Second parameter:       $2"
echo "The third parameter:    $3"
echo "Number of parameters:   $#"
echo "The parameter passed is displayed as a string: $@"
echo "The parameter passed is displayed as a string: $*"
echo "$$"   #脚本运行的当前版本号
echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
echo "-----\$*-----"
for  i in "$*" ;do
	echo $i
done

echo "-----\$@-----"
for  i in "$@" ;do
	echo $i
done	
echo "++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++"
if [ 2 == 3 ];then
	echo "aaaaaaaaaa"
else
	echo "bbbbbbbbbb"
fi