#include<stdio.h>
int main()
{
	FILE *fwrite=NULL,*fread=NULL;
	int age;
	char name[8];
	fwrite = fopen("test.txt","w");
	fputs("Name Kaushik age 18",fwrite);
	fputs("Successful\n",stdout);
	fclose(fwrite);
	
	fread = fopen("test.txt","r");
	fscanf(fread,"%*s %s %*s %d",name,&age);
	fclose(fread);
	fprintf(stdout,"Name : %s\nAge : %d\n",name,age);
	
	return 0;
}
