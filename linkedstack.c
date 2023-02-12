/* Online C Compiler and Editor */
#include <stdio.h>
#include <stdlib.h>

struct stack
{
    int data;
    struct stack *next;
};
typedef struct stack node;
node *ptr,*newnode,*ptr,*top;

int ele =0;

void create()
{
    newnode=(node*)malloc(sizeof(newnode));
    newnode->data=ele;
    newnode->next=NULL;
}

void push()
{
    printf("enter the element to push");
    scanf("%d",&ele);
    create(ele);
    if(top==NULL)
    {
        top=newnode;
    }
    else
    {
        newnode->next=top;
        top=newnode;
    }
}

int pop()
{
    if(top==NULL)
    {
        printf("STACK IS EMPTY\n");
        return 0;
    }
    else
    {
        ele=top->data;;
        ptr=top;
        top=ptr->next;
        free(ptr);
        printf("POPPED %d",ele);
        return 0;
    }
}

void display()
{
    ptr=top;
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
        printf("1.PUSH\n2.POP\n3.DISPLAY\n4.exit");
        printf("ENTER CH");
        scanf("%d",&ch);
        
        switch(ch)
        {
            case 1:push();
                    break;
            case 2:pop();
                    break;
            case 3:display();
                    break;
            case 4:exit(0);
                    break;
        }
    }

    return 0;
}
