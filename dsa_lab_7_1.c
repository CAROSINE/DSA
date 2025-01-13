#include<stdio.h>
#include<stdlib.h>
#include<time.h>



struct T{
    int Info;
    struct T *Left;
    struct T *Right;
};

typedef struct T Tree;

void Find(Tree *Root,int item,Tree **Loc,Tree **Par)
{
    Tree *Ptr,*Save;
    if(Root == NULL)    {   *Loc = NULL; *Par = NULL; return;   }
    if(item == Root->Info)  {   *Loc = Root; *Par = NULL;   return; }
    if(item < Root->Info) {  Ptr = Root->Left; Save = Root; }
    else {  Ptr = Root->Right;   Save = Root; }
    while(Ptr != NULL)
    {
        if(item == Ptr->Info) { *Loc = Ptr; *Par = Save; return; }
        if(item < Ptr->Info)
            {  Save = Ptr; Ptr = Ptr->Left;  }
        else
            {  Save = Ptr; Ptr = Ptr->Right;  }
    }
    *Loc = NULL; *Par = Save;   return;
}


Tree *InsBST(Tree *Root,int Item)
{
    Tree *Loc,*Par,*New;
    Find(Root,Item,&Loc,&Par);
    if(Loc != NULL) return Root;
    New = (Tree *)malloc(sizeof(Tree));
    New->Info = Item;
    Loc = New; New->Left = NULL;    New->Right = NULL;
    if(Par == NULL) Root = New;
    else if(Item < Par->Info)   Par->Left = New;
    else    Par->Right = New;
    return Root;
}

void PreOrder(Tree *Root)
{
    printf("%5d",Root->Info);
    if(Root->Left != NULL) PreOrder(Root->Left);
    if(Root->Right != NULL) PreOrder(Root->Right);
}
void InOrder(Tree *Root)
{
    if(Root->Left != NULL) InOrder(Root->Left);
    printf("%5d",Root->Info);
    if(Root->Right != NULL) InOrder(Root->Right);
}
void PostOrder(Tree *Root)
{
    if(Root->Left != NULL) PostOrder(Root->Left);
    if(Root->Right != NULL) PostOrder(Root->Right);
    printf("%5d",Root->Info);
}
void main()
{
    int i,n,item;
    char op;
    Tree *Root = NULL;
    srand(time(NULL));
    while(1)
    {
        printf("\n1. Create a Binary Search Tree \n");
        printf("2. Pre-order Traverse\n");
        printf("3. In-order Traverse\n");
        printf("4. Post-order Traverse\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nHow many numbers : ");
            scanf("%d",&n);
            while(n)
            {
                item = (rand() % 50) + 1;
                printf("%5d",item);
                Root = InsBST(Root,item);
                n--;
            }
            break;
        case '2':
            printf("\nPre-order Traverse is\n");
            PreOrder(Root);
            break;
        case '3':
            printf("\nIn-order Traverse is\n");
            InOrder(Root);
            break;
        case '4':
            printf("\nPost-order Traverse is\n");
            PostOrder(Root);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}

