#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int N, M;
int MAP[9][9];
int COPY[9][9];
vector <pair <pair <int, int>, int> > cctv;
int visit[9] = { -1, -1,-1,-1,-1,-1,-1,-1,-1};
int answer = 64;
void print() {
	printf("--------------\n");
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++)
			printf("%d ", COPY[i][j]);
		printf("\n");
	}
}

void up(int now_row, int now_col) {
	for (int j = now_row - 1; j >= 0; j--) {
		if (COPY[j][now_col] == 6) //���� ���
			break;
		else if (COPY[j][now_col] == 0) //�� ������ ���
			COPY[j][now_col] = -1;
		else//�ٸ� cctv�� �ִ� ���
			continue;
	}
}
void right(int now_row, int now_col) {
	for (int j = now_col + 1; j < M; j++) {
		if (COPY[now_row][j] == 6) //���� ���
			break;
		else if (COPY[now_row][j] == 0) //�� ������ ���
			COPY[now_row][j] = -1;
		else//�ٸ� cctv�� �ִ� ���
			continue;
	}
}
void down(int now_row, int now_col) {
	for (int j = now_row + 1; j < N; j++) {
		if (COPY[j][now_col] == 6) //���� ���
			break;
		else if (COPY[j][now_col] == 0) //�� ������ ���
			COPY[j][now_col] = -1;
		else//�ٸ� cctv�� �ִ� ���
			continue;
	}
}
void left(int now_row, int now_col) {
	for (int j = now_col - 1; j >= 0; j--) {
		if (COPY[now_row][j] == 6) //���� ���
			break;
		else if (COPY[now_row][j] == 0) //�� ������ ���
			COPY[now_row][j] = -1;
		else//�ٸ� cctv�� �ִ� ���
			continue;
	}
}
void moniToring() {
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			COPY[i][j] = MAP[i][j];

	for (int i = 0; i < cctv.size(); i++) {
		int now_row = cctv[i].first.first;
		int now_col = cctv[i].first.second;
		int kind = cctv[i].second;

		//1�� cctv�� ���
		if (kind == 1) {
			if (visit[i] == 0) { //��
				up(now_row, now_col);
			}
			else if (visit[i] == 1) { //������
				right(now_row, now_col);
			}
			else if (visit[i] == 2) { //�Ʒ�
				down(now_row, now_col);
			}
			else { //����
				left(now_row, now_col);
			}
		}//2�� cctv�� ���
		else if (kind == 2) {
			if (visit[i] == 0) { //����, ������
				left(now_row, now_col);
				right(now_row, now_col);
			}
			else { //��, �Ʒ�
				up(now_row, now_col);
				down(now_row, now_col);
			}
		}
		else if (kind == 3) {
			if (visit[i] == 0) { //��, ������
				up(now_row, now_col);
				right(now_row, now_col);
			}
			else if (visit[i] == 1) { //������, �Ʒ�
				right(now_row, now_col);
				down(now_row, now_col);
			}
			else if (visit[i] == 2) { // �Ʒ�, ����
				down(now_row, now_col);
				left(now_row, now_col);
			}
			else if (visit[i] == 3) { //����, ��
				left(now_row, now_col);
				up(now_row, now_col);
			}
		}
		else if (kind == 4) {
			if (visit[i] == 0) { //�� �� ��
				left(now_row, now_col);
				up(now_row, now_col);
				right(now_row, now_col);
			}
			else if (visit[i] == 1) { //�� �� ��
				up(now_row, now_col);
				right(now_row, now_col);
				down(now_row, now_col);
			}
			else if (visit[i] == 2) { //�� �� ��
				right(now_row, now_col);
				down(now_row, now_col);
				left(now_row, now_col);
			}
			else if (visit[i] == 3) { // �� �� ��
				down(now_row, now_col);
				left(now_row, now_col);
				up(now_row, now_col);
			}
		}
		else if (kind == 5) {
			up(now_row, now_col);
			right(now_row, now_col);
			down(now_row, now_col);
			left(now_row, now_col);
		}
	}
	//print();
	int sum = 0;
	for (int i = 0; i < N; i++)
		for (int j = 0; j < M; j++)
			if (COPY[i][j] == 0)
				sum++;

	answer = min(answer, sum);
}

void dfs(int idx, int depth) {
	if (depth == cctv.size()){
		moniToring();
		return;
	}

	for (int i = idx; i < cctv.size(); i++) {
		//���� �湮���� ���� cctv���
		if (visit[i] == -1) {
			//cctv�� ������ ���� ���ù����� �ִ´�

			switch (cctv[i].second) {
			case 1: 
			case 3:
			case 4:
				for (int j = 0; j < 4; j++) {
					visit[i] = j;
					dfs(i, depth + 1);
					visit[i] = -1;
				}
				break;
			case 2:
				for (int j = 0; j < 2; j++) {
					visit[i] = j;
					dfs(i, depth + 1);
					visit[i] = -1;
				}
				break;
			case 5:
				visit[i] = 0;
				dfs(i, depth + 1);
				visit[i] = -1;
				break;
			}
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] != 0 && MAP[i][j] != 6)
				cctv.push_back(make_pair(make_pair(i, j), MAP[i][j]));
		}
	}

	dfs(0, 0);

	printf("%d\n", answer);

	return 0;
}