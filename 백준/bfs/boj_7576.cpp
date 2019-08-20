#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

queue <pair <pair <int, int>, int > > que;
int MAP[1001][1001];
int visit[1001][1001];
int N, M;
int ans = 0;
int flag = 0;
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 1) //�丶���� Que�� ��ġ�� ��¥�� ����
				que.push(make_pair(make_pair(i, j), 0));
		}

	while (!que.empty()) {
		int now_row = que.front().first.first;
		int now_col = que.front().first.second;
		int now_day = que.front().second;
		que.pop();

		for (i = 0; i < 4; i++) {
			int next_row = now_row + dr[i];
			int next_col = now_col + dc[i];
			int next_day = now_day + 1;
			if (next_row >= 0 && next_row < M && next_col >= 0 && next_col < N)//�ʹ���
				if (MAP[next_row][next_col] == 0) {
					flag = 1; // ��� �丶�䰡 ���� ���°� �ƴ�
					MAP[next_row][next_col] = next_day;
					que.push(make_pair(make_pair(next_row, next_col), next_day));
				}
		}
	}
	for (i = 0; i < M; i++)
		for (j = 0; j < N; j++) {
			if (MAP[i][j] == 0) { // ��� ���� ���� ��Ȳ�� �ִ°��
				flag = 2;
				break;
			}
			ans = max(ans, MAP[i][j]);
		}
	if (flag == 0) //��� �丶�䰡 ��������
		printf("0\n");
	else if (flag == 2) //��� ���� ���ϴ� ��Ȳ
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}