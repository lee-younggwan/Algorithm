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

int T, N, K;
int MAP[9][9];
int COPY[9][9];
int visit[9][9];
int ans = 0;
void dfs(int now_row, int now_col, int dist, int flag)
{
	visit[now_row][now_col] = 1;
	ans = max(ans, dist);


	for (int i = 0; i < 4; i++) {
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];

		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
			if (!visit[next_row][next_col]) {
				if (COPY[next_row][next_col] < COPY[now_row][now_col]) {
					dfs(next_row, next_col, dist + 1, flag);
					visit[next_row][next_col] = 0;
				}
				else {
					if (flag) { //���� �ѹ��� ������ ���� ���� ���� ���
						//������ ������ġ���� -1�� �����̴�
						if (COPY[next_row][next_col] - K < COPY[now_row][now_col]) { //������ ����� ���, ���纸�� ���������� ��´�
							while (COPY[next_row][next_col] >= COPY[now_row][now_col])
								COPY[next_row][next_col]--;
							dfs(next_row, next_col, dist + 1, 0);
							visit[next_row][next_col] = 0;
							COPY[next_row][next_col] = MAP[next_row][next_col];
						}
						else //��Ƶ� ���̾��� ���
							continue;
					}
					else
						continue;
				}
			}
		}
	}
	visit[now_row][now_col] = 0;
}
void copy_map()
{
	for (int i = 0; i < N; i++)
		for (int j = 0; j < N; j++) {
			COPY[i][j] = MAP[i][j];
			visit[i][j] = 0;
		}
}
int main()
{
	int i, j;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &K);
		ans = 0;
		vector <pair <int, int> > vec;
		int high = 0;
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				scanf("%d", &MAP[i][j]);
				high = max(high, MAP[i][j]); // ���� ���� ���츮�� ���̸� ã�´�
			}
		}
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++) {
				if (MAP[i][j] == high)  //���� ���� ���츮�� vector�� �ִ´�
					vec.push_back(make_pair(i, j));
			}
		}

		for (i = 0; i < vec.size(); i++) { //���� ���� ��� ���츮���� �����ϴ� ��� ��츦 ã�ƾ��Ѵ�
			copy_map();
			dfs(vec[i].first, vec[i].second, 1, 1);
		}
		printf("#%d %d\n", test_case, ans);
	}
}