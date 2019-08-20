#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

queue <pair <pair<int, int>, int>> que;
int MAP[101][101];
int N, M;
int main()
{
	int i, j;

	scanf("%d %d", &N, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%1d", &MAP[i][j]);

	que.push(make_pair(make_pair(0, 0), 1));

	while (!que.empty()) {
		int now_row = que.front().first.first;
		int now_col = que.front().first.second;
		int now_cnt = que.front().second;
		que.pop();

		for (i = 0; i < 4; i++) {
			int next_row = now_row + dr[i];
			int next_col = now_col + dc[i];
			int next_cnt = now_cnt + 1;

			if (next_row == N - 1 && next_col == M - 1) {
				printf("%d\n", next_cnt);
				return 0;
			}

			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
				if (MAP[next_row][next_col] == 1){
					MAP[next_row][next_col] = next_cnt;
					que.push(make_pair(make_pair(next_row, next_col), next_cnt));
				}
			}
		}
	}

	return 0;
}