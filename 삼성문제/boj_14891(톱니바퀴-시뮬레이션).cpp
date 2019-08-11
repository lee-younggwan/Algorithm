#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int K;
int MAP[4][9];
int visit[4];
vector <pair <int, int>> command[101];

void rotation(int idx, int dir)
{
	int i;
	int left = MAP[idx][6];
	int right = MAP[idx][2];

	visit[idx] = 1;
	// ����� �´��� �κ��� left, right�� �����ϰ� ���� ��ϸ� ȸ����Ų��
	if (dir == 1) {
		for (i = 7; i >= 0; i--)
			MAP[idx][i + 1] = MAP[idx][i];
		MAP[idx][0] = MAP[idx][8];
	}
	else {
		MAP[idx][8] = MAP[idx][0];
		for (i = 0; i < 8; i++)
			MAP[idx][i] = MAP[idx][i + 1];
	}

	//����� idx�� ���� ȸ��
	if (idx == 0) {
		if (!visit[1])
			if (right != MAP[1][6]) // 0�� ��Ϲ����� 1�� ��Ϲ����� ���� �ٸ��ٸ� 1�� ��ϸ� ȸ��
				rotation(1, dir*-1);
	}
	else if (idx == 1) {
		if (!visit[0])
			if (left != MAP[0][2])
				rotation(0, dir*-1);

		if (!visit[2])
			if (right != MAP[2][6])
				rotation(2, dir*-1);
	}
	else if (idx == 2) {
		if (!visit[1])
			if (left != MAP[1][2])
				rotation(1, dir*-1);

		if (!visit[3])
			if (right != MAP[3][6])
				rotation(3, dir*-1);
	}
	else if (idx == 3) {
		if (!visit[2])
			if (left != MAP[2][2])
				rotation(2, dir*-1);
	}
}
int main()
{
	int i, j;
	int idx, dir;
	for (i = 0; i < 4; i++)
		for (j = 0; j < 8; j++)
			scanf("%1d", &MAP[i][j]);

	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d %d", &idx, &dir);
		memset(visit, 0, sizeof(visit));
		rotation(idx - 1, dir);
	}

	int ans = 0;
	if (MAP[0][0])
		ans = ans + 1;
	if (MAP[1][0])
		ans = ans + 2;
	if (MAP[2][0])
		ans = ans + 4;
	if (MAP[3][0])
		ans = ans + 8;
	printf("%d\n", ans);
}