#include <stdio.h>

void main()
{
	int a[10][10], m, n, i, j, count=0;
	printf("Enter the number of rows and columns\n");
	scanf("%d%d", &m, &n);
	printf("Enter the %d matrix elements\n", m*n);
	for(i=0;i<m;i++)
	{
		for(j=0;j<n;j++)
		{
			scanf("%d", &a[i][j]);
			if(a[i][j] == 0)
			{
				count++;
			} 
		}
	}
	if(count > (m*n) / 2)
	{
		printf("The given matrix is a sparse matrix");
	}
	else
	{
		printf("The given matrix is not a sparse matrix");
	}
}