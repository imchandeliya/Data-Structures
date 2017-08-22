/*
	Towor of Honoi using C
	author = "Aditya Chandeliya";
*/

#include<iostream>
using namespace std;

void honoi(int n_disk, char source, char temp, char destination);
int main()
{
	char source = 'S';
	char temp = 'T';
	char destination = 'D';
	int n_disk;
	printf("Enter number of disks:");
	scanf("%d",&n_disk);
	
	printf("Sequence is:\n\n");
	honoi(n_disk, source, temp, destination);
}

void honoi(int n_disk, char source, char temp, char destination)
{
	if(n_disk>0)
	{
		honoi(n_disk-1, source, destination, temp );
		printf("Move disk %d, %c -> %c\n",n_disk,source,destination);
		honoi(n_disk-1,temp,source,destination);
	}	
}
