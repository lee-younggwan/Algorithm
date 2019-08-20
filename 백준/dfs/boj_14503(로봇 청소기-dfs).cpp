#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1,0,1,0 }; //북동남서
int dc[] = { 0,1,0,-1 };

int MAP[51][51];
int N, M;
int r, c;
int ans = 0;
void dfs(int now_row, int now_col, int dir)
{
	int next_dir, next_row, next_col;

	if (MAP[now_row][now_col] == 1) //벽이면 종료한다
		return;

	if (MAP[now_row][now_col] == 0) //현재 위치를 청소
	{
		MAP[now_row][now_col] = 2;
		ans++;
	}
	for (int i = 0; i < 4; i++) {
		next_dir = (dir + 3 ) % 4;
		next_row = now_row + dr[next_dir];
		next_col = now_col + dc[next_dir];

		//아직 청소하지 않은 공간이 존재한다면
		if (MAP[next_row][next_col] == 0) {
			dfs(next_row, next_col, next_dir);
			return;
		}
		dir = next_dir;
	}

	//네 방향 모두 청소가 이미 되어있거나 벽인 경우, 바라보는 방향을 유지한 채로 한 칸 후진
	next_row = now_row + -1*dr[next_dir];
	next_col = now_col + -1*dc[next_dir];
	dfs(next_row, next_col, next_dir);
}
int main()
{
	int i, j;
	int dir;
	scanf("%d %d", &N, &M);
	scanf("%d %d %d", &r, &c, &dir);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &MAP[i][j]);

	dfs(r, c, dir);
	printf("%d\n", ans);

}