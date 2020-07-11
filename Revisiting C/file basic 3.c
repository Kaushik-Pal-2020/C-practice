#include<stdio.h>
int main()
{
	FILE *fread = fopen("test.txt","r"),*fappend=NULL;
	char s[100];
	while(fgets(s,100,fread))
	{
		printf("%s",s);
	}
	fclose(fread);
	
	fappend = fopen("test.txt","a");
	putc('\n',fappend);
	fputs("hello all",fappend);
	fclose(fappend);
	return 0;
}
