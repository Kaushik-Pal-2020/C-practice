#include <stdio.h>
int main()
{
    char p[10], cd;
    printf("enter file name with extension\n");
    // scanf("%s", p);
    FILE *fp = fopen("test01.txt", "w");
    if (!fp)
        printf("File can not be created\n");
    else
    {
        printf("File exist\n");
        while ((cd = getchar()) != EOF)
            putc(cd, fp);
    }
    fclose(fp);
    FILE *fp2 = fopen("test01.txt", "r");
    while ((cd = getc(fp2)) != EOF)
        putchar(cd);
    fclose(fp2);
    return 0;
}
