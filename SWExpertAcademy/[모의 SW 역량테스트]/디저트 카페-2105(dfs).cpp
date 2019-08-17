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

int dr[] = { 1,1,-1,-1 };// 하우,하좌,상좌,상우
int dc[] = { 1,-1,-1,1 };


int disert[101];
int visit[21][21];
int MAP[21][21];
int T, N;
int start_row, start_col;
int ans = -1;
vector <pair <int, int> > vec;
void dfs(int now_row, int now_col, int dir, int cnt)
{
	if (now_row == start_row && now_col == start_col && cnt > 1) {
		ans = max(ans, cnt);
		return;
	}
	
	for (int i = 0; i < 2; i++) { // 지금 위치에서 갈 수 있는 방향은 현재 보는 방향과 오른쪽으로 90도 돌린방향
		int next_dir = dir + i;
		int next_row = now_row + dr[next_dir];
		int next_col = now_col + dc[next_dir];
		int next_cnt = cnt + 1;

		if (next_row == start_row && next_col == start_col) {
			dfs(next_row, next_col, next_dir, cnt + 1);
		}
		else if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) { //다음 위치가 범위 안이고
			if (!disert[MAP[next_row][next_col]] && !visit[next_row][next_col]) { // 아직 선택하지 않은 디저트라면 
				disert[MAP[next_row][next_col]] = 1;
				visit[next_row][next_col] = 1;
				dfs(next_row, next_col, next_dir, next_cnt);
				disert[MAP[next_row][next_col]] = 0;
				visit[next_row][next_col] = 0;
			}
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &T);

	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++) {
				scanf("%d", &MAP[i][j]);
				visit[i][j] = 0;
			}
		memset(disert, 0, sizeof(disert));
		ans = -1;

		for (i = 0; i < N-1; i++)
			for (j = 1; j < N-1; j++) {
				start_row = i; start_col = j;
				disert[MAP[i][j]] = 1;
				dfs(i, j, 0, 0);
				disert[MAP[i][j]] = 0;
			}
		printf("#%d %d\n", test_case, ans);
	}
}