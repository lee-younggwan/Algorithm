#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
using namespace std;

int N;
int answer = 0;
int MAP[17][17];

int main() {
	int i, j;

	scanf("%d", &N);
	for (i = 1; i <= N; i++)
		for (j = 1; j <= N; j++)
			scanf("%d", &MAP[i][j]);

	//좌표쌍, (0=가로, 1=세로, 2=대각선)
	queue <pair <pair <int, int>, int> > que;
	que.push(make_pair(make_pair(1, 2), 0));

	while (!que.empty()) {
		int now_row = que.front().first.first;
		int now_col = que.front().first.second;
		int now_dir = que.front().second;
		que.pop();

		if (now_row == N && now_col == N) {
			answer++;
			continue;
		}

		//현재 파이프가 가로방향인 경우 가로와 대각선방향으로 갈 수 있음.
		if (now_dir == 0) {
			//가로 방향으로 가는 경우
			int next_row = now_row;
			int next_col = now_col + 1;
			int next_dir = 0;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//대각선 방향으로 가는 경우
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

		}//세로방향인 경우 세로와 대각선 방향으로 갈 수 있음.
		else if (now_dir == 1) {
			//세로 방향으로 가는 경우
			int next_row = now_row + 1;
			int next_col = now_col;
			int next_dir = 1;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//대각선 방향으로 가는 경우
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

		}//대각선방향인 경우 가로 세로 대각선 방향으로 갈 수 있음.
		else {
			//세로 방향으로 가는 경우
			int next_row = now_row + 1;
			int next_col = now_col;
			int next_dir = 1;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//가로 방향으로 가는 경우
			next_row = now_row;
			next_col = now_col + 1;
			next_dir = 0;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//대각선 방향으로 가는 경우
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP안에 있고 꼭 빈 칸이어야 하는 곳이면
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));
		}

	}
	
	printf("%d\n", answer);
	return 0;
}