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

queue <pair<int, int>> que;
int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };
int MAP[51][51];
int visit[51][51];
int N, L, R;
int flag;
void bfs()
{
	vector <pair <int, int> > vec;
	vec.push_back(make_pair(que.front().first, que.front().second));
	int sum = MAP[que.front().first][que.front().second];

	while (!que.empty()) {
		int now_row = que.front().first;
		int now_col = que.front().second;
		que.pop();

		for (int i = 0; i < 4; i++) {
			int next_row = now_row + dr[i];
			int next_col = now_col + dc[i];

			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
				if (!visit[next_row][next_col] && abs(MAP[now_row][now_col] - MAP[next_row][next_col]) >= L &&
					abs(MAP[now_row][now_col] - MAP[next_row][next_col]) <= R) {
					que.push(make_pair(next_row, next_col));
					vec.push_back(make_pair(next_row, next_col));
					sum = sum + MAP[next_row][next_col];
					visit[next_row][next_col] = 1;
					flag = 1;
				}
			}
		}
	}
	for (int i = 0; i < vec.size(); i++)
		MAP[vec[i].first][vec[i].second] = sum / vec.size();
}
int main()
{
	int i, j;
	int ans = 0;
	scanf("%d %d %d", &N, &L, &R);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &MAP[i][j]);

	flag = 1;
	while (flag) {
		flag = 0;
		memset(visit, 0, sizeof(visit));
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (visit[i][j] == 0) {
					que.push(make_pair(i, j));
					visit[i][j] = 1;
					bfs();
				}
		if (flag)
			ans++;
	}
	printf("%d\n", ans);
}