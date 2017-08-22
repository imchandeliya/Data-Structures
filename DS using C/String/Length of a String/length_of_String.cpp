/*
	C program to find length of String
	author: Aditya Chandeliya
*/

#include<iostream>
#include<string.h>
using namespace std;

int main()
{
	printf("Enter String:	");
	char str[100];
	gets(str);
	int length = strlen(str);
	printf("\nlength of string is %i \n",length);
	return 0;	
}
