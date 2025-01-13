#include<stdio.h>
#include<stdlib.h>
char *MySubString(char *str,int in, int nofc)
{
    char *sub = (char *)malloc(nofc);
    int i = 0;
    while(nofc)
    {
        sub[i] = str[in+i];
        i++;
        nofc--;
    }
    sub[i] = '\0';
    return sub;
}

int MyStrLength(char *str)
{
    int l = 0;
    while(str[l])
    {
        l++;
    }
    return l;
}

char *MyConcate(char *str1,char *str2)
{
    char *con = (char *)malloc(MyStrLength(str1) + MyStrLength(str2));
    int i = 0;
    while(str1[i])
    {
        con[i] = str1[i];
        i++;
    }
    int j = 0;
    while(str2[j])
    {
        con[i+j] = str2[j];
        j++;
    }
    con[i+j] = '\0';
    return con;
}


void main()
{
    char op;
    int in, nofc;
    char Str1[100],Str2[100], *Str3;
    while(1)
    {
        printf("\n1. Input a String\n");
        printf("2. Length of the String\n");
        printf("3. Display the String\n");
        printf("4. Sub-string of the String\n");
        printf("5. Concatenation of two String\n");
        printf("6. Index\n");
        printf("7. Insert\n");
        printf("8. Replace\n");
        printf("9. Delete\n");

        printf("0. Exit\nEnter your option : ");
        op = getche();
        switch(op)
        {
        case '1':
            printf("\nEnter a line of text string:\n");
            gets(Str1);
            break;
        case '2':
            printf("\nThe length of the string is %d",MyStrLength(Str1));
            break;
        case '3':
            printf("\nInputted Sting is :\n");
            puts(Str1);
            break;
        case '4':
            printf("\nEnter the index of the sub-string : ");
            scanf("%d",&in);
            printf("Enter the NOFC of the sub-string : ");
            scanf("%d",&nofc);
            printf("\nThe sub string is\n");
            puts(MySubString(Str1,in,nofc));

            break;
        case '5':
            printf("\nEnter second string\n");
            gets(Str2);
            printf("\nConcated String is\n");
            Str3 = MyConcate(Str1,Str2);
            puts(Str3);
            break;
        case '0':
            exit(0);
            break;
        }
    }
}

