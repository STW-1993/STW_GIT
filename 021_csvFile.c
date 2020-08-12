/*
 * csv文件读取操作，fgets()、strtok()函数的使用
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    FILE *fp = NULL;
    char *line,*record;
    char buffer[20450];//20450这个数组大小也要根据自己文件的列数进行相应修改。

    if((fp = fopen("021.csv", "r")) != NULL)
    {
        while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//当没有读取到文件末尾时循环继续，读取一行fgets
        {
            record = strtok(line, ",");
            while (record != NULL)//读取每一行的数据并打印出来
            {
                printf("%s ", record);//将读取到的每一个数据打印出来
                record = strtok(NULL, ",");
            }
        }
        fclose(fp);
        fp = NULL;
    }
}



