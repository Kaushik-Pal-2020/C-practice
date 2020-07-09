#include <stdio.h>
#include <stdlib.h>
#include <math.h>
long long int fib_series(long long int n)
{
	static long long int t0 = 0, t1 = 1;
	if (n > 1)
	{
		long long int s = fib_series(n - 1);
		printf("%lld ", s);
		t0 = t1;
		t1 = s;
		return t0 + t1;
	}
	else
	{
		printf("%lld %lld ", t0, t1);
		return 1;
	}
}

int fib(int n)
{
	if (n <= 1)
		return n;
	return fib(n - 1) + fib(n - 2);
}

int fib_iterative(int n)
{
	int a = 0, b = 1, c, i;
	if (n == 0)
		return a;
	for (i = 2; i <= n; i++)
	{
		c = a + b;
		a = b;
		b = c;
	}
	return b;
}
void power(int F[2][2], int n)
{
	int i;
	int M[2][2] = {{1, 1}, {1, 0}};

	// n - 1 times multiply the matrix to {{1,0},{0,1}}
	for (i = 2; i <= n; i++)
		multiply(F, M);
}
int fib_formula(int n)
{
	double phi = (1 + sqrt(5)) / 2;
	return round(pow(phi, n) / sqrt(5));
}
int fib_matrix(int n)
{
	int F[2][2] = {{1, 1}, {1, 0}};
	if (n == 0)
		return 0;
	power(F, n - 1);

	return F[0][0];
}

void multiply(int F[2][2], int M[2][2])
{
	int x = F[0][0] * M[0][0] + F[0][1] * M[1][0];
	int y = F[0][0] * M[0][1] + F[0][1] * M[1][1];
	int z = F[1][0] * M[0][0] + F[1][1] * M[1][0];
	int w = F[1][0] * M[0][1] + F[1][1] * M[1][1];

	F[0][0] = x;
	F[0][1] = y;
	F[1][0] = z;
	F[1][1] = w;
}

int main()
{
	printf("%d", fib(5));
	system("pause");
	return 0;
}
