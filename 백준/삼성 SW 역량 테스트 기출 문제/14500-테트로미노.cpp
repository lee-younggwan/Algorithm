#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int dr[] = { -1,0,1,0 };//위 오른 밑 왼
int dc[] = { 0,1,0,-1 };

int N, M;
int MAP[501][501];
int visit[501][501];
int ans = 0;
void calculFuck(int now_row, int now_col) {	
	int check = 0;
	int sum = 0;
	//ㅏ
	check = 0;
	sum = MAP[now_row][now_col];
	for (int i = 0; i < 4; i++) {
		if (i == 3)//왼쪽은 필요없음
			continue;
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			sum = sum + MAP[next_row][next_col];
		}
		else {
			check = 1;
			break;
		}
	}
	if (check == 0)
		ans = max(ans, sum);

	//ㅗ
	check = 0;
	sum = MAP[now_row][now_col];
	for (int i = 0; i < 4; i++) {
		if (i == 2)//밑쪽은 필요없음
			continue;
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			sum = sum + MAP[next_row][next_col];
		}
		else {
			check = 1;
			break;
		}
	}
	if (check == 0)
		ans = max(ans, sum);
	//ㅜ
	check = 0;
	sum = MAP[now_row][now_col];
	for (int i = 0; i < 4; i++) {
		if (i == 0)//위쪽은 필요없음
			continue;
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			sum = sum + MAP[next_row][next_col];
		}
		else {
			check = 1;
			break;
		}
	}
	if (check == 0)
		ans = max(ans, sum);
	//ㅓ
	check = 0;
	sum = MAP[now_row][now_col];
	for (int i = 0; i < 4; i++) {
		if (i == 1)//오른쪽은 필요없음
			continue;
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			sum = sum + MAP[next_row][next_col];
		}
		else {
			check = 1;
			break;
		}
	}
	if (check == 0)
		ans = max(ans, sum);
}
void dfs(int now_row, int now_col, int depth, int sum) {
	if (depth == 3) {
		ans = max(ans, sum);
		return;
	}

	for (int i = 0; i < 4; i++) {
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];
		
		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
			if (visit[next_row][next_col] != 1) {
				visit[next_row][next_col] = 1;
				dfs(next_row, next_col, depth + 1, sum+MAP[next_row][next_col]);
				visit[next_row][next_col] = 0;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			scanf("%d", &MAP[i][j]);

	//i, j부터 놓을 수 있는 모든 테트로미노를 계산..
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			visit[i][j] = 1;
			dfs(i, j, 0, MAP[i][j]);
			visit[i][j] = 0;
			//ㅗ 모양은 따로 처리
			calculFuck(i, j);
		}
	}

	printf("%d\n", ans);

	return 0;
}