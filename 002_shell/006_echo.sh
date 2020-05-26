#!/bin/bash

echo "It is a test!"

echo It is a test!        #双引号可以省略

echo "\"It is a test!\""

read name
echo "${name} it is a test!"

echo -e "It is a test! \n"
echo "yes!"

echo -e "It is a test! \c"
echo "yes!"

echo `date`