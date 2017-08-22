/*
	Program to concatinate strings
*/

#include<iostream>
using namespace std;
void concat(char *str1, char *str2);

int main()
{
	char str1[100];
	char str2[100];
	printf("Enter String 1:");
	gets(str1);
	printf("Enter String 2:");
	gets(str2);
	
	concat(str1, str2);
	
	printf("concatination is : %s",str1);
}


void concat(char *str1, char *str2)
{
	while(*str1 != '\0')
		str1++;
	while(*str2 != '\0')
	{
		*str1 = *str2;
		str1++;
		str2++;
	}
	*str1 == '\0';
}
