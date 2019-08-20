#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

long long int lan[1000001];
int main(void)
{
	int i;
	long long int N, M;
	long long int result;
	long long int left = 0;
	long long int right = -1;
	long long int mid = 0;
	long long int maxx = -1;
	scanf("%lld %lld", &N, &M);

	for (i = 0; i < N; i++) {
		scanf("%lld", &lan[i]);
		right = max(right, lan[i]);
	}

	while (left <= right) {
		mid = (left + right) / 2;
		result = 0;
		for (i = 0; i < N; i++) {
			if(lan[i]>mid)
				result = result + lan[i] - mid;
		}
		if (result >= M)
		{
			left = mid + 1;
			if (mid > maxx)
				maxx = mid;
		}
		else
			right = mid - 1;
	}
	printf("%lld\n", maxx);
	return 0;
}
