#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int N, M;
char MAP[11][11];
char COPY[11][11];
vector <int> dir;
int ans = 987654321;
int red_row, red_col, blue_row, blue_col;
int tr_row, tr_col, tb_row, tb_col;
int moveUp() {

	//�Ķ������� ���� ��ġ�� ������ ���� ���� ��ġ���� ���� �ִٸ� �Ķ����� ���� ������
	if (tb_row <= tr_row) {
		//�Ķ����� ���� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�������� ���� ������
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �����Ѵ�(���������� ���ۿ� ������ ����)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//���̰ų� �Ķ������̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//���������� ���� ��ġ�� �Ķ������� ���� �ִٸ� ���� ���� ���� ������
	else {
		//�������� ���� ������
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �Ķ��� ������ ������ �Ķ������� ���ۿ� ������ �ʴ´ٸ� �����Ѵ�
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�Ķ����� ���� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̰ų� ���� ���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}
int moveDown() {
	//�Ķ������� ���� ��ġ�� ������ ���� ���� ��ġ���� �Ʒ��� �ִٸ� �Ķ����� ���� ������
	if (tb_row >= tr_row) {
		//�Ķ����� �Ʒ��� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�������� �Ʒ��� ������
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �����Ѵ�(���������� ���ۿ� ������ ����)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//���̰ų� �Ķ������̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//���������� ���� ��ġ�� �Ķ������� �Ʒ��� �ִٸ� ���� ���� ���� ������
	else {
		//�������� �Ʒ��� ������
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �Ķ��� ������ ������ �Ķ������� ���ۿ� ������ �ʴ´ٸ� �����Ѵ�
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�Ķ����� �Ʒ��� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̰ų� ���� ���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}

int moveLeft() {
	//�Ķ������� ���� ��ġ�� ������ ���� ���� ��ġ���� ���ʿ� �ִٸ� �Ķ����� ���� ������
	if (tb_col <= tr_col) {
		//�Ķ����� �������� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col-1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�������� �������� ������
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col-1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �����Ѵ�(���������� ���ۿ� ������ ����)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//���̰ų� �Ķ������̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//���������� ���� ��ġ�� �Ķ������� ���ʿ� �ִٸ� ���� ���� ���� ������
	else {
		//�������� �������� ������
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col - 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �Ķ��� ������ ������ �Ķ������� ���ۿ� ������ �ʴ´ٸ� �����Ѵ�
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�Ķ����� �������� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col - 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̰ų� ���� ���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}

int moveRight() {
	//�Ķ������� ���� ��ġ�� ������ ���� ���� ��ġ���� �����ʿ� �ִٸ� �Ķ����� ���� ������
	if (tb_col >= tr_col) {
		//�Ķ����� �������� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�������� ���������� ������
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �����Ѵ�(���������� ���ۿ� ������ ����)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//���̰ų� �Ķ������̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//���������� ���� ��ġ�� �Ķ������� �����ʿ� �ִٸ� ���� ���� ���� ������
	else {
		//�������� ���������� ������
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//�����̶�� �Ķ��� ������ ������ �Ķ������� ���ۿ� ������ �ʴ´ٸ� �����Ѵ�
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//�Ķ����� ���������� ������
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//�� ĭ�̶�� ���� �ű�� �������� �ִ� ��ġ�� ����
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//�����̶�� �����Ѵ�(�Ķ������� ���ۿ� ������ ����
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//���̰ų� ���� ���̶�� �� �ڸ����� �����Ѵ�
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}
void playGame(int cnt) {
	int i, j;
	
	//�������� ó�� ��ġ �ʱ�ȭ
	tr_row = red_row, tr_col = red_col;
	tb_row = blue_row, tb_col = blue_col;

	for (i = 0; i < dir.size(); i++) {
		//���� ����δ�.
		if (dir[i] == 0) {
			int res = moveUp();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}
		//�Ʒ��� ����δ�
		else if (dir[i] == 1) {
			int res = moveDown();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}//�������� ����δ�
		else if (dir[i] == 2) {
			int res = moveLeft();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}//���������� ����δ�
		else if (dir[i] == 3) {
			int res = moveRight();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}
	}
}
void dfs(int depth) {
	if (depth == 10) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				COPY[i][j] = MAP[i][j];
		playGame(depth);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (dir.empty()) {
			dir.push_back(i);
			dfs(depth + 1);
			dir.pop_back();
		}
		else {
			//��￴�� �������� �� ����̴� ���ų�
			//��￴�� ������ �ݴ� �������� ����̴� ���� �ǹ̰� ���� ���
			if (dir.back() == i)
				continue;
			if (i == 0 && dir.back() == 1)
				continue;
			if (i == 1 && dir.back() == 0)
				continue;
			if (i == 2 && dir.back() == 3)
				continue;
			if (i == 3 && dir.back() == 2)
				continue;

			dir.push_back(i);
			dfs(depth + 1);
			dir.pop_back();
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = temp[j];
			if (MAP[i][j] == 'R') {
				red_row = i;
				red_col = j;
			}
			if (MAP[i][j] == 'B') {
				blue_row = i;
				blue_col = j;
			}
		}
	}
	
	//�ߺ������� �����
	dfs(0);

	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}