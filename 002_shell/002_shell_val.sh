#!/bin/bash

my_string="i am a student!"    #定义变量

echo ${my_string}              #打印变量

echo ${#my_string}             #打印变量的长度

echo ${my_string:2:5}          #打印my_string变量里提取的从第3到第6个字符之间的所有字符

echo `expr index "$my_string" stu`    #打印查找字符串my_string字符串中三个字符‘s’‘t’‘u’任何一个首次出现的位置（从1开始算），注：这里用的反引号，不是单引号

echo "----------------------------------------------------------"

my_string1=${my_string}
my_string2=${#my_string}
my_string3=${my_string:2:5}
my_string4=`expr index "$my_string" stu`

echo ${my_string1} ${my_string2} ${my_string3} ${my_string4}  

echo '++++++++++++++++++++++++++++++++++++++++++++++++++++++++++'

array_name=(value0 value1 value2 value3)           #定义一个数组，用括号来表示数组，数组元素用"空格"符号分割开

echo ${array_name[2]}         #打印数组的第三个元素

echo ${array_name[@]}         #打印数组的所有元素

echo ${#array_name[@]}        #打印数组的元素个数

echo ${#array_name[1]}        #打印数组的第二个元素的字符数量

