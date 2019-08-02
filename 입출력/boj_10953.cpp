#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int main()
{	
	int N, i;
	int A, B;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
	{
		scanf("%d,%d", &A, &B);
		printf("%d\n", A + B);
	}

	return 0;
}