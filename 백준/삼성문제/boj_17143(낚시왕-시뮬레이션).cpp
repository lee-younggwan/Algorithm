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

int dr[] = { 0, -1, 1, 0, 0 }; // 0 위 아래 오른쪽 왼쪾
int dc[] = { 0, 0, 0, 1, -1 };

vector <pair <pair <int, int>, int > > graph[101][101];
int R, C, M;
int main()
{
	ios_base::sync_with_stdio(0);
	int i, j, k, t;
	int r, c, s, d, z;
	int now_row, now_col, now_speed, now_dir, now_size, next_row, next_col;
	cin.tie(0);
	cin >> R >> C >> M;
	for (i = 0; i < M; i++) {
		cin >> r >> c >> s >> d >> z;
		graph[r][c].push_back(make_pair(make_pair(s, d), z)); // 속도 방향 크기를 넣는다
	}

	//낚시왕이 열을 이동한다
	int ans = 0;
	for (i = 1; i <= C; i++) {
		//print();
		//현재 낚시왕이 있는 열의 가장 위에 있는 상어를 잡는다
		for (j = 1; j <= R; j++) {
			if (graph[j][i].size()) {
				ans = ans + graph[j][i].front().second;
				graph[j][i].clear();
				break;
			}
		}

		//상어들을 que에 넣는다
		queue <pair <pair <pair <pair <int, int>, int>, int>, int > >  que; //row, col, speed, dir, size
		for (j = 1; j <= R; j++)
			for (k = 1; k <= C; k++)
				if (graph[j][k].size()) {
					que.push({ { { { j, k }, graph[j][k].front().first.first }, graph[j][k].front().first.second }, graph[j][k].front().second });
					graph[j][k].clear();

				}

		//상어들을 이동시킨다
		while (!que.empty()) {
			now_row = que.front().first.first.first.first;
			now_col = que.front().first.first.first.second;
			now_speed = que.front().first.first.second;
			now_dir = que.front().first.second;
			now_size = que.front().second;
			que.pop();

			switch (now_dir) {
			case 1: //위 아래인 경우
			case 2:
				now_speed = now_speed % (2 * (R - 1));
				break;
			case 3:
			case 4:
				now_speed = now_speed % (2 * (C - 1));
				break;
			}
			for (t = 0; t < now_speed; t++) {
				next_row = now_row + dr[now_dir];
				next_col = now_col + dc[now_dir];

				if (next_row >= 1 && next_row <= R && next_col >= 1 && next_col <= C) { //격자판의 안쪽인 경우
					now_row = next_row;
					now_col = next_col;
				}
				else { //격자판의 경계인 경우
					if (now_dir == 1)
						now_dir = 2;
					else if (now_dir == 2)
						now_dir = 1;
					else if (now_dir == 3)
						now_dir = 4;
					else if (now_dir == 4)
						now_dir = 3;
					now_row = now_row + dr[now_dir];
					now_col = now_col + dc[now_dir];
				}
			}
			if (!graph[now_row][now_col].size()) {
				graph[now_row][now_col].push_back({ { now_speed, now_dir }, now_size });
			}
			else {
				if (now_size > graph[now_row][now_col].front().second) { // 기존에 있던 상어보다 큰 경우
					graph[now_row][now_col].clear();
					graph[now_row][now_col].push_back({ {now_speed, now_dir}, now_size });
				}
			}
		}
	}
	cout << ans << "\n";
}