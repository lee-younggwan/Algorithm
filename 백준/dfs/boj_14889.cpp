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
int MAP[21][21];
int start[21];
int ans = 40001;
void dfs(int idx, int cnt)
{
	// idx∏¶ start∆¿ø° ≥÷¿∫ dfs
	int i, j, start_score = 0, link_score = 0;

	if (cnt == N / 2) {
		for (i = 0; i < N; i++) {
			if (start[i]) { //start∆¿¿Ã∏È
				for (j = 0; j < N; j++) {
					if (i == j)
						continue;
					if (start[j])
						start_score = start_score + MAP[i][j];
				}
			}
			else { //link ∆¿¿Œ∞ÊøÏ
				for (j = 0; j < N; j++) {
					if (i == j)
						continue;
					if (start[j] == 0)
						link_score = link_score + MAP[i][j];
				}
			}
		}
		ans = min(ans, abs(start_score - link_score));
		return;
	}
	for (i = idx; i < N; i++) {
		if (start[i] == 0) {
			start[i] = 1;
			dfs(i, cnt + 1);
			start[i] = 0;
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &MAP[i][j]);

	dfs(0, 0);
	printf("%d\n", ans);
}