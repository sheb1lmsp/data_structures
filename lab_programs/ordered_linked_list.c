#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node NODE;
NODE *start = NULL;

void insert(int item), delete(int item), display();

void main()
{
	printf("Insertion..\n");
	insert(61);
	display();
	insert(16);
	display();
	insert(8);
	display();
	insert(27);
	display();
	printf("\nDeletion..\n");
	delete(8);
	display();
	delete(61);
	display();
	delete(27);
	display();
}

void display()
{
	NODE *currptr = start;
	printf("\n*** LIST *** : ");
	while(currptr!=NULL)
	{
		printf("%d -> ", currptr->info);
		currptr = currptr->link;
	}
	printf("\n");
}

void insert(int item)
{
	NODE *newnode, *currptr = start, *prevptr = NULL;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->info = item;

	if(start==NULL)
	{
		start = newnode;
		newnode->link = NULL;
	}

	else if(item < start->info)
	{
		newnode->link = start;
		start = newnode;
	}

	else
	{
		do
		{	
			prevptr = currptr;
			currptr = currptr->link;
		} while(currptr!=NULL && item > currptr->info);
		
		prevptr->link = newnode;
		newnode->link = currptr;
	}
}

void delete(int item)
{
	NODE *currptr = start, *prevptr = NULL;
	if(start==NULL)
	{
		printf("\nEmpty List\n");
	}
	else if(start->info == item)
	{
		start = start->link;
		free(currptr);
	}
	else
	{
		do
		{
			prevptr = currptr;
			currptr = currptr->link;
		} while(currptr!=NULL && currptr->info != item);

		if(currptr==NULL)
		{
			printf("The item is not found in the linked list");
		}
		else
		{
			prevptr->link = currptr->link;
			free(currptr);
		}
	}
}