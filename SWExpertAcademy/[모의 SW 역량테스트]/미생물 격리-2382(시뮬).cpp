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

int dr[] = { 0, -1, 1, 0, 0 }; // 상 하 좌 우
int dc[] = { 0, 0, 0, -1, 1 };

vector <pair <int, int> > vec[101][101];
int T, N, M, K;

void simul()
{
	int time, i, j;
	for (time = 0; time < M; time++) {

		queue <pair <pair <pair <int, int>, int>, int> > que;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (vec[i][j].size()) { // 미생물이 있으면 que에 넣는다
					que.push(make_pair(make_pair(make_pair(i, j), vec[i][j].front().first), vec[i][j].front().second));
					vec[i][j].clear();
				}
			}
		}

		while (!que.empty()) {
			int now_row = que.front().first.first.first;
			int now_col = que.front().first.first.second;
			int now_bug = que.front().first.second;
			int now_dir = que.front().second;
			que.pop();

			int next_row = now_row + dr[now_dir];
			int next_col = now_col + dc[now_dir];

			//약품이 칠해지지 않은 부분인 경우
			if (next_row >= 1 && next_row < N - 1 && next_col >= 1 && next_col < N - 1)
				vec[next_row][next_col].push_back(make_pair(now_bug, now_dir));
			else if (next_row == 0 || next_row == N - 1 || next_col == 0 || next_col == N - 1) {//약품이 칠해진 부분인 경우
				now_bug = now_bug / 2; //미생물 수를 2로 나누고 방향을 바꾼다
				switch (now_dir) {
				case 1:
					now_dir = 2;
					break;
				case 2:
					now_dir = 1;
					break;
				case 3:
					now_dir = 4;
					break;
				case 4:
					now_dir = 3;
					break;
				}
				if (now_bug != 0)
					vec[next_row][next_col].push_back(make_pair(now_bug, now_dir));
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (vec[i][j].size() > 1) {
					int sum = 0;
					int idx = 0;
					int maxx = 0;
					for (int k = 0; k < vec[i][j].size(); k++) {
						sum = sum + vec[i][j][k].first;
						if (vec[i][j][k].first > maxx) {
							maxx = vec[i][j][k].first;
							idx = k;
						}
					}
					int dir = vec[i][j][idx].second;
					vec[i][j].clear();
					vec[i][j].push_back(make_pair(sum, dir));
				}
			}
		}
	}
}
int main()
{
	int i, j;
	int row, col, bug, dir;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				if (vec[i][j].size())
					vec[i][j].clear();

		scanf("%d %d %d", &N, &M, &K);

		for (i = 0; i < K; i++) {
			scanf("%d %d %d %d", &row, &col, &bug, &dir);
			vec[row][col].push_back(make_pair(bug, dir));
		}

		simul();
		int ans = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (vec[i][j].size()) {
					ans += vec[i][j].front().first;
				}
			}
		}
		printf("#%d %d\n", test_case, ans);
	}
}