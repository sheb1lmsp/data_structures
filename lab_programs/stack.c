#include<stdio.h>
#include<stdlib.h>

#define maxstk 5
int top = -1;
int s[maxstk];
void push(), pop(), display();

void main()
{
	int choice;
	while(1)
	{
		printf("\n1 : push\n2 : pop\n3 : display\n4 : Quit\nEnter your choice\n");
		scanf("%d", &choice);
		switch(choice)
		{
			case 1 : push();
					 break;
			case 2 : pop();
				 	 break;
			case 3 : display();
				 	 break;
			case 4 : exit(1);
			default : printf("\nWrong choice\n");
		}
	}
}

void push()
{
	int item;
	if(top == (maxstk-1))
	{
		printf("\nStack Overflow");
	}
	else
	{
		printf("Enter the item to be pushed\n");
		scanf("%d", &item);
		++top;
		s[top] = item;
	}
}

void pop()
{
	if(top==-1)
	{
		printf("\nStack underflow");
	}
	else
	{
		printf("\nPopped item is %d", s[top]);
		--top;
	}
}

void display()
{
	int i;
	if(top==-1)
	{
		printf("\nStack is empty");
	}
	else
	{
		printf("Stack elements are\n");
		for(i=top;i>=0;i--)
		{
			printf("%d\n", s[i]);
		}
	}
}