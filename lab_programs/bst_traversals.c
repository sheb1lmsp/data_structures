#include<stdio.h>
#include<stdlib.h>


struct node
{
	int info;
	struct node *left, *right;
};
typedef struct node NODE;
NODE *root = NULL;

void insert(int value)
{
	NODE *newnode, *p, *currptr;
	newnode = (NODE*)malloc(sizeof(NODE));
	newnode->info = value;
	newnode->left = newnode->right = NULL;
	if(root == NULL)
	{
		root = newnode;
	}
	else
	{
		currptr = root;
		while(currptr)
		{
			p = currptr;
			if(newnode->info > currptr->info)
			{
				currptr = currptr->right;
			}
			else
			{
				currptr = currptr->left;
			}
		}
		if(newnode->info > p->info)
		{
			p->right = newnode;
		}
		else
		{
			p->left = newnode;
		}
	}
}

void inorder(NODE *root)
{
	if(root!=NULL)
	{
		inorder(root->left);
		printf("%d\t", root->info);
		inorder(root->right);
	}
}

void preorder(NODE *root)
{
	if(root!=NULL)
	{
		printf("%d\t", root->info);
		preorder(root->left);
		preorder(root->right);
	}
}

void postorder(NODE *root)
{
	if(root!=NULL)
	{
		postorder(root->left);
		postorder(root->right);
		printf("%d\t", root->info);
	}
}

void main()
{
	insert(2);
	insert(5);
	insert(1);
	insert(3);
	insert(9);
	insert(0);
	insert(6);
	printf("\nPreorder : ");
	preorder(root);
	printf("\nInorder : ");
	inorder(root);
	printf("\nPostorder : ");
	postorder(root);
}