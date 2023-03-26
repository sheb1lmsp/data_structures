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

NODE *minvalue(NODE *node)
{
    NODE *current = node;
 
    /* loop down to find the leftmost leaf */
    while (current && current->left != NULL)
        current = current->left;
    return(current);
}

NODE *delete(NODE *root, int item)
{
    if (root == NULL)
        return(root);
 
    // If the item to be deleted is smaller than the root's info, then it lies in left subtree
    if (item < root->info)
        root->left = delete(root->left, item);
 
    // If the item to be deleted is greater than the root's info, then it lies in right subtree
    else if (item > root->info)
        root->right = delete(root->right, item);
 
    // if item is same as root's info, then This is the node to be deleted 
    else 
	{
        // node with only one child or no child
        if (root->left == NULL) 
		{
            NODE *temp = root->right;
            free(root);
            return(temp);
        }
        else if (root->right == NULL)
		{
            NODE *temp = root->left;
            free(root);
            return temp;
        }
 
        // node with two children: Get the inorder successor (smallest in the right subtree)
        NODE *temp = minvalue(root->right);
 
        // Copy the inorder successor's content to this node
        root->info = temp->info;
 
        // Delete the inorder successor
        root->right = delete(root->right, temp->info);
    }
	return(root);
}

void main()
{
	insert(18);
	insert(15);
	insert(40);
	insert(50);
	insert(30);
	insert(17);
	insert(41);
	printf("\nInorder : ");
	inorder(root); 
	insert(45);
	printf("\nInorder : ");
	inorder(root);
	insert(19);
	printf("\nInorder : ");
	inorder(root);
	root = delete(root, 15);
	printf("\nInorder : ");
	inorder(root); 
	root = delete(root, 17);
	printf("\nInorder : ");
	inorder(root); 
	root = delete(root, 41);
	printf("\nInorder : ");
	inorder(root); 
}