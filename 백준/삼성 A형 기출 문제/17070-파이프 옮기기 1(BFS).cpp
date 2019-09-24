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

	//��ǥ��, (0=����, 1=����, 2=�밢��)
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

		//���� �������� ���ι����� ��� ���ο� �밢���������� �� �� ����.
		if (now_dir == 0) {
			//���� �������� ���� ���
			int next_row = now_row;
			int next_col = now_col + 1;
			int next_dir = 0;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//�밢�� �������� ���� ���
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

		}//���ι����� ��� ���ο� �밢�� �������� �� �� ����.
		else if (now_dir == 1) {
			//���� �������� ���� ���
			int next_row = now_row + 1;
			int next_col = now_col;
			int next_dir = 1;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//�밢�� �������� ���� ���
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

		}//�밢�������� ��� ���� ���� �밢�� �������� �� �� ����.
		else {
			//���� �������� ���� ���
			int next_row = now_row + 1;
			int next_col = now_col;
			int next_dir = 1;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//���� �������� ���� ���
			next_row = now_row;
			next_col = now_col + 1;
			next_dir = 0;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));

			//�밢�� �������� ���� ���
			next_row = now_row + 1;
			next_col = now_col + 1;
			next_dir = 2;

			//MAP�ȿ� �ְ� �� �� ĭ�̾�� �ϴ� ���̸�
			if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N)
				if (MAP[next_row][next_col] == 0 && MAP[next_row - 1][next_col] == 0 && MAP[next_row][next_col - 1] == 0)
					que.push(make_pair(make_pair(next_row, next_col), next_dir));
		}

	}
	
	printf("%d\n", answer);
	return 0;
}