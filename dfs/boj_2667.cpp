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
int dc[] = { 0, 1, 0, -1 };

vector <int> answer;
int ans = 0, cnt = 0;
int N;
int MAP[26][26];
int visit[26][26];
void dfs(int now_row, int now_col, int count)
{
	ans = max(ans, count);
	visit[now_row][now_col] = 1;

	for (int i = 0; i < 4; i++) { //북동남서 방향으로 DFS
		int next_row = now_row + dr[i];
		int next_col = now_col + dc[i];

		if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
			if (!visit[next_row][next_col] && MAP[next_row][next_col] == 1) // 아직 방문하지 않았고 집이있는 경우
				dfs(next_row, next_col, ans + 1);
		}
	}
}
int main()
{
	int i, j;
	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%1d", &MAP[i][j]);

	for(i=0;i<N;i++)
		for (j = 0; j < N; j++) {
			if (!visit[i][j] && MAP[i][j] == 1) { //아직 방문하지 않았고 집이 있는경우
				ans = 0; cnt++;
				dfs(i, j, 1);
				answer.push_back(ans);
			}
		}

	printf("%d\n", cnt);
	sort(answer.begin(), answer.end());
	for (i = 0; i < answer.size(); i++)
		printf("%d\n", answer[i]);

	return 0;
}