#include<stdio.h>
#include<time.h>
FILE *file_write=NULL;

void towerOfHanoi(int n,char source, char destination , char helper)
{
    static unsigned long long int count_steps = 1;
    if(n==1)
    {
    	fprintf(file_write,"%lld . Moving %d plate from %c pole to %c pole\n",
		count_steps, n, source, destination);
        count_steps++;
        return;
    }
    
    towerOfHanoi(n-1,source,helper,destination);
    fprintf(file_write,"%lld . Moving %d plate from %c pole to %c pole\n",
	count_steps, n, source, destination);
    count_steps++;
    towerOfHanoi(n-1,helper, destination, source);
    return;
}


int main()
{
	file_write = fopen("tower of hanoi result.txt","w");
	if(!fwrite)
	{
		printf("File Error\n");
		return -1;
	}
	char deco[] = "--------------------------------------------------\n";
    clock_t t1, t2;
    int n = 22;
    long long int count = 1;
    fprintf(file_write,"Working for %d no of poles\n",n);
    fputs(deco,file_write);
    t1 = clock();
    towerOfHanoi(n,'A','C','B');
    t2 = clock();
    fputs(deco,file_write);
    printf("------------------------------------\n");
    double total_execution = ((double)t2-t1)/1000;
    printf("total process time : %.4lf sec\n",total_execution);
    fputs("\n",file_write);
    fprintf(file_write,"Total process time : %.4lf sec\n",total_execution);
    fclose(file_write);
    return 0;
}
