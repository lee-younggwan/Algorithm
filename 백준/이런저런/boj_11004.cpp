#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int N, K;
long long arr[5000001];
int main()
{
	int i;
	scanf("%d %d", &N, &K);
	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	printf("%ll\n", arr[K - 1]);
	return 0;
}