#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

#define MAX 1000001

int exam[MAX];
int N, A, B, C;
int main()
{
	int i;
	scanf("%d", &N);
	
	for(i=1;i<=N;i++)
		scanf("%d", &exam[i]);
	scanf("%d %d", &B, &C);

	long long int ans = 0;
	for (i = 1; i <= N; i++) {
		exam[i] = exam[i] - B;

		if (exam[i] > 0) {
			if (exam[i] % C != 0)
				ans = ans + exam[i] / C + 1;
			else
				ans = ans + exam[i] / C;
		}
	}
	printf("%lld\n", ans + N);
}