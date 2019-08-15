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

#define MAX 101
int r, c, k;
int R, C;
int MAP[MAX][MAX];
void init() {
	int i, j;
	for (i = 1; i <= R; i++)
		for (j = 1; j <= C; j++)
			MAP[i][j] = 0;
}
void print()
{
	int i, j;
	for (i = 1; i <= R; i++) {
		for (j = 1; j <= C; j++)
			printf("%d ", MAP[i][j]);
		printf("\n");
	}
	printf("------------------------------\n");
}

int main()
{
	int i, j;
	scanf("%d %d %d", &r, &c, &k);

	for (i = 1; i <= 3; i++)
		for (j = 1; j <= 3; j++)
			scanf("%d", &MAP[i][j]);

	R = C = 3;
	int time = 0;
	while (MAP[r][c] != k) {
		time++;
		//print();
		if (time > 100) {
			time = -1;
			break;
		}

		vector <pair <int, int> > vec[MAX];
		if (R >= C) {

			for (i = 1; i <= R; i++) {
				int cnt[MAX] = { 0, };
				for (j = 1; j <= C; j++) {
					cnt[MAP[i][j]]++;
				}
				for (j = 1; j < MAX; j++)
					if (cnt[j])
						vec[i].push_back({ cnt[j], j });
			}
			init();
			for (i = 1; i <= R; i++)
				sort(vec[i].begin(), vec[i].end());
			for (i = 1; i <= R; i++) {
				int idx = 0;
				for (j = 0; j < vec[i].size(); j++) {
					MAP[i][idx + 1] = vec[i][j].second;
					MAP[i][idx + 2] = vec[i][j].first;
					idx = idx + 2;
					if (idx > 100)
						break;
				}
				C = max(C, idx);
			}
		}
		else {

			for (i = 1; i <= C; i++) {
				int cnt[MAX] = { 0, };
				for (j = 1; j <= R; j++) {
					cnt[MAP[j][i]]++;
				}
				for (j = 1; j < MAX; j++)
					if (cnt[j])
						vec[i].push_back({ cnt[j], j });
			}
			init();
			for (i = 1; i <= C; i++)
				sort(vec[i].begin(), vec[i].end());
			for (i = 1; i <= C; i++) {
				int idx = 0;
				for (j = 0; j < vec[i].size(); j++) {
					MAP[idx + 1][i] = vec[i][j].second;
					MAP[idx + 2][i] = vec[i][j].first;
					idx = idx + 2;
					if (idx > 100)
						break;
				}
				R = max(R, idx);
			}
		}
	}
	printf("%d\n", time);
}