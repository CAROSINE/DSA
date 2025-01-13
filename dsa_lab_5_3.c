#include<stdio.h>
#include<stdlib.h>
#include<time.h>



struct T{
    int info;
    struct T *Ford;
    struct T *Back;
};

typedef struct T TWList;

void CreateTWList(TWList **First,TWList **Last,int n)
{
    TWList *Ptr;
    while(n)
    {
        if(*First == NULL && *Last == NULL)
        {
            *First = (TWList *)malloc(sizeof(TWList));
            (*First)->info = (rand() % 1000) + 1;
            (*First)->Back = NULL;
            (*First)->Ford = NULL;
            *Last = *First;
            Ptr = *First;
        }
        else
        {
            Ptr->Ford = (TWList *)malloc(sizeof(TWList));
            Ptr->Ford->info = (rand() % 1000) + 1;
            Ptr->Ford->Ford = NULL;
            Ptr->Ford->Back = Ptr;
            Ptr = Ptr->Ford;
            *Last = Ptr;
        }
     n--;
    }
}

void Traverse_First(TWList *First)
{
    TWList *Ptr;
    Ptr = First;
    while(Ptr != NULL)
    {
        printf("%5d",Ptr->info);
        Ptr = Ptr->Ford;
    }
}

void Traverse_Back(TWList *Last)
{
    TWList *Ptr;
    Ptr = Last;
    while(Ptr != NULL)
    {
        printf("%5d",Ptr->info);
        Ptr = Ptr->Back;
    }
}


void main()
{
    int i,n;
    TWList *First = NULL,*Last = NULL;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Create a Random Two-Way Linked List\n");
        printf("2. Traverse the Two-Way Linked List\n");
        printf("3. Search an item from Two-Way List\n");
        printf("4. Create a Sorted Linked List\n");
        printf("5. Insert item Into the Two-Way List\n");
        printf("6. Delete an item from the Two-Way List\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter amount of items : ");
            scanf("%d",&n);
            CreateTWList(&First,&Last,n);
            break;
        case '2':
            printf("\nThe list Forward Traverse\n");
            Traverse_First(First);
            printf("\nThe list Backward Traverse\n");
            Traverse_Back(Last);

            break;
        case '5':

            break;
        case '0':
            exit(0);
            break;
        }
    }
}
