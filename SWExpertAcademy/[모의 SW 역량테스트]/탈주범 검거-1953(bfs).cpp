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

int dr[] = { -1,0,1,0 };
int dc[] = { 0, 1, 0, -1 };

int MAP[51][51];
int visit[51][51];
int T, N, M, R, C, L;

bool check(int type, int dir, int next_row, int next_col)
{
	if (MAP[next_row][next_col] == 0)
		return false;
	else {
		switch (type) {
		case 1:
			if (dir == 0) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 5 || MAP[next_row][next_col] == 6)
					return true;
				else
					return false;
			}
			else if (dir == 1) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 6 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			else if (dir == 2) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			else if (dir == 3) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 5)
					return true;
				else
					return false;
			}
			break;
		case 2:
			if (dir == 0) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 5 || MAP[next_row][next_col] == 6)
					return true;
				else
					return false;
			}
			else if (dir == 2) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			break;
		case 3:
			if (dir == 1) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 6 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			else if (dir == 3) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 5)
					return true;
				else
					return false;
			}
			break;
		case 4:
			if (dir == 0) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 5 || MAP[next_row][next_col] == 6)
					return true;
				else
					return false;
			}
			else if (dir == 1) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 6 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			break;
		case 5:
			if (dir == 1) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 6 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			else if (dir == 2) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			break;
		case 6:
			if (dir == 2) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 7)
					return true;
				else
					return false;
			}
			else if (dir == 3) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 5)
					return true;
				else
					return false;
			}
			break;
		case 7:
			if (dir == 0) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 2 || MAP[next_row][next_col] == 5 || MAP[next_row][next_col] == 6)
					return true;
				else
					return false;
			}
			else if (dir == 3) {
				if (MAP[next_row][next_col] == 1 || MAP[next_row][next_col] == 3 || MAP[next_row][next_col] == 4 || MAP[next_row][next_col] == 5)
					return true;
				else
					return false;
			}
			break;
		}
	}
}
int main()
{
	int i, j;
	int now_row, now_col, next_row, next_col, now_time, next_time;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d %d %d", &N, &M, &R, &C, &L);

		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				scanf("%d", &MAP[i][j]);
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				visit[i][j] = 0;

		queue <pair <pair <int, int >, int > > que;
		que.push(make_pair(make_pair(R, C), 1));
		visit[R][C] = 1;

		while (!que.empty()) {
			now_row = que.front().first.first;
			now_col = que.front().first.second;
			now_time = que.front().second;
			que.pop();
			if (now_time == L)
				continue;

			switch (MAP[now_row][now_col]) {
			case 1: // 상,하,좌,우
				for (i = 0; i < 4; i++) {
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;

					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 2: // 상, 하
				for (i = 0; i < 4; i = i + 2) { //0과 2만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 3: // 좌, 우
				for (i = 1; i < 4; i = i + 2) { //1과 3만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 4: // 상, 우
				for (i = 0; i < 2; i++) { //0과 1만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 5: // 하, 우
				for (i = 1; i < 3; i++) { //1과 2만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 6: // 하, 좌
				for (i = 2; i < 4; i++) { //2와 3만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			case 7: // 상, 좌
				for (i = 0; i < 4; i = i + 3) { //0과 3만
					next_row = now_row + dr[i];
					next_col = now_col + dc[i];
					next_time = now_time + 1;
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (!visit[next_row][next_col] && check(MAP[now_row][now_col], i, next_row, next_col)) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
					}
				}
				break;
			}

		}
		int ans = 0;
		for (i = 0; i < N; i++)
			for (j = 0; j < M; j++)
				if (visit[i][j])
					ans++;
		printf("#%d %d\n", test_case, ans);

	}
}