#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1,1,0,0 }; // 상하좌우
int dc[] = { 0,0,-1,1 };

vector <pair <int, int> > wormhole[5];
int T, N;
int start_row, start_col;
int MAP[101][101];
int ans = 0;
int changeDir(int dir, int type)
{
	if (type == 1) {
		if (dir == 0)
			return 1;
		if (dir == 1)
			return 3;
		if (dir == 2)
			return 0;
		if (dir == 3)
			return 2;
	}
	else if (type == 2) {
		if (dir == 0)
			return 3;
		if (dir == 1)
			return 0;
		if (dir == 2)
			return 1;
		if (dir == 3)
			return 2;
	}
	else if (type == 3) {
		if (dir == 0)
			return 2;
		if (dir == 1)
			return 0;
		if (dir == 2)
			return 3;
		if (dir == 3)
			return 1;
	}
	else if (type == 4) {
		if (dir == 0)
			return 1;
		if (dir == 1)
			return 2;
		if (dir == 2)
			return 3;
		if (dir == 3)
			return 0;
	}
	else if (type == 5) {
		if (dir == 0)
			return 1;
		if (dir == 1)
			return 0;
		if (dir == 2)
			return 3;
		if (dir == 3)
			return 2;
	}
}
void simul()
{
	int i, j;

	for (i = 0; i < 4; i++) {
		int now_row = start_row;
		int now_col = start_col;
		int now_dir = i;

		int score = 0;
		while (1) {
			int next_row = now_row + dr[now_dir];
			int next_col = now_col + dc[now_dir];

			if (next_row == start_row && next_col == start_col || MAP[next_row][next_col] == -1)
				break;

			//벽 안인 경우
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N) {
				if (MAP[next_row][next_col] == 0) { // 빈공간인경우
					now_row = next_row;
					now_col = next_col;

					continue;
				}
				else if (MAP[next_row][next_col] >= 6) {// 웜홀인경우
					if (next_row == wormhole[MAP[next_row][next_col] - 6].front().first && next_col == wormhole[MAP[next_row][next_col] - 6].front().second) {
						int temp_row = wormhole[MAP[next_row][next_col] - 6][1].first;
						int temp_col = wormhole[MAP[next_row][next_col] - 6][1].second;
						next_row = temp_row;
						next_col = temp_col;
					}
					else {
						int temp_row = wormhole[MAP[next_row][next_col] - 6][0].first;
						int temp_col = wormhole[MAP[next_row][next_col] - 6][0].second;
						next_row = temp_row;
						next_col = temp_col;
					}
				}
				else { //블록인경우
					int temp_dir = now_dir;
					now_dir = changeDir(now_dir, MAP[next_row][next_col]);
					score++;
					//왔던 길을 다시 돌아가는 경우 종료
					if (temp_dir == 0 && now_dir == 1) {
						score = 2 * score - 1;
						break;
					}
					else if (temp_dir == 1 && now_dir == 0) {
						score = 2 * score - 1;
						break;
					}
					else if (temp_dir == 2 && now_dir == 3) {
						score = 2 * score - 1;
						break;
					}
					else if (temp_dir == 3 && now_dir == 2) {
						score = 2 * score - 1;
						break;
					}
				}
			}
			else { //벽에 부딪힌 경우 = 왔던 길 다시 돌아가는 경우
				now_dir = changeDir(now_dir, 5);
				score++;
				score = score * 2 - 1;
				break;
			}
			now_row = next_row;
			now_col = next_col;
		}
		ans = max(ans, score);
	}
}
int main()
{
	int i, j;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		ans = 0;
		for (i = 0; i < 5; i++)
			wormhole[i].clear();

		vector <pair <int, int> > start;

		//1,1부터 N,N까지 입력을 받는다..
		for (i = 1; i <= N; i++)
			for (j = 1; j <= N; j++) {
				scanf("%d", &MAP[i][j]);
				if (MAP[i][j] >= 6) { //웜홀인 경우
					wormhole[MAP[i][j] - 6].push_back(make_pair(i, j));
				}
				if (MAP[i][j] == 0)
					start.push_back(make_pair(i, j));
			}

		for (i = 0; i < start.size(); i++) {
			start_row = start[i].first; start_col = start[i].second;
			simul();
		}
		printf("#%d %d\n", test_case, ans);
	}
}