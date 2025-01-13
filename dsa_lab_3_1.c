#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int SearchItem(int *,int,int);

void Insert(int *,int *,int,int);
int Delete(int *,int,int);

void main()
{
    int i,n,loc,item, Data[10000];
    srand(time(NULL));

    char op;
    while(1)
    {
        printf("\n1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Search an item from the Array\n");
        printf("4. Insert an item into the Array\n");
        printf("5. Delete an item from the Array\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter the amount of numbers: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                Data[i] = (rand() %1000);
            }
            break;
        case '2':
            printf("\nThe %d Numbers are as follows:\n",n);
            for(i=0;i<n;i++)
            {
                printf("%5d",Data[i]);
            }
            break;
        case '3':
            printf("Enter the value, which you want to search : ");
            scanf("%d",&item);
            loc = SearchItem(Data,n,item);
            if(loc == -1)
                printf("Item not available in the list\n");
            else
                printf("Item %d available in location %d\n",item,loc);
            break;
        case '4':
                printf("\nEnter the Location for insert : ");
                scanf("%d",&loc);
                printf("Enter the item to insert : ");
                scanf("%d",&item);
                Insert(Data,&n,loc,item);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}

int SearchItem(int *LA,int N,int item)
{
    int i;
    for(i=0;i<N;i++)
    {
        if(item == LA[i])
        {
            return i;
        }
    }
    return -1;
}

void Insert(int *LA,int *N,int K,int item)
{
    int J = *N;
    while(J >= K)
    {
        LA[J+1] = LA[J];
        J--;
    }
    LA[K] = item;
    *N = *N + 1;
}
