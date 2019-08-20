#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0, 0,0,-1,1 }; //0동서북남
int dc[] = { 0, 1,-1,0,0 };
int dice[] = { 0,0,0,0,0,0,0 };

int N, M, K;
int MAP[21][21];
int command;

void dicepose(int dir) {
	int temp[7];
	for (int i = 0; i < 7; i++)
		temp[i] = dice[i];

	if (dir == 1) { //동쪽
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (dir == 2) { //서쪽
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (dir == 3) { //북쪽
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else if (dir == 4) { //남쪽
		dice[1] = temp[2];
		dice[5] = temp[1];
		dice[6] = temp[5];
		dice[2] = temp[6];
	}
}
int main()
{
	int i, j;
	int now_row, now_col, next_row, next_col;
	scanf("%d %d %d %d %d", &N, &M, &now_row, &now_col, &K);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++) {
			scanf("%d", &MAP[i][j]);
		}

	for (i = 0; i < K; i++) {
		scanf("%d", &command);

		next_row = now_row + dr[command];
		next_col = now_col + dc[command];

		//지도의 바깥으로 이동하는 경우 해당 명령 무시
		if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M)
			continue;

		//주사위의 면을 계산
		dicepose(command);

		//이동할 칸의 수가 0이면 주사위의 바닥면에 있는 수가 칸에 복사
		if (MAP[next_row][next_col] == 0) {
			MAP[next_row][next_col] = dice[6];
		}
		else { //0이 아니면 칸에 있는 수가 주사위의 바닥면에 복사, 칸에 쓰여 있는 수는 0으로
			dice[6] = MAP[next_row][next_col];
			MAP[next_row][next_col] = 0;
		}

		printf("%d\n", dice[1]);

		now_row = next_row;
		now_col = next_col;
	}
}