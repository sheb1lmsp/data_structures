#include<stdio.h>
#define max 10
int queue[max], rear = -1, front = -1;

void enqueue(int item), dequeue(), display();

void main()
{
	printf("Insertion..\n");
	enqueue(61);
	display();
	enqueue(16);
	display();
	enqueue(8);
	display();
	enqueue(27);
	display();
	printf("\nDeletion..\n");
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
	dequeue();
	display();
}

void enqueue(int item)
{
	if(front == (rear+1)%max)
		printf("\nQueue overflow\n");
	else
	{
		if(rear==-1)
			front = rear = 0;
		else
			rear = (rear+1)%max;
		queue[rear] = item;
	}
}

void dequeue()
{
	if(front == -1)
		printf("\nQueue underflow\n");
	else if (front == rear)
		front = rear = -1;
	else
		front = (front+1)%max;
}

void display()
{
	int i;
	if(front == -1)
		printf("\nQueue is empty\n");
	else if(front > rear)
	{
		printf("\nQueue elements : ");
		for(i=front;i<max;i++)
			printf("%d\t", queue[i]);
		for(i=0;i<=rear;i++)
			printf("%d\t", queue[i]);
	}
	else
	{
		printf("\nQueue elements : ");
		for(i=front;i<=rear;i++)
			printf("%d\t", queue[i]);
	}
}