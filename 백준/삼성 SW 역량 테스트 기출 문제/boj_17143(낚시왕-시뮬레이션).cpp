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

int dr[] = { 0, -1, 1, 0, 0 }; // 0 �� �Ʒ� ������ �ަU
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
		graph[r][c].push_back(make_pair(make_pair(s, d), z)); // �ӵ� ���� ũ�⸦ �ִ´�
	}

	//���ÿ��� ���� �̵��Ѵ�
	int ans = 0;
	for (i = 1; i <= C; i++) {
		//print();
		//���� ���ÿ��� �ִ� ���� ���� ���� �ִ� �� ��´�
		for (j = 1; j <= R; j++) {
			if (graph[j][i].size()) {
				ans = ans + graph[j][i].front().second;
				graph[j][i].clear();
				break;
			}
		}

		//������ que�� �ִ´�
		queue <pair <pair <pair <pair <int, int>, int>, int>, int > >  que; //row, col, speed, dir, size
		for (j = 1; j <= R; j++)
			for (k = 1; k <= C; k++)
				if (graph[j][k].size()) {
					que.push({ { { { j, k }, graph[j][k].front().first.first }, graph[j][k].front().first.second }, graph[j][k].front().second });
					graph[j][k].clear();

				}

		//������ �̵���Ų��
		while (!que.empty()) {
			now_row = que.front().first.first.first.first;
			now_col = que.front().first.first.first.second;
			now_speed = que.front().first.first.second;
			now_dir = que.front().first.second;
			now_size = que.front().second;
			que.pop();

			switch (now_dir) {
			case 1: //�� �Ʒ��� ���
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

				if (next_row >= 1 && next_row <= R && next_col >= 1 && next_col <= C) { //�������� ������ ���
					now_row = next_row;
					now_col = next_col;
				}
				else { //�������� ����� ���
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
				if (now_size > graph[now_row][now_col].front().second) { // ������ �ִ� ���� ū ���
					graph[now_row][now_col].clear();
					graph[now_row][now_col].push_back({ {now_speed, now_dir}, now_size });
				}
			}
		}
	}
	cout << ans << "\n";
}