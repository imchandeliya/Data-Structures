/*
	Linked List implementation using C
	author = "Aditya Chandeliya"
*/

//Imports
#include<iostream>
#include<malloc.h>
using namespace std;

//Structure for Node
struct node
{
	int data;
	struct node *link;
}*start;

//Method Declaration
void createList(int item);
void displayList();
void addBegin(int item);
void addEnd(int item);
void addAfter(int item, int position);
void deleteElement(int item);
void countList();
void reverseList();
void search(int item);

//Main
int main()
{
	int choice=0,m,no_nodes,place;
	do
	{
		printf("\n\n********Menu********\n\n");
		printf("1. Create a list\n");
		printf("2. Add element at beginning\n");
		printf("3. Add element at end\n");
		printf("4. Add element after\n");
		printf("5. Delete element\n");
		printf("6. Display list\n");
		printf("7. Count list items\n");
		printf("8. Reverse List\n");
		printf("9. Search element\n");
		printf("Enter 0 (zero) to Exit program\n");
		printf("\nEnter you choice:");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter number of nodes you want to add:");
				scanf("%d",&no_nodes);
				for(int i=1 ; i<=no_nodes ; i++)
				{
					printf("Enter element %d:	",i);
					scanf("%d",&m);
					createList(m);
				}
				break;
			case 2:
				printf("Element to enter:");
				scanf("%d",&m);
				addBegin(m);
				break;
			
			case 3:
				printf("Element to enter:");
				scanf("%d",&m);
				addEnd(m);
				break;
			
			case 4:
				printf("Element to enter:");
				scanf("%d",&m);
				printf("Enter position number (example: 0,1,2,3... etc):",m);
				scanf("%d",&place);
				addAfter(m, place);
				break;				
		
			case 5:
				printf("Enter element to delete:");
				scanf("%d",&m);
				deleteElement(m);
				break;
			case 6:
				displayList();
				break;		
			case 7:
				countList();
				break;	
			case 8:
				reverseList();
				break;
			case 9:
				printf("Enter element to search:	");
				scanf("%d",&m);
				search(m);
				break;
			case 0:
				printf("Exiting program...");
				break;
			default:
				printf("Wrong input, please try again...");
				break;
		}
	}while(choice != 0);
	
	return 0;
}//End Main

//Create List
void createList(int item)
{
	struct node *temp,*q;
	temp = (node*)malloc(sizeof(struct node));
	temp->data = item;
	temp->link = NULL;
	
	if(start==NULL)
		start = temp;
	else
	{
		q = start;
		while(q->link != NULL)
			q = q->link;
		q->link = temp;
	}
}//End Create List

/*
	Algorithm for CreateList Method
	
	CreateList(item to be inserted during creation)
	{
		temp = Create Node of size Node Struct;
		insert the item in data field;
		mark link field as Null;
		
		if(The origin of LinkedList is Null, ie There is No Existing Linklist present)
			Store address of temp to start
		else
			Treverse upto last Node of existing linkedlist;
				store the address of temp to in link field of last element;
		
		
	}

*/

//Display List
void displayList()
{
	struct node *q;
	q = start;
	printf("List:	");
	
	if(start == NULL)
		printf("List is Empty");
	while(q != NULL)
	{
		printf("%d, ",q->data);
		q = q->link;
	}
	printf("\n");
}//End Display List

/*
	Algorithm for  displayList
	
	voidList()
	{
		
	}
*/

//Add Element at beginning
void addBegin(int item)
{
	if(start == NULL)
	{
		printf("List empty, Adding element to new List");
		createList(item);
	}
	else
	{
		struct node *temp;
		temp = (node*)malloc(sizeof(struct node));
		temp->data = item;
		temp->link = start;
		start = temp;
	}
}//End Add Element at Beginning


//Add Element at End
void addEnd(int item)
{
	if(start == NULL)
	{
		printf("List is empty, Adding element to new List");
		createList(item);
	}
	else	
	{
		struct node *p;
		struct node *temp;
		temp = (node*)malloc(sizeof(struct node));
		temp->data = item;
		
		p = start;
		while(p->link != NULL)
			p = p->link;
		p->link = temp;
		temp->link = NULL;
	}
}//End Add ELement at End

//Add After
void addAfter(int item, int position)
{
	int check = 0;
	if(start == NULL)
	{
		printf("List empty, please try other options...");
	}
	else
	{
		struct node *p,*temp;
		p = start;
		for(int i=1 ; i<position ; i++)
		{
			p = p->link;
			if(p == NULL)
			{
				printf("Tere are less then %d elements\n",position);
				return;
			}
		}

		temp = (node*)malloc(sizeof(struct node));
		temp->data = item;
		temp->link = p->link;
		p->link = temp;
	}
}//End Add After


//Delete Element
void deleteElement(int item)
{
	struct node *ptr,*temp;
																						
	if(start->data == item)
	{
		temp = start;
		start = start->link;
		free(temp);
		return;
	}
	ptr = start;
	while(ptr->link->link != NULL)
	{
		if(ptr->link->data == item)
		{
			temp = ptr->link;
			ptr->link = temp->link;
			free(temp);
			return;
		}
		ptr = ptr->link;
	}
	if(ptr->link->data == item)
	{
		temp = ptr->link;
		free(temp);
		ptr->link = NULL;
		return;
	}
	printf("Element bot found...\n");
}//End Delete Element

//Count List
void countList()
{
	struct node *ptr;
	ptr = start;
	int ctr=0;
	while(ptr != NULL)
	{
		ptr = ptr->link;
		ctr++;
	}
	printf("Total number of elements: %d",ctr);
}//End Count List

//Reerse List
void reverseList()
{
	struct node *p1,*p2,*p3;
	
	if(start->link == NULL)
		return;
	p1 = start;
	p2 = start->link;
	p3 = p2->link;
	p1->link = NULL;
	p2->link = p1;
	
	while(p3 != NULL)
	{
		p1 = p2;
		p2 = p3;
		p3 = p3->link;
		p2->link = p1;
	}	
	start = p2;
}//End Reverse List

//Search Element
void search(int item)
{
	struct node *ptr;
	int count=1;
	ptr = start;
	
	while(ptr != NULL)
	{
		if(ptr->data == item)
		{
			printf("Element found at index %d",count);
			return;
		}
		count++;
		ptr = ptr->link;
	}
	if(ptr == NULL)
		printf("Element not found...\n");
}//End Search Element


