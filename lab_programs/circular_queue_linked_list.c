#include<stdio.h>
#include<stdlib.h>

struct node
{
	int info;
	struct node *link;
};

typedef struct node NODE;
NODE *f = NULL, *r = NULL;

void enqueue(int item), dequeue(int item), display();

void main()
{
	printf("Insertion..\n");
	enqueue(5);
	display();
	enqueue(7);
	display();
	enqueue(0);
	display();
	enqueue(6);
	display();
	enqueue(3);
	display();
	enqueue(9);
	display();
	printf("\nDeletion..\n");
	dequeue(6);
	display();
	dequeue(9);
	display();
	dequeue(5);
	display();
}

void enqueue(int item)
{
	NODE *newnode;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->info = item;
	if(f == NULL && r == NULL)
	{
		f = r = newnode;
		r->link = f;
	}
	else
	{
		r->link = newnode;
		r = newnode;
		r->link = f;
	}
}

void dequeue(int item)
{
	NODE *currptr = f, *prevptr = NULL;
	if(f == NULL && r == NULL)
	{
		printf("Queue underflow");
	}
	else if(f->info == item)
	{
		f = f->link;
		r->link = f;
		free(currptr);
	}
	else
	{
		do
		{
			prevptr = currptr;
			currptr = currptr->link;
		} while(currptr != f && currptr->info != item);
		if(currptr == f)
		{
			printf("The item is not found");
		}
		else
		{
			if(currptr == r)
			{
				r = prevptr;
			}
			prevptr->link = currptr->link;
			free(currptr);
		}
	}
}

void display()
{
	NODE *currptr = f;
	if(f == NULL && r == NULL)
	{
		printf("Queue is empty");
	}
	else
	{
		printf("\nQueue elements : ");
		do	
		{
			printf("%d -> ", currptr->info);
			currptr = currptr->link;
		} while(currptr != f);
	}
	printf("\n");
}