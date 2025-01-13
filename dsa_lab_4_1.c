#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int Bubble(int *,int);
int LinearSearch(int *, int, int, int *);
int BinarySearch(int *, int, int, int *);
int Selection(int *,int);
void Display(int *A, int N)
{
    int i;
    for(i=0;i<N;i++)
    {
        printf("%5d",A[i]);
    }
}
void main()
{
    int i,n,loc,item, Data[10000],Data1[10000],bsc,ssc,lc = 0,bc = 0;
    srand(time(NULL));
    clock_t begin,end;
    double time_spent;

    char op;
    while(1)
    {
        printf("\n1. Create an Array\n");
        printf("2. Display the Array\n");
        printf("3. Sort the Array using Bubble Sort\n");
        printf("4. Sort the Array using Selection Sort\n");
        printf("5. Search an Item using linear search\n");
        printf("6. Search an Item using Binary search\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter the amount of numbers: ");
            scanf("%d",&n);
            for(i=0;i<n;i++)
            {
                Data[i] = Data1[i] = (rand() %1000);
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
            begin = clock();
            bsc = Bubble(Data,n);
            end = clock();
            printf("\nThe Bubble Sort is as follows:\n");
            Display(Data,n);
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nTotal time spend for Bubble Sort: %f Seconds\n",time_spent);
            printf("Total interchange %d",bsc);
            break;
        case '4':
            begin = clock();
            ssc = Selection(Data1,n);
            end = clock();
            printf("\nThe Selection Sort is as follows:\n");
            Display(Data1,n);
            time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
            printf("\nTotal time spend for Selection Sort: %f Seconds\n",time_spent);
            printf("Total interchange %d",ssc);
            break;
        case '5':
            printf("\nEnter the item for search : ");
            scanf("%d",&item);
            lc = 0;
            loc = LinearSearch(Data,n,item,&lc);
            if(loc == -1)
                printf("\nItem not found\n");
            else
                printf("\nItem found Using Linear Search in location %d\n",loc);
                printf("\nIn Linear Search Comparison %d\n",lc);

            break;
        case '6':
            bc = 0;
            loc = BinarySearch(Data,n,item,&bc);
            if(loc == -1)
                printf("\nItem not found\n");
            else
                printf("\nItem found Using Binary Search in location %d\n",loc);
                printf("\nIn Binary Search Comparison %d\n",bc);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}

int Bubble(int *Data,int N)
{
    int k,ptr,temp,count = 0;
    for(k=0;k<N-1;k++)
    {
        ptr = 0;
        while(ptr < N-k-1)
        {
            if(Data[ptr] > Data[ptr+1])
            {
                count++;
                temp = Data[ptr];
                Data[ptr] = Data[ptr+1];
                Data[ptr+1] = temp;
            }
            ptr++;
        }
    }
    return count;
}

int LinearSearch(int *Data, int N, int item, int *count)
{
    int i,loc = -1;
    for(i = 0;i < N; i++)
    {
        (*count)++;
        if(item == Data[i])
        {
            loc = i;
            break;
        }
    }
    return loc;
}

int BinarySearch(int *Data, int N, int item,int *count)
{
    int Beg = 0,Loc;
    int End = N-1;
    int Mid = (int)(End + Beg)/2;
    while(Beg <= End && Data[Mid] != item)
    {
        (*count)++;
        if(item < Data[Mid])
            End = Mid -1;
        else
            Beg = Mid + 1;
        Mid = (int)(End + Beg)/2;

    }
    if(Data[Mid] == item)
        Loc = Mid;
    else
        Loc = -1;
    return Loc;
}
int MIN(int *A,int K,int N)
{
    int Min = A[K],Loc = K,J;
    for(J=K+1;J<=N;J++)
    {
        if(Min > A[J])
        {
            Min = A[J];
            Loc = J;
        }
    }
    return Loc;
}
int Selection(int *A,int N)
{
    int K,Loc,Temp;
    int count = 0;
    for(K=0;K<N-1;K++)
    {
        Loc = MIN(A,K,N-1);
        if(A[K] > A[Loc])
        {
            Temp = A[Loc];
            A[Loc] = A[K];
            A[K] = Temp;
            count++;
        }
    }
    return count;
}
