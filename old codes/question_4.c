#include<stdio.h>
#include<stdlib.h>
#define MAX 10

struct student{
    //roll no., name, semester
    int semester;
    char name[50];
    unsigned long long roll_no;
};

int main()
{
    int i;
    struct  student record[MAX];
    printf("TAKING INPUTS FROM USER\n");
    for(i=0;i<MAX;i++)
    {
        printf("Taking input for : %d student\n",i+1);
        printf("Name of the student :\t");
        fgets(record[i].name, sizeof(record[i].name), stdin);
        printf("Roll no :\t");
        scanf("%llu",&record[i].roll_no);
        printf("Semester NO :\t");
        scanf("%d",&record[i].semester);
        printf("\n");
    }
    printf("\n\n");
    for(i=0; i<MAX; i++)
     {
         printf("     Records of STUDENT : %d \n", i+1);
         printf(" Name is: %s ", record[i].name);
         printf("Roll is: %llu \n", record[i].roll_no);
         printf(" Semester is: %d\n\n",record[i].semester);
     };
     system("pause");
    return 0;
}