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

int MAP[9][9];
int visit[9][9];
int COPY[9][9];
int visit2[9][9];
int N, M;
int ans = -1;
void bfs()
{
	queue <pair <int, int>> que;
	int i, j, cnt=0;
	int virus[9][9];
	int now_row, now_col, next_row, next_col;

	for(i=0;i<N;i++)
		for (j = 0; j < M; j++) {
			virus[i][j] = COPY[i][j];
			if (virus[i][j] == 2) //바이러스의 위치를 que에 집어 넣는다
				que.push(make_pair(i, j));
		}

	while (!que.empty()) {
		now_row = que.front().first;
		now_col = que.front().second;
		que.pop();

		for (i = 0; i < 4; i++) {
			next_row = now_row + dr[i];
			next_col = now_col + dc[i];

			if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
				if (virus[next_row][next_col] == 0) { //빈칸이라면 바이러스를 전파
					virus[next_row][next_col] = 2;
					que.push(make_pair(next_row, next_col));
				}
			}
		}
	}
	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			if (virus[i][j] == 0)
				cnt++;
	ans = max(ans, cnt);
}
void makewall(int cnt)
{
	//벽을 3개 세웠으면 바이러스를 퍼뜨린다
	if (cnt == 3) {
		bfs();
		return;
	}

	for(int i=0;i<N;i++)
		for (int j = 0; j < M; j++) {
			if (COPY[i][j] == 0) { //빈칸이면 벽을 세운다
				COPY[i][j] = 1;
				makewall(cnt + 1);
				COPY[i][j] = 0;
			}
		}
}
int main()
{
	int i, j, k, t;
	scanf("%d %d", &N	, &M);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			scanf("%d", &MAP[i][j]);

	//벽 3개를 세우고 바이러스를 퍼뜨린다
	for(i=0;i<N;i++)
		for (j = 0; j < M; j++) {
			if (MAP[i][j] == 0) {//빈 칸이라면 벽을 세운다
				
				for (k = 0; k < N; k++)//맵을 copy
					for (t = 0; t < M; t++)
						COPY[k][t] = MAP[k][t];

				COPY[i][j] = 1; //일단 벽을 세우고
				makewall(1);
				COPY[i][j] = 0;
			}
		}
	printf("%d\n", ans);
}