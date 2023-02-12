#include <stdio.h>
#include <stdlib.h>

struct queue
{
    int data;
    struct queue *next;
};
typedef struct queue node;
node *ptr,*newnode,*ptr,*rear,*front,*temp;

int ele =0;
int rval;

void create()
{
    newnode=(node*)malloc(sizeof(newnode));
    newnode->data=ele;
    newnode->next=NULL;
}

void enqueue()
{
    printf("enter the element to push");
    scanf("%d",&ele);
    create(ele);
    if(rear==NULL)
    {
        rear=newnode;
        front=newnode;
    }
    else
    {
        rear->next=newnode;
        rear=newnode;
    }
}

int dequeue()
{
    if(front==NULL)
    {
        printf("QUEUE IS EMPTY\n");
        return 0;
    }
    else
    {
        temp=front;
        front=temp->next;
        rval=temp->data;
        free(temp);
        printf("the dequeued element %d",rval);
        return 0;
    }
}

void display()
{
    ptr=front;
    while(ptr!=NULL)
    {
        printf("%d\n",ptr->data);
        ptr=ptr->next;
    }
}

int main()
{
    int ch;
    while(1)
    {
        printf("1.enqueue\n2.dequeue\n3.DISPLAY\n4.exit");
        printf("ENTER CH");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:enqueue();
                    break;
            case 2:dequeue();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
        }
    }

    return 0;
}
