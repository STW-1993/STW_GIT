/*
 * csv�ļ���ȡ������fgets()��strtok()������ʹ��
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>


int main(){
    FILE *fp = NULL;
    char *line,*record;
    char buffer[20450];//20450��������СҲҪ�����Լ��ļ�������������Ӧ�޸ġ�

    if((fp = fopen("021.csv", "r")) != NULL)
    {
        while ((line = fgets(buffer, sizeof(buffer), fp))!=NULL)//��û�ж�ȡ���ļ�ĩβʱѭ����������ȡһ��fgets
        {
            record = strtok(line, ",");
            while (record != NULL)//��ȡÿһ�е����ݲ���ӡ����
            {
                printf("%s ", record);//����ȡ����ÿһ�����ݴ�ӡ����
                record = strtok(NULL, ",");
            }
        }
        fclose(fp);
        fp = NULL;
    }
}



