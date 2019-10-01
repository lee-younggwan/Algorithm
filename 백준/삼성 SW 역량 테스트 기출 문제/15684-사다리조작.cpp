#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, H;
int visit[31][11];
int conn[31][11];
int ans = 987654321;
void print() {
	printf("-----------------------\n");
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
}
void playGame(int cnt) {
	//���μ����� ��ٸ��� ź��
	//if (visit[4][1] && visit[4][2])
		//printf("herehererherherehe\n");
	int check = 0;
	//print();
	for (int i = 1; i <= N; i++) {
		int now_ver = i;
		for (int j = 1; j <= H; j++) {
			//���μ��� ������ ������ ���μ��� ���� ����
			if (visit[j][now_ver] != 0) {
				//���μ��� ���������� ����Ǿ� �ִٸ�
				if (conn[j][now_ver] == 1)
					now_ver = now_ver + 1;
				//�������� ����Ǿ� �ִٸ�
				else if (conn[j][now_ver] == -1)
					now_ver = now_ver - 1;
			}
		}
		//�� �������� �� ���� ���μ��� ��ġ�� i�� �ٸ��ٸ� ����
		if (now_ver != i) {
			check = 1;
			break;
		}
	}
	if (check == 0) {
		ans = min(ans, cnt);
	}
}
//���μ�, ���μ�, ���̸� ���ڷ�
void dfs(int ver, int hor, int depth) {
	//�߰��� ���μ� ������ 3���� ū ���
	if (depth > 3)
		return;

	//��ٸ� ������ ����
		playGame(depth);

	for (int i = ver; i <= N-1; i++) {
		if (i != ver)
			hor = 1;
		for (int j = hor; j <= H; j++) {
			if (visit[j][i] == 0) {
				//�� ���μ��� �����ϰų� ���ϸ� �ȵȴ�
				if (visit[j][i+1] == 0) {
					//i�� ���μ��� i+1�� ���μ��� j�� ������ġ���� ����
					visit[j][i] = 2;
					visit[j][i+1] = 2;
					conn[j][i] = 1;
					conn[j][i + 1] = -1;
					//���μ��� �ٲ���...
					if (i != ver)
						dfs(i, 1, depth + 1);
					else
						dfs(i, j, depth + 1);
					conn[j][i + 1] = 0;
					conn[j][i] = 0;
					visit[j][i+1] = 0;
					visit[j][i] = 0;
				}
			}
		}
	}
}
int main() {
	int a, b;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 11; j++) {
			visit[i][j] = 0;
			conn[i][j] = 0;
		}
	}

	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		//b�� ���μ��� b+1�� ���μ��� a�� ������ġ���� ����
		scanf("%d %d", &a, &b);
		visit[a][b] = 1;
		visit[a][b+1] = 1;
		conn[a][b] = 1;
		conn[a][b+1] = -1;
	}

	dfs(1,1,0);

	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}