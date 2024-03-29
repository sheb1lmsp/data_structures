#include<stdio.h>

void create_hashtable(int *a, int *HT, int n, int tabsize);
int hash_search(int *HT, int tabsize, int element);

void main()
{
	int n, i, tabsize, element, index;
	printf("Enter the length of the array\n");
	scanf("%d", &n);
	int a[n];
	printf("Enter the array elements\n");
	for(i=0;i<n;i++)
	{
		scanf("%d", &a[i]);
	}
	printf("Enter the hashtable size\n");
	scanf("%d", &tabsize);
	int HT[tabsize];
	create_hashtable(a, HT, n, tabsize);
	printf("Enter the element to be searched\n");
	scanf("%d", &element);
	index = hash_search(HT, tabsize, element);
	printf("The element %d found at index %d\n", element, index);
}

void create_hashtable(int *a, int *HT, int n, int tabsize)
{
	int i, j, k,pos;
	for(i=0;i<tabsize;i++)
	{
		HT[i] = -1;
	}
	for(i=0;i<n;i++)
	{
		pos = a[i] % tabsize;
		if(HT[pos] == -1)
		{
			HT[pos] = a[i];
		}
		else
		{
			j = (pos+1) % tabsize;
			k =2;
			while(j!=pos)
			{
				if(HT[j]==-1)
				{
					HT[j] = a[i];
					break;
				}
				else
				{
					j = (pos+k*k) % tabsize;
					k++;
				}
			}
		}
	}
	printf("Hash table..\n-----------\n");
	printf("Index\t\tElements\n");
	for(i=0;i<tabsize;i++)
	{
		printf("%d\t\t%d\n", i, HT[i]);
	}
}

int hash_search(int *HT, int tabsize, int element)
{
	int j, k, pos;
	pos = element % tabsize;
	if(HT[pos] == element)
	{
		return(pos);
	}
	else
	{
		j = (pos+1) % tabsize;
		k =2;
		while(j!=pos)
		{
			if(HT[j]==-1)
			{
				return j;
			}
			else
			{
				j = (pos+k*k) % tabsize;
				k++;
			}
		}
	}
	return(-1);
}