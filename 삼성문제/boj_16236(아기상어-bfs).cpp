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

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

queue <pair <pair <int, int>, int> > que;

int MAP[21][21];
int visit[21][21];
int N;
int shark = 2;

bool comp(const  pair <pair < int, int >, int >  &a, const  pair <pair < int, int >, int >  &b)
{
	if (a.second == b.second) {
		if (a.first.first == b.first.first)
			return a.first.second < b.first.second;
		return a.first < b.first;
	}
	return a.second < b.second;
}
void init()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			visit[i][j] = 0;
}
void print()
{
	int i, j;
	printf("상어위치 < %d %d > %d\n", que.front().first.first, que.front().first.second, que.front().second);
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", MAP[i][j]);
		printf("\n");
	}
}
int main()
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 9) { // 상어 위치 저장
				que.push(make_pair(make_pair(i, j), 0));
				MAP[i][j] = 0;
				visit[i][j] = 1;
			}
		}

	int cnt = 0;
	int flag = 1;
	int ans = 0;
	int sum = 0;
	while (1) {
		vector <pair <pair <int, int>, int> > vec;
		cnt = 0;
		//print();
		while (!que.empty()) {
			int now_row = que.front().first.first;
			int now_col = que.front().first.second;
			int now_time = que.front().second;
			que.pop();

			for (i = 0; i < 4; i++) {
				int next_row = now_row + dr[i];
				int next_col = now_col + dc[i];
				int next_time = now_time + 1;

				if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
					if (!visit[next_row][next_col] && MAP[next_row][next_col] <= shark) {
						// 빈칸혹은 상어와 크기가 같다면 que에 집어 넣는다
						if (MAP[next_row][next_col] == 0 || MAP[next_row][next_col] == shark) {
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
						}
						else { // 현재 아기상어의 크기보다 작은 물고기라면
							que.push(make_pair(make_pair(next_row, next_col), next_time));
							vec.push_back(make_pair(make_pair(next_row, next_col), next_time));
							visit[next_row][next_col] = 1;
							cnt++;
						}
					}
				}
			}
		}
		if (cnt != 0) { //먹을 수 있는 물고기가 있다면
			if (cnt == 1) { // 1마리만 먹어서 아기 상어의 크기가 커지는 경우가 없음
				ans = vec.front().second;
				que.push(make_pair(make_pair(vec.front().first.first, vec.front().first.second), vec.front().second));
				init();
				visit[vec.front().first.first][vec.front().first.second] = 1;
				MAP[vec.front().first.first][vec.front().first.second] = 0;
				ans = vec.front().second;
				sum++;
				if (sum == shark) {
					shark++;
					sum = 0;
				}
				else
					break;
			}
			else { // 여러 마리라면 거리가 가장 가까운 물고기를 먹으러 간다.
				stable_sort(vec.begin(), vec.end(), comp);
				que.push(make_pair(make_pair(vec.front().first.first, vec.front().first.second), vec.front().second));
				init();
				visit[vec.front().first.first][vec.front().first.second] = 1;
				MAP[vec.front().first.first][vec.front().first.second] = 0;
				ans = vec.front().second;
				sum++;
				if (sum == shark) {
					shark++;
					sum = 0;
				}
			}
		}
		else
			break;
	}
	printf("%d\n", ans);
}