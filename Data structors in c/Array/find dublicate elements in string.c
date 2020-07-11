#include<stdio.h>
// super optimized Hashtable alternative
int duplicate(char *arr)
{
    int Hash,val,count,i;
    Hash = val = count = 0;
    for(i=0;arr[i]!=NULL;i++)
    {
        val = 1<<(arr[i]-97);
        if((val&Hash)>0)
            count++;
        else
            Hash = (Hash|val);
    }
    return count;
}
int main()
{
    char name[]="finding";
    fprintf(stdout,"%s has total of %d duplicates\n",name,duplicate(name));
    return 0;
}