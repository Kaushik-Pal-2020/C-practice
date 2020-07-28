#include<stdio.h>
#include<time.h>


void towerOfHanoi(int n,char source, char destination , char helper)
{
    static unsigned long long int count_steps = 1;
    if(n==1)
    {
        printf("%lld . Moving %d plate from %c pole to %c pole\n",
        count_steps, n, source, destination);
        count_steps++;
        return;
    }
    
    towerOfHanoi(n-1,source,helper,destination);
    printf("%lld . Moving %d plate from %c pole to %c pole\n",
        count_steps, n, source, destination);
    count_steps++;
    towerOfHanoi(n-1,helper, destination, source);
    return;
}


int main()
{
    clock_t t1, t2;
    int n = 3;
    long long int count = 1;
    t1 = clock();
    towerOfHanoi(20,'A','C','B');
    t2 = clock();
    printf("------------------------------------\n");
    double total_execution = ((double)t2-t1)/1000;
    printf("total process time : %.4lf sec\n",total_execution);
    return 0;
}