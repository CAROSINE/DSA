
#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct L{
    int info;
    struct L *next;
};

typedef struct L List;

void Display(List *Start)
{
    List *Ptr = Start;
    while(Ptr!= NULL)
    {
        printf("%6d",Ptr->info);
        Ptr = Ptr->next;
    }
}

List *CreateList(List *Start,int n)
{
    List *Ptr;
    while(n)
    {
        if(Start == NULL)
        {
            Start = (List *)malloc(sizeof(List));
            Start->info = (rand() %1000) + 1;
            Start->next = NULL;
            Ptr = Start;
        }
        else
        {
            Ptr->next = (List *)malloc(sizeof(List));
            Ptr = Ptr->next;
            Ptr->info = (rand() %1000) + 1;
            Ptr->next = NULL;
        }
        n--;
    }
    return Start;

}

void main()
{
    int i,n;
    List *Start = NULL;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Create a Random Linked List\n");
        printf("2. Display the linked List\n");
        printf("3. Search an item from the list\n");
        printf("4. Create a Linked list avoiding duplicate numbers");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("Enter amount of items : ");
            scanf("%d",&n);
            if(n)
                Start = CreateList(Start,n);
            else
                printf("gjjglfdj");

            break;
        case '2':
            printf("\nThe list as follows\n");
            Display(Start);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
