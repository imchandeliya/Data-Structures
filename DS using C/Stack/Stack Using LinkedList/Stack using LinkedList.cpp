/*
	Stack implementation using LinkedList
	author = "Aditya Chandeliya" 
	
*/

#include<iostream>
#include<malloc.h>
using namespace std;

//Method Declarations
void push(int item);
void pop();
void display();

//Node Structure
struct node
{
	int data;
	struct node *link;
}*top = NULL;


//Main Method
int main()
{
	int choice, m;
	do
	{
		printf("\n\n********MENU********\n");
		printf("1. Push\n");
		printf("2. Pop\n");
		printf("3. Display\n");
		printf("Enter 0 (zero) to exit the program...\n\n");
		printf("Enter your choice:	");
		scanf("%d",&choice);
		
		switch(choice)
		{
			case 1:
				printf("Enter element to push:	");
				scanf("%d",&m);
				push(m);
				break;
			case 2:
				pop();
				break;
			case 3:
				display();
				break;
			case 0:
				printf("Exitting program...");
				break;
			default:
				printf("Wrong input, Try agin...");
				break;
		}
	}while(choice != 0);
	return 0;	
}//End Main


//Push Method
void push(int item)
{
	struct node *temp;
	temp = (node*)malloc(sizeof(struct node));
	temp->data = item;
	
	if(top == NULL)
		temp->link = NULL;
	else
		temp->link = top;
		
	top = temp;
}//End Push Method

//Pop Method
void pop()
{
	struct node *temp;
	temp = top;
	top = top->link;
	printf("Element %d is pooped out od Stack.\n",temp->data);
	free(temp);
}//End Pop

//Display Method
void display()
{
	struct node *ptr;
	ptr = top;
	
	printf("\nStack: Top>> ");
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("<<Bottom\n\n");
}//End Display Method
