#include <stdio.h>
#include <complex.h>
#include <math.h>

int main()
{
    float complex cx = 1.0 + 3.0 * I;
    float complex cy = 1.0 - 4.0 * I;

    printf("Starting values : cx = %.2f %+ .2fi  cy = %.2f %+ .2fi\n", creal(cx), cimag(cx), creal(cy), cimag(cy));

    float complex sum = cx + cy;
    printf("\nsum cx + cy =  %.2f %+ .2fi\n", creal(sum), cimag(sum));

    float complex diff = cx - cy;
    printf("\ndifference cx - cy =  %.2f %+ .2fi\n", creal(diff), cimag(diff));

    float complex product = cx * cy;
    printf("\nProduct cx * cy =  %.2f %+ .2fi\n", creal(product), cimag(product));

    float complex divide = cx - cy;
    printf("\nquotient cx / cy =  %.2f %+ .2fi\n", creal(divide), cimag(divide));

    float complex conjugate = conj(cx);
    printf("\nconjugate of cx =  %.2f %+ .2fi\n", creal(conjugate), cimag(conjugate));

    float complex power = cpow(cx, cy);
    printf("\npower cx ^ cy =  %.2f %+ .2fi\n", creal(power), cimag(power));

    float complex v = 3.141592653589793238 * I;
    printf("\n e^(pi*I) = %.2f %+ .2f \n", creal(exp(v)), cimag(exp(v)));
    return 0;
}
