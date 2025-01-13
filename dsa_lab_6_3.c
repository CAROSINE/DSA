#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct a{
    int item;
    struct a *next;
};

typedef struct a Queue;

void QueueInsert(Queue **Front,Queue **Rear,int item)
{
    if(*Front == NULL && *Rear == NULL)
    {
        *Front = (Queue *)malloc(sizeof(Queue));
        (*Front)->item = item;
        (*Front)->next = NULL;
        *Rear = *Front;
    }
    else
    {
        (*Rear)->next = (Queue *)malloc(sizeof(Queue));
        *Rear = (*Rear)->next;
        (*Rear)->item = item;
        (*Rear)->next = NULL;
    }
}

int QueueDelete(Queue **Front,Queue **Rear)
{
    int item;
    if(*Front == *Rear)
    {
        item = (*Front)->item;
        *Front = NULL;
        *Rear = NULL;
    }
    else
    {
       item = (*Front)->item;
       *Front = (*Front)->next;
    }
    return item;
}

void DisplayQueue_Recursion(Queue *Front)
{
    if(Front->next != NULL)
        DisplayQueue_Recursion(Front->next);
    printf("%5d",Front->item);
}

void DisplayQueue(Queue *Front)
{
    Queue *Ptr;
    Ptr = Front;
    while(Ptr != NULL)
    {
        printf("%5d",Ptr->item);
        Ptr = Ptr->next;
    }
}

void main()
{
    int i,item;
    char op;
    Queue *Front = NULL, *Rear = NULL;
    srand(time(NULL));
    while(1)
    {
        printf("\n1. Queue Insert \n");
        printf("2. Queue Delete\n");
        printf("3. Display the Queue\n");
        printf("4. Display the Queue in Front Way\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter a value to insert into queue : ");
            scanf("%d",&item);
            QueueInsert(&Front,&Rear,item);
            break;
        case '2':
            if(Front != NULL && Rear != NULL)
            {
                item = QueueDelete(&Front,&Rear);
                printf("\nDeleted item from Queue is %d",item);
            }
            else
                printf("\nEmpty Queue\n");
            break;
        case '3':
            if(Front != NULL)
            {
                printf("\nAvailable Items in the Queue\n");
                DisplayQueue(Front);
            }
            else
                printf("\nEmpty Queue\n");
            break;
        case '4':
            if(Front != NULL)
            {
                printf("\nAvailable Items in the Queue\n");
                DisplayQueue_Recursion(Front);
            }
            else
                printf("\nEmpty Queue\n");
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
