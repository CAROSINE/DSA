#include<stdio.h>
#include<time.h>
void main()
{
 int i,n,Data[10000];
 srand(time(NULL));
 printf("Enter the amount of numbers: ");
 scanf("%d",&n);
 clock_t begin = clock();
 for(i=0;i<n;i++)
 {
 Data[i] = (rand() %100);
 }
 printf("\nThe %d Numbers are as follows:\n",n);
 for(i=0;i<n;i++)
 {
 printf("%5d",Data[i]);
 }
 clock_t end = clock();
 double time_spent = (double)(end - begin) / CLOCKS_PER_SEC;
 printf("\nTotal time spend : %f Seconds",time_spent);
}
