#include<stdio.h>
#include<stdlib.h>

void main()
{
     char op;
     while(1)
     {
         printf("1. Input a String\n");
         printf("2. Length of the String\n");
         printf("3. Sub-string of the String\n");
         printf("4. Concatenation of two String\n");
         printf("0. Exit\nEnter your option : ");
         op = getche();
        switch(op)
         {
             case '1':
                printf("ONE\n");
             break;
             case '2':
                printf("Two\n");
             break;
             case '0':
                exit(0);
             break;
         }
     }
}
