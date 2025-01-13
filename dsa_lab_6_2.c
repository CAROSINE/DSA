#include<stdio.h>
#include<stdlib.h>
#include<time.h>


struct S{
    char info;
    struct S *next;
};

typedef struct S Stack;

int MyStrLength(char *str)
{
    int l = 0;
    while(str[l])
    {
        l++;
    }
    return l;
}

Stack *Push(Stack *Top,char n)
{
    Stack *New  = (Stack *)malloc(sizeof(Stack));
    New->info = n;
    New->next = Top;
    Top = New;
    return Top;
}
Stack *Pop(Stack *Top,char *item)
{
    if(Top == NULL)
    {
        *item = '\0';
        return Top;
    }
    else
    {
        *item = Top->info;
        Top = Top->next;
        return Top;
    }
}
int isOperand(char sym)
{
    if(sym >= 'A' && sym <= 'Z')    return 1;
    else if(sym >= '0' && sym <= '9')    return 1;
    else return 0;
}
int isOperator(char sym)
{
    if(sym =='+' || sym == '-' || sym == '*' || sym == '/' || sym == '^') return 1;
    else return 0;
}
int Precedance(char sym)
{
    if(sym == '^') return 5;
    if(sym == '/') return 4;
    if(sym == '*') return 3;
    if(sym == '+') return 2;
    if(sym == '-') return 1;

}

char *POLISH(char *Q)
{
    Stack *Top = NULL;
    char topopt,sym,*P;
    Top = Push(Top,'(');
    int L = MyStrLength(Q);
    Q[L] = ')'; Q[L+1] = '\0';
    int count = 0, i = 0,pi = 0;
    P = (char *)malloc(L);

    while(Top != NULL)
    {
        sym = Q[i];
        //3
        if(isOperand(sym))
        {
            P[pi++] = sym;
        }
        //4
        if(sym == '(') Top = Push(Top,sym);
        //5
        if(isOperator(sym))
        {
            Top = Pop(Top,&topopt);
            while(isOperator(topopt))
            {
                if(Precedance(topopt) >= Precedance(sym))
                {
                    P[pi++] = topopt;
                    Top = Pop(Top,&topopt);
                }
                else
                    break;
            }
            Top = Push(Top,topopt);
            Top = Push(Top,sym);
        }
        //6
        if(sym == ')')
        {
            Top = Pop(Top,&topopt);
            while(isOperator(topopt))
            {
                P[pi++] = topopt;
                Top = Pop(Top,&topopt);
            }
        }
        i++;
    }
    P[pi] = '\0';
    return P;
}
void main()
{
    int i;
    char item, Infix[100],Prefix[100],*Postfix;
    srand(time(NULL));
    char op;
    while(1)
    {
        printf("\n1. Input an Infix Expression \n");
        printf("2. Convert Infix to Prefix Expression\n");
        printf("3. Convert Infix to Postfix Expression\n");
        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter a valid Infix Expression : \n");
            gets(Infix);

            break;
        case '2':
            printf("\nPrefix Expression is\n");
            break;
        case '3':
            printf("\nPostfix Expression is\n");
            Postfix = POLISH(Infix);
            puts(Postfix);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}
