#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int order[10];
int hitter[51][10];
int visit[10];
int answer = 0;
int playGame() {
	int i, j;
	int player, out, idx = 0, score = 0;

	//�̴׺��� �÷���
	for (i = 0; i < N; i++) {
		//3�ƿ� �Ǳ�������
		int loo[3] = { 0, };
		out = 0;
		while (out != 3) {
			player = order[idx++ % 9];

			//1��Ÿ
			if (hitter[i][player] == 1) {
				if (loo[2] == 1) { //3�翡 ����� �ִٸ�
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2�翡 ����� �ִٸ�
					loo[2] = 1;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1�翡 ����� �ִٸ�
					loo[1] = 1;
					loo[0] = 0;
				}
				loo[0] = 1;

			}//2��Ÿ
			else if (hitter[i][player] == 2) {
				if (loo[2] == 1) { //3�翡 ����� �ִٸ�
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2�翡 ����� �ִٸ�
					score++;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1�翡 ����� �ִٸ�
					loo[2] = 1;
					loo[0] = 0;
				}
				loo[1] = 1;

			}//3��Ÿ
			else if (hitter[i][player] == 3) {
				if (loo[2] == 1) { //3�翡 ����� �ִٸ�
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2�翡 ����� �ִٸ�
					score++;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1�翡 ����� �ִٸ�
					score++;
					loo[0] = 0;
				}
				loo[2] = 1;

			}//Ȩ��
			else if (hitter[i][player] == 4) {
				for (j = 0; j < 3; j++) {
					if (loo[j] == 1) {
						loo[j] = 0;
						score++;
					}
				}
				score++;
			}//�ƿ�
			else
				out++;
		}
	}
	return score;
}
void dfs(int depth) {

	if (depth == 9) {
		answer = max(answer, playGame());
		return;
	}

	//������ ���� ������ �����
	for (int i = 0; i < 9; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			order[i] = depth;
			dfs(depth + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < 9; j++)
			scanf("%d", &hitter[i][j]);

	//4��° Ÿ�ڴ� 1�� ����
	//4��°�� �̹� ����
	order[3] = 0;
	visit[3] = 1;
	dfs(1);

	printf("%d\n", answer);
	return 0;
}