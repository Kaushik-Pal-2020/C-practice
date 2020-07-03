#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
    char name[3][50];
    char ch,junk;
    int no[3];
    int i,j;
    i=j=0;
    int valve=1;
    printf("enter your name and roll number along with it\n");
    while( (ch = getchar()) != '\n' && i<3 )
    {
        if(ch!=',')
    {
        name[i][j]= ch;
        ++j; 
        
    }
       else if(ch==',' && valve!=0)
       {
           name[i][j]='\0';
           j=0;
           junk=ch;
           valve=0;
       }
       else if(valve==0)
       {
           no[j++]=ch;
       }
       i++;
       fflush(stdin); 
    } printf("displaing\n");
    for(int i=0;i<3;i++)
    {
       printf("  %-30s %d\n",name[i],no[i]);
    }
    system("pause");
    return 0;
}