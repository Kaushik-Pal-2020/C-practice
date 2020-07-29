#include<stdio.h>
#include<string.h>

void powersetSubString(char *input,char *output,int i)
{
    if(input[i] == NULL)
    {
        printf("%c\n",*output);
        return;
    }
    char output1[10] = output;
    char output2[10] = output;
    strcat(output2, &input[i]);
    i++;
    powersetSubString(input,output1,i);
    powersetSubString(input, output2,i);
    return;
}

int main()
{
    char name[] = "abc";
    char output = ' ';
    powersetSubString("abc"," ",0);
    return 0;

}