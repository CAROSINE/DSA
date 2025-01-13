#include<stdio.h>
#include<time.h>

void main()
{
 int i,n,Data[10000];
 srand(time(NULL));
 printf("Enter the amount of numbers: ");
 scanf("%d",&n);
 for(i=0;i<n;i++)
 {
 Data[i] = (rand() %1000);
 }
 printf("\nThe %d Numbers are as follows:\n",n);
 for(i=0;i<n;i++)
 {
 printf("%5d",Data[i]);
 }
}
