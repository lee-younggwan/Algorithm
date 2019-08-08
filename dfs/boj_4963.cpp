#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1, 0, 1, 0, -1, -1, 1, 1 }; //8방향
int dc[] = { 0, 1, 0, -1, -1, 1, 1, -1 };

int visit[51][51];
int MAP[51][51];
int w, h;
void dfs(int now_row, int now_col)
{
	visit[now_row][now_col] = 1;

	for (int i = 0; i < 8; i++) { //북동남서 방향으로 DFS
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];

		if (next_row >= 0 && next_row < h && next_col >= 0 && next_col < w) {
			if (!visit[next_row][next_col] && MAP[next_row][next_col] == 1) // 아직 방문하지 않았고 집이있는 경우
				dfs(next_row, next_col);
		}
	}
}
int main()
{
	int i, j;
	int cnt;
	while (1) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		memset(MAP, 0, sizeof(MAP));

		scanf("%d %d", &w, &h);
		if (w == 0 && h == 0)
			break;
		for (i = 0; i < h; i++)
			for (j = 0; j < w; j++)
				scanf("%d", &MAP[i][j]);

		for(i=0;i<h;i++)
			for (j = 0; j < w; j++) {
				if (!visit[i][j] && MAP[i][j]) {
					dfs(i, j);	
					cnt++;
				}
			}
		printf("%d\n", cnt);
	}
	return 0;
}