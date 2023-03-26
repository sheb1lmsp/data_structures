#include <stdio.h>

void main()
{
	int a[10][10], sparse[10][10], transpose[10][10];
	int i, j, m, n, s=0;
	printf("Enter the rows and columns of matrix\n");
	scanf("%d%d", &m, &n);
	printf("Enter the %d matrix elements\n", m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
		}
	}
	printf("The matrix is\n");
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			printf("%d\t", a[i][j]);
		}
		printf("\n");
	}
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			if(a[i][j] != 0)
			{
				sparse[s][0] = i;
				sparse[s][1] = j;
				sparse[s][2] = a[i][j];
				transpose[s][0] = j;
				transpose[s][1] = i;
				transpose[s][2] = a[i][j];
				s++;
			}
		}
	}
	printf("The sparse matrix is\n");
	for(i=0;i<s;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t", sparse[i][j]);
		}
		printf("\n");
	}
	printf("The transpose of sparse matrix is\n");
	for(i=0;i<s;i++)
	{
		for(j=0;j<3;j++)
		{
			printf("%d\t", transpose[i][j]);
		}
		printf("\n");
	}
}