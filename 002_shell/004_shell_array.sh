#!/bin/bash

my_array=(A B "C" D)

array_name[0]=value0
array_name[1]=value1
array_name[2]=value2

echo ${my_array[0]}
echo ${my_array[1]}
echo ${my_array[2]}
echo ${my_array[3]}

echo ${array_name[0]}
echo ${array_name[1]}
echo ${array_name[2]}

echo ${my_array[@]}
echo ${array_name[*]}

echo ${#my_array[@]}
echo ${#my_array[1]}