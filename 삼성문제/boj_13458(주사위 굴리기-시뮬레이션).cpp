#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0, 0,0,-1,1 }; //0�����ϳ�
int dc[] = { 0, 1,-1,0,0 };
int dice[] = { 0,0,0,0,0,0,0 };

int N, M, K;
int MAP[21][21];
int command;

void dicepose(int dir) {
	int temp[7];
	for (int i = 0; i < 7; i++)
		temp[i] = dice[i];

	if (dir == 1) { //����
		dice[1] = temp[4];
		dice[3] = temp[1];
		dice[4] = temp[6];
		dice[6] = temp[3];
	}
	else if (dir == 2) { //����
		dice[1] = temp[3];
		dice[3] = temp[6];
		dice[4] = temp[1];
		dice[6] = temp[4];
	}
	else if (dir == 3) { //����
		dice[1] = temp[5];
		dice[5] = temp[6];
		dice[6] = temp[2];
		dice[2] = temp[1];
	}
	else if (dir == 4) { //����
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

		//������ �ٱ����� �̵��ϴ� ��� �ش� ��� ����
		if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= M)
			continue;

		//�ֻ����� ���� ���
		dicepose(command);

		//�̵��� ĭ�� ���� 0�̸� �ֻ����� �ٴڸ鿡 �ִ� ���� ĭ�� ����
		if (MAP[next_row][next_col] == 0) {
			MAP[next_row][next_col] = dice[6];
		}
		else { //0�� �ƴϸ� ĭ�� �ִ� ���� �ֻ����� �ٴڸ鿡 ����, ĭ�� ���� �ִ� ���� 0����
			dice[6] = MAP[next_row][next_col];
			MAP[next_row][next_col] = 0;
		}

		printf("%d\n", dice[1]);

		now_row = next_row;
		now_col = next_col;
	}
}