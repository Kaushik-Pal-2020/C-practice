#include <stdio.h>
#include <stdlib.h>
#define PI 3.14159265
#include <math.h>

int main()
{
    double x, ret, val;
    x = 60.0;
    ret = cos(x * PI / 180.0);
    printf("cosine = %lf\n", (ret));
    system("pause");
    return 0;
}