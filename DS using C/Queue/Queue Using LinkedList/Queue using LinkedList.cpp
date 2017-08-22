/*
	Queue Implemtation using LinkedList in C programming
	author = "Aditya Chandeliya"
	
*/

//Includes
#include<iostream>
#include<malloc.h>
using namespace std;

//Method Declaration
void insert(int item);
void display();
void del();

//Structure for the Node
struct node
{
	int data;
	struct node *link;
}*front=NULL, *rear=NULL;	//Front and Rear pointers

//Main Function
int main()
{
	int choice, m;
	do
	{
		printf("\n********MENU********\n");
		printf("1. Insert\n");
		printf("2. Delete\n");
		printf("3. Display Queue\n");
		printf("Enter 0 (zero) to exit program...\n");
		
		printf("\nEnter your choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter element:");
				scanf("%d",&m);
				insert(m);
				break;
			case 2:
				del();
				break;
			case 3:
				display();
				break;
			case 0:
				printf("Exitting the program...\n\n");
				break;
			default:
				printf("Wrong Choice, Try Again...\n\n");
				break;
		}	
	}while(choice != 0);	
	
	return 0;
}//End Main

//Insert Method
void insert(int item)
{
	struct node *temp;
	temp = (node*)malloc(sizeof(struct node));
	temp->data = item;
	
	if(rear == NULL)
	{
		temp->link = NULL;
		front = temp;
	}
	else
		temp->link = rear;
	rear = temp;
}//End Insert

//Delete Method
void del()
{
	struct node *ptr,*temp;
	ptr = rear;
	
	while(ptr->link->link != NULL)
		ptr = ptr->link;
	temp = ptr->link;
	printf("\n\nElement %d deleted\n",temp->data);
	front = ptr;
	front->link = NULL;
	free(temp);
}
//End Delete Method

//Display Method
void display()
{
	struct node *ptr;
	ptr = rear;
	printf("\nQueue is:	rear>>");
	while(ptr != NULL)
	{
		printf("%d ",ptr->data);
		ptr = ptr->link;
	}
	printf("<<front\n\n");	
}//End Display Method

