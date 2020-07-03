#include<stdio.h>
#include<conio.h>
main()
{
    int i,j,k,l;
    int  N=171;
    if (N%2==0)
    N=N+1;
  
    /*
    for printing 
           *
          ***
         *****
        *******
    */
    for(i=0,l=1;l<=N;i++,l+=2)
    {
        for(j=(N/2)-i;j>=1;j--)
        printf(" ");
        for(k=1;k<=l;k++)
        printf("*");
        printf("\n");
        
    }
    printf("\n\n");
    getch();
}