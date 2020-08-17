// output for 5:
// 5 5 5 5 5 5 5 5 5
// 5 4 4 4 4 4 4 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 2 1 2 3 4 5
// 5 4 3 2 2 2 3 4 5
// 5 4 3 3 3 3 3 4 5
// 5 4 4 4 4 4 4 4 5
// 5 5 5 5 5 5 5 5 5
#include <stdio.h>
int main()
{
    int n = 3; // user input
    int i, j, k, l, m, o;
    for (i = 0; i < 2 * n - 1; i++)
    {
        // for upper or lower lines
        if (i == 0 || i == (2 * n) - 2)
            for (j = 0; j < 2 * n - 1; j++)
                printf("%d ", n);

        // for middle + upper middle part
        else if (i > 0 && i < n)
        {

            // for first numbers
            for (k = 0; k < i; k++)
                printf("%d ", n - k);

            // for middle numbers
            for (l = 0; l < 2 * (n - i) - 1; l++)
                printf("%d ", n - i);

            // last number
            for (m = i - 1; m >= 0; m--)
                printf("%d ", n - m);
        }
        else
        {
            o = (2 * n) - i - 2;

            for (k = 0; k < o; k++)
                printf("%d ", n - k);

            for (l = 0; l < 2 * (n - o) - 1; l++)
                printf("%d ", n - o);

            for (m = o - 1; m >= 0; m--)
                printf("%d ", n - m);
        }
        printf("\n");
    }
    return 0;
}