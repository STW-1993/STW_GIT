/*
 * 删除一个字符串中的指定字母，如：字符串 "aca"，删除其中的 a 字母；如：字符串"abcabcabcabcabc"，删除其中的ac字母
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
    char s[2] = "ac";     // 要删除的字母
    char s2[30] = "abcabcabcabcabc";  // 目标字符串
    printf("%s\n", deleteCharacters(s2, s));
    return 0;

}


