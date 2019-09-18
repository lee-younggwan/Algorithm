#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
int T, N;
int location[10];
int mass[10];
int main() {
	int i, j;
	double ans = 0;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		for(i=0;i<N;i++)
			scanf("%d", &location[i]);
		for (i = 0; i < N; i++)
			scanf("%d", &mass[i]);

		for (i = 0; i < N - 1; i++) {
			double left = location[i];
			double right = location[i + 1];

			int cnt = 0;
			ans = 0;
			while (cnt != 50) {
				double mid = (left + right) / 2;
				double sum = 0;
				for (j = 0; j <= i; j++) {
					sum = sum + mass[j] / ((mid - location[j])*(mid - location[j]));
				}
				for (j = i + 1; j < N; j++) {
					sum = sum - mass[j] / ((mid - location[j])*(mid - location[j]));
				}
				
				//왼쪽이 더 크다
				if (sum > 0) {
					left = mid;
				}
				else {
					ans = mid;
					right = mid;
				}
				cnt++;
			}
			printf("#%d %.10lf\n", test_case, ans);
		}
	}
	return 0;
}