#include<stdio.h>

int count = 0;
void toh(int n, char src, char temp, char dest);


void main()
{
	char src = 'S', temp = 'T', dest = 'D';
	int n;
	printf("Enter the no. of disks\n");
	scanf("%d", &n);
	printf("Sequence..\n");
	toh(n, src, temp, dest);
	printf("Total no.of moves is %d", count);
}

void toh(int n, char src, char temp, char dest)
{
	if(n>0)
	{
		toh(n-1,src,dest, temp);
		printf("disk %d moved from %c to %c\n", n, src, dest);
		count++;
		toh(n-1,temp,src, dest);
	}
}