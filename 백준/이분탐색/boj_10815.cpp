#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

vector <int> vec;
int arr[500001];
int N, M;
int main(void)
{
	int i;
	int left, right, mid;
	int find;
	int flag = 0;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		scanf("%d", &arr[i]);
	sort(arr, arr + N);
	left = 0;
	right = N - 1;

	scanf("%d", &M);
	for (i = 0; i < M; i++) {
		flag = 0;
		left = 0;
		right = N - 1;
		scanf("%d", &find);
		while (left <= right) {
			mid = (left + right) / 2;

			if (find > arr[mid])
				left = mid + 1;
			else if (find < arr[mid])
				right = mid - 1;
			else if (find == arr[mid]) {
				flag = 1;
				break;
			}
		}
		if (flag)
			printf("1 ");
		else
			printf("0 ");
	}

	return 0;
}
