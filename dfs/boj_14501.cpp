#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N;
int time[16];
int point[16];
int ans = 0;
void dfs(int idx, int cost)
{
	for (int i = idx + 1; i <= N+1; i++) {
		if (i >= idx + time[idx] && idx + time[idx] <= N + 1) {
			ans = max(ans, cost);
			dfs(i, cost + point[i]);
		}
	}
}
int main()
{
	int i;
	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		scanf("%d %d", &time[i], &point[i]);

	for (i = 1; i <= N; i++)
		dfs(i, point[i]);
	
	printf("%d\n", ans);
}