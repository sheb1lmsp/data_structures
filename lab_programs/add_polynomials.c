#include<stdio.h>
#include<stdlib.h>

struct polynomial
{
	int coeff,pow;
	struct polynomial *link;
};
typedef struct polynomial NODE;
NODE *poly1 = NULL, *poly2 = NULL, *poly3 = NULL;

NODE *create_poly(), *add_poly(NODE *poly1, NODE *poly2);
void display(NODE *ptr);

void main()
{
	printf("Create first polynomial\n");
	poly1 = create_poly();
	printf("First polynomial : ");
	display(poly1);
	printf("\nCreate second polynomial\n");
	poly2 = create_poly();
	printf("Second polynomial : ");
	display(poly2);
	poly3 = add_poly(poly1, poly2);
	printf("\nAddition of two polynomials : ");
	display(poly3);
}

NODE *create_poly()
{
	int flag;
	NODE *newnode, *poly;
	newnode = (NODE*)malloc(sizeof(NODE));
	poly = newnode;
	do
	{
		printf("\nEnter the coeff..\n");
		scanf("%d", &newnode->coeff);
		printf("Enter the power..\n");
		scanf("%d", &newnode->pow);
		newnode->link = NULL;
		printf("Do you want to add more? (Y=1 / N=0)");
		scanf("%d", &flag);
		if(flag==1)
		{
			newnode->link = (NODE*)malloc(sizeof(NODE));
			newnode = newnode->link;
			newnode->link = NULL;
		}
	} while(flag);
	return(poly);
}

NODE *add_poly(NODE *poly1, NODE *poly2)
{
	NODE *newnode, *poly;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->link = NULL;
	poly = newnode;

	while(poly1 && poly2)
	{
		if(poly1->pow > poly2->pow)
		{
			newnode->pow = poly1->pow;
			newnode->coeff = poly1->coeff;
			poly1 = poly1->link;
		}
		else if(poly1->pow < poly2->pow)
		{
			newnode->pow = poly2->pow;
			newnode->coeff = poly2->coeff;
			poly2 = poly2->link;
		}
		else
		{
			newnode->pow = poly1->pow;
			newnode->coeff = poly1->coeff + poly2->coeff;
			poly1 = poly1->link;
			poly2 = poly2->link;
		}
		if(poly1 && poly2)
		{
			newnode->link = (NODE*)malloc(sizeof(NODE));
			newnode = newnode->link;
			newnode->link = NULL;
		}
	}
	while(poly1 || poly2)
	{
		newnode->link = (NODE*)malloc(sizeof(NODE));
		newnode = newnode->link;
		newnode->link = NULL;	
		if(poly1)
		{
			newnode->pow = poly1->pow;
			newnode->coeff = poly1->coeff;
			poly1 = poly1->link;
		}
		if(poly2)
		{
			newnode->pow = poly2->pow;
			newnode->coeff = poly2->coeff;
			poly2 = poly2->link;
		}
	}
	return(poly);
}

void display(NODE *ptr)
{
	while(ptr != NULL)
	{
		printf("%dx^%d ", ptr->coeff, ptr->pow);
		ptr = ptr->link;
		if(ptr != NULL)
			printf("+ ");
	}
}