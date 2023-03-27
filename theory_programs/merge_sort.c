#include <stdio.h>

void merge_sort(int *a, int lb, int ub);
void merge(int *a, int low, int mid, int high);

void main()
{
	int a[10], n, i;
	printf("Enter the size of the array\n");
	scanf("%d", &n);
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	merge_sort(a,0,n-1);
	printf("\nArray after merge sort\n");
	for(i=0;i<n;i++)
	{
		printf("%d\t", a[i]);
	}
}

void merge_sort(int *a, int low, int high)
{
	int mid;
	if(low<high)
	{
		mid = (low + high) / 2;
		merge_sort(a, low, mid);
		merge_sort(a, mid+1, high);
		merge(a, low, mid, high);
	}
}

void merge(int *a, int low, int mid, int high)
{
	int i, j, k, c[10];
	i = k = low;
	j = mid+1;
	while((i<=mid) && (j<=high))
	{
		if(a[i] <= a[j])
		{
			c[k++] = a[i++];
		}
		else
		{
			c[k++] = a[j++];
		}
	}
	while(i<=mid)
	{
		c[k++] = a[i++];
	}
	while(j<=high)
	{
		c[k++] = a[j++];
	}
	for(i=low;i<k;i++)
	{
		a[i] = c[i];
	}
}