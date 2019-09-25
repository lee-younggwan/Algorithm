#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;
int enemy = 0;
int answer = 0;
int N, M, D;
vector<vector<int> > MAP(16, vector<int>(16));
int flag[16] = { 0, };

int Fight(vector <int> archer) {

	int i, j, d, k;
	int count = 0;
	vector<vector<int>> COPY = MAP;
	vector<vector<int>> visit(16, vector<int>(16));

	for (i = N - 1; i >= 0; i--) {
		queue <pair <int, int> > que;

		for (j = 0; j < 3; j++) {
			//���� �ü��� ��ġ
			int now_row = i + 1;
			int now_col = archer[j];

			//�Ÿ� 1���� D���� Ž��
			for (d = 1; d <= D; d++) {
				int d_r = -1;
				int d_c = (d-1) * (-1);

				//���� �ü��� ��ġ���� �� ������� ���ʺ��� Ž��
				for (k = 1; k < d * 2; k++) {
					int next_row = now_row + d_r;
					int next_col = now_col + d_c;

					//���� �ְ� ���� �湮�� ���� ���ٸ� que�� �ְ� break
					//���� �ְ� �湮������ �ִٸ� break
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < M) {
						if (COPY[next_row][next_col] == 1) {
							if (visit[next_row][next_col] != 1) {
								visit[next_row][next_col] = 1;
								que.push(make_pair(next_row, next_col));
							}
							break;
						}
					}
					//��ġ ����
					if (k < d)
						d_r--;
					else
						d_r++;
					d_c++;
				}
				//���� 1���̶� ã�Ҵٸ� break
				if (k != d * 2)
					break;
			}
		}
		while (!que.empty()) {
			int now_row = que.front().first;
			int now_col = que.front().second;
			que.pop();
			COPY[now_row][now_col] = 0;
			count++;
		}
	}
	return count;

}
void dfs(int depth, vector <int> position) {
	if (depth == 3) {
		//�ü� 3�� �� ��ġ�� ��� ������ �� �ִ� ���� �ִ� �� ���
		answer = max(answer, Fight(position));
		return;
	}
	for (int i = 0; i < M; i++)
		if (!flag[i]) {
			flag[i] = 1;
			vector <int> temp = position;
			temp.push_back(i);
			dfs(depth + 1, temp);
			flag[i] = 0;
		}
}
int main() {
	int i, j, temp;
	scanf("%d %d %d", &N, &M, &D);

	for (i = 0; i < N; i++)
		for (j = 0; j < M; j++)
			cin >> MAP[i][j];


	dfs(0, { });
	printf("%d\n", answer);
	return 0;
}