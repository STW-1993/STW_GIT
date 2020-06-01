/*
 * ɾ��һ���ַ����е�ָ����ĸ���磺�ַ��� "aca"��ɾ�����е� a ��ĸ���磺�ַ���"abcabcabcabcabc"��ɾ�����е�ac��ĸ
 */
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

char* deleteCharacters(char * str, char * charSet)
{
    int hash [128] = {0};
	int i;
	int currentIndex = 0;
	
    if(NULL == charSet)
        return str;
    for(i = 0; i < strlen(charSet); i++)
        hash[charSet[i]] = 1;
    for(i = 0; i < strlen(str); i++)
    {
        if(!hash[str[i]])
            str[currentIndex++] = str[i];
    }
    str[currentIndex] = '\0';
    return str;
}
 
int main()
{
    char s[2] = "ac";     // Ҫɾ������ĸ
    char s2[30] = "abcabcabcabcabc";  // Ŀ���ַ���
    printf("%s\n", deleteCharacters(s2, s));
    return 0;

}


