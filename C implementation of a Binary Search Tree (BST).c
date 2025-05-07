#include<stdio.h>
#include<stdlib.h>
#include<time.h>

struct T
{
    int Info;
    struct T *Left;
    struct T *Right;
};

typedef struct T Tree;


Tree *InsBST(Tree *,int);
Tree *Find(Tree *,int,Tree **);
void Inorder(Tree *);
void Preorder(Tree *);
void Postorder(Tree *);

void main()
{
    int item,n;

    Tree *T1 = NULL;

    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\nWell come Tree Programs\n");
        printf("1. Create a Binary Search Tree\n");
        printf("2. Tree Traversing (Pre-Order)\n");
        printf("3. Tree Traversing (In-Order)\n");
        printf("4. Tree Traversing (Post-Order)\n");
        printf("0. Exit\nEnter your option : ");

        op = getche();
        switch(op)
        {
            case '1':
                printf("\nHow many numbers : ");
                scanf("%d",&n);
                while(n)
                {
                    item = (rand() % 100);
                    printf("%5d",item);
                    T1 = InsBST(T1,item);
                    n--;
                }
            break;
            case '2':
                printf("\nPre-Order Traversing is \n");
                Preorder(T1);
                break;
            case '3':
                printf("\nIn-Order Traversing is \n");
                Inorder(T1);
                break;
            case '4':
                printf("\nPost-Order Traversing is \n");
                Postorder(T1);
                break;
            case '0':
                exit(0);
            break;
        }
    }
}

void Preorder(Tree *T)
{
    printf("%5d",T->Info);
    if(T->Left != NULL)
        Preorder(T->Left);
    if(T->Right != NULL)
        Preorder(T->Right);
}
void Inorder(Tree *T)
{
    if(T->Left != NULL)
        Inorder(T->Left);
    printf("%5d",T->Info);
    if(T->Right != NULL)
        Inorder(T->Right);
}
void Postorder(Tree *T)
{
    if(T->Left != NULL)
        Postorder(T->Left);
    if(T->Right != NULL)
        Postorder(T->Right);
    printf("%5d",T->Info);
}

Tree *Find(Tree *T,int item,Tree **Par)
{
    Tree *Ptr,*Save,*Loc;
    if(T == NULL)
    {
        Loc = NULL;
        (*Par) = NULL;
        return Loc;
    }
    if(item == T->Info)
    {
        Loc = T;
        (*Par) = NULL;
        return Loc;
    }
    if(item < T->Info)
    {
        Ptr = T->Left;
        Save = T;
    }
    else
    {
        Ptr = T->Right;
        Save = T;
    }
    while(Ptr != NULL)
    {
        if(item == Ptr->Info)
        {
            Loc = Ptr;
            *Par = Save;
            return Loc;
        }
        if(item < Ptr->Info)
        {
            Save = Ptr;
            Ptr = Ptr->Left;
        }
        else
        {
            Save = Ptr;
            Ptr = Ptr->Right;
        }
    }
    Loc = NULL;
    (*Par) = Save;
    return Loc;
}


Tree *InsBST(Tree *T,int item)
{
    Tree *New,*Loc,*Par;
    Loc = Find(T,item,&Par);
    if(Loc != NULL) return T;

    New = (Tree *)malloc(sizeof(Tree));
    New->Info = item;
    Loc = New;
    New->Left = NULL;
    New->Right = NULL;
    if(Par == NULL)
        T = New;
    else if(item < Par->Info)
        Par->Left = New;
    else
        Par->Right = New;
    return T;
}
