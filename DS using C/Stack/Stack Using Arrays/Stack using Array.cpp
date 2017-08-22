/*
	C program for Stack Implementation [Array Version]
	author= "Aditya Chandeliya"
	
	Constraints: Max size 5
*/

//Imports
#include<iostream>
using namespace std;

//Method Declarations
bool isEmpty();
bool isFull();
void push(int item);
void pop();
void display();

//Stack Definition
#define MAX 10
int top = -1;
int Stack[MAX];


//Main Method
int main()
{
	int choice,m;
	do
	{
		printf("********Menu********\n");
		printf("1. Push.\n");
		printf("2. Pop.\n");
		printf("3. Display .\n");
		printf("Enter 0 (zero) to exit the program...");
		printf("\nEnter your choice:	");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("\nElement to Push:	");
				scanf("%d",&m);
				push(m);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 4:
				printf("Exitting the program...");
				break;
			default:
				printf("Wrong Input, Try again...\n\n");
				break;
		}
	}while(choice != 0);		
	return 0;
}//End Main Method

//isFull Method
bool isFull()
{
	if(top >= MAX-1)
		return true;
	else
		return false;
}//End isFull Method

//isEmpty
bool isEmpty()
{
	if(top == -1)
		return true;
	else
		return false;
}//isEmpty

//Push Method
void push(int item)
{
	if(isFull())
		printf("\nStack OverFlow...\n\n");
	else
	{
		top++;
		Stack[top] = item;
	}
}//End Push Method

//Pop Method
void pop()
{
	if(isEmpty())
		printf("Stack Empty...\n\n");
	else
	{
		printf("Element %d is pooped out,\n\n",Stack[top]);
		top--;
	}
}//End Pop Method


//Display Method
void display()
{
	if(isEmpty())
		printf("Stack is Empty...\n\n");

	else
	{
		printf("Stack Elements:	");
		for(int i=0 ; i<=top ; i++)
			printf("%d ",Stack[i]);
	}	
	printf("\n\n");
}//End Display Method
