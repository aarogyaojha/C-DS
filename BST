#include<stdio.h>
#include<stdlib.h>
struct Btree
{
	int item;
	struct Btree *lchild,*rchild;
};
typedef struct Btree node;
node *p,*temp,*prev,*root;

void create(int num)
{
	p = (node*)malloc(sizeof(node));
	p->item = num;
	p->lchild = p->rchild = NULL;
	if(root == NULL)
	{
		root = p;
		return;
	}
	temp = root;
	while(temp!=NULL)
	{
		
		if(num<=temp->item)
		{
			prev = temp;
			temp = temp->lchild;
		}
		else if(num>temp->item)
		{
			prev = temp;
			temp = temp->rchild;
		}
		
	}
	if(num>prev->item)
	{
		prev->rchild = p;
	}
	else if(num<prev->item)
	{
		prev->lchild = p;
	}
}

void inorder(node *temp)
{
	if(temp!=NULL)
	{
		inorder(temp->lchild);
		printf("%d\n",temp->item);
		inorder(temp->rchild);
	}
}

void preorder(node *temp)
{
	if(temp!=NULL)
	{
		printf("%d\n",temp->item);
		preorder(temp->lchild);
		preorder(temp->rchild);
	}
}

void postorder(node *temp)
{
	if(temp!=NULL)
	{
		postorder(temp->lchild);
		postorder(temp->rchild);
		printf("%d\n",temp->item);
	}
}

void search(node *temp,int data)
{
	if(temp==NULL)
	{
		printf("Element not found!");
	}
	else if(data<temp->item)
	{
		search(temp->lchild,data);
	}
	else if(data>temp->item)
	{
		search(temp->rchild,data);
	}
	else if(data==temp->item)
	{
		printf("Element Found!");
	}
}

int main()
{
	int choice,n,ele,key;
	while (1) 
	{
		printf("\n---------------------- Menu------------------------\n");
		printf("1.Insert in TREE\n2.Inorder\n3.Preorder\n4.Postorder\n5.Search\n6.Exit\n");
		printf("Enter the choice you want to Perform:\n");
		scanf("%d",&choice);
		switch (choice)
		{
			case 1: printf("Ente the number of elements: ");
					scanf("%d",&n);
					for(int i=0;i<n;i++)
					{
						printf("Enter the element to be inserted: ");
						scanf("%d",&ele);
						create(ele);
					}
					break;
			case 2: inorder(root);
					break;
			case 3: preorder(root);
					break;
			case 4: postorder(root);
					break;
			case 5: printf("Enter the element to search: ");
					scanf("%d",&key);
					search(root,key);
					break;
			case 6: exit(0);
					break;
			default: printf("Invalid Choice!");
		}
	}
}
