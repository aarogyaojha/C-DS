#include <stdio.h>
#include <stdlib.h>
int i,ele;
struct dll
{
    int data;
    struct dll *next,*prev;
};
typedef struct dll node;
node *start,*ptr,*temp,*newnode;

int ele=0;

void create()
{
    newnode=(node*)malloc(sizeof(node));
    newnode->prev=NULL;
    printf("enter the element");
    scanf("%d",&newnode->data);
    newnode->next=NULL;
}

void createdll()
{
    int n;
    printf("HOW MANY NODES HUH??");
    scanf("%d",&n);
    for(i=1;i<=n;i++)
    {
        create(ele);
        if(i==1)
        {
            start=newnode;
        }
        else
        {
            ptr=start;
            while(ptr->next!=NULL)
                ptr=ptr->next;
            ptr->next=newnode;
            newnode->next=NULL;
            newnode->prev=ptr;
        }
    }
}

void display()
{
    ptr=start;
    int count=0;
    while(ptr!=NULL)
    {
        count++;
        printf("%d->",ptr->data);
        ptr=ptr->next;
    }
    printf("the number of nodes=%d",count);
}

void insertatf()
{
    create();
    newnode->next=start;
    newnode->prev=NULL;
    start=newnode;
}

void insertate()
{
    create();
    ptr=start;
    while(ptr->next!=NULL)
    {
        ptr=ptr->next;
    }
    ptr->next=newnode;
    newnode->next=NULL;
    newnode->prev=ptr;
}

void delatf()
{
    temp=start;
    start=temp->next;
    free(temp);
    printf("F NODE DELETED");
}
void delate()
{
    ptr=start;
    while(ptr->next!=NULL)
    {
        temp=ptr;
        ptr=ptr->next;
    }
    free(ptr);
    temp->next=NULL;
    printf("last node deleted");
}

int main()
{
    int ch;
    while(1)
    {
        printf("1.create\n2.DISPLAY AND COUNT\n3.INSERT AT FRONT\n4.INSERT AT LAST\n5.DELETE FROM FRONT\n6.DELETE FROM LAST\n7EXIT");
        printf("ENTER CH");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:createdll();
                    break;
            case 2:display();
                    break;
            case 3:insertatf();
                    break;
            case 4:insertate();
                    break;
            case 5:delatf();
                    break;
            case 6:delate();
                    break;
            case 7:exit(0);
                    break;
        }
    }

    return 0;
}
