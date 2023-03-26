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
}

void display()
{
	int i;
	if(front==-1)
		printf("\nQueue is empty\n");
	else
	{
		printf("\nQueue elements : ");
		for(i=front;i<=rear;i++)
			printf("%d\t", queue[i]);
	}
}

void enqueue(int item)
{
	if(rear == max-1)
		printf("\nQueue overflow\n");
	else
	{
		if(front == -1)
			++front;
		++rear;
		queue[rear] = item;
	}
}

void dequeue()
{
	if(front == -1 || front > rear)
		printf("\nQueue underflow\n");
	else
	{
		printf("\nElement %d deleted from the queue\n", queue[front]);
		++front;
	}
}