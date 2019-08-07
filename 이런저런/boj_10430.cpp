#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int main()
{
	int A, B, C;
	scanf("%d %d %d", &A, &B, &C);

	printf("%d\n", (A + B) % C);
	printf("%d\n", (A%C + B % C) % C);
	printf("%d\n", (A*B) % C);
	printf("%d\n", (A%C * B%C) % C);

	return 0;
}