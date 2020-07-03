//Write a program to initialize members of a structure using pointer to a structure. Structure members are roll number, name, date of birth.
#include<stdio.h>
#include<stdlib.h>
#include <string.h>
struct student
{
    char name[50];
    int dob;
    unsigned long long roll;
};

int main()
{
    struct student s;
    struct student* s_ptr=&s;
    strcpy(s_ptr->name,"Kaushik Pal");
    s_ptr->dob = 10092001;
    s_ptr->roll = 12000119098;
    system("pause");
    return 0;
}