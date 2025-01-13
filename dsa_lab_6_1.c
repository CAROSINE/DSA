
#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct S{
    int info;
    struct S *next;
};

typedef struct S Stack;


Stack *PUSH(Stack *Top,int n)
{
    Stack *New  = (Stack *)malloc(sizeof(Stack));
    New->info = n;
    New->next = Top;
    Top = New;
    return Top;
}
Stack *Pop(Stack *Top,int *item)
{
    if(Top == NULL)
    {
        *item = 0;
        return Top;
    }
    else
    {
        *item = Top->info;
        Top = Top->next;
        return Top;
    }
}

void main()
{
    int i,item;
    Stack *Top = NULL;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Stack Push Operation Using Link List \n");
        printf("2. Stack Pop Operation Using Link List \n");
        printf("3. Display Stack\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter a value for push : ");
            scanf("%d",&item);
            Top = PUSH(Top,item);

            break;
        case '2':
            Top = Pop(Top,&item);
            if(item == 0)
                printf("\nStack Underflow\n");
            else
                printf("\n Popped item is %d",item);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
