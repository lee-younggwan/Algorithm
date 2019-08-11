#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0, 1, 0 ,-1 }; // �� �� �� �� ����
int dc[] = { 1, 0, -1, 0 };

queue <pair <int, int> >que;

int N, K, L;
int MAP[101][101];
int visit[101][101];
int sec[101];
char command[101];
int dir;
int time;
int phase;
int main()
{
	int i;
	int x, y;

	scanf("%d", &N);
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		MAP[x-1][y-1] = 1; //����� ��ġ, ���������� 1�� 1������ �����̹Ƿ�
	}

	scanf("%d", &L);
	for (i = 0; i < L; i++)
		scanf("%d %c", &sec[i], &command[i]);

	//ó������, �ð�, �ܰ�(������ȯ) �ʱ�ȭ
	dir = 0; 
	time = 0;
	phase = 0;

	que.push(make_pair(0, 0));
	int now_row = 0;
	int now_col = 0;
	visit[0][0] = 1;

	while (!que.empty()) {

		time++;
		int next_row = now_row + dr[dir];
		int next_col = now_col + dc[dir];

		//�� or �ڱ��ڽŰ� �ε��� ���
		if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N || visit[next_row][next_col] == 1) {
			printf("%d\n", time);
			break;
		}
		que.push(make_pair(next_row, next_col));
		visit[next_row][next_col] = 1;

		//����� �ִ� ���
		if (MAP[next_row][next_col]) {
			MAP[next_row][next_col] = 0; //����� �Դ´�
		}
		else { //����� ���� ��� que���� pop�� �ϰ� visit�� 0���� �ٲ۴�
			int tail_row = que.front().first;
			int tail_col = que.front().second;
			que.pop();

			visit[tail_row][tail_col] = 0;
		}

		//time�� ������ ��ȯ�� �ð��� �Ǿ��� ���
		if (time == sec[phase]) {
			if (command[phase] == 'L')  //���� 90�� ȸ���̶��
				dir = (dir + 3) % 4;
			else
				dir = (dir + 5) % 4;
			phase++;
		}
		now_row = next_row;
		now_col = next_col;
	}
}