#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <queue>
using namespace std;


// ���� ������ ������ ��� �Լ� ���� �ʱ�ȭ �ڵ带 �� �ۼ����ּ���.

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int i, j;
	int visit[101][101];
	for (i = 0; i < 101; i++)
		for (j = 0; j< 101; j++)
			visit[i][j] = 0;

	int dr[] = { -1,0,1,0 };
	int dc[] = { 0,1,0,-1 };

	queue <pair <int, int> > que;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			//��ĥ���� ���� ������ �ƴϰ� �湮������ ���� ���
			//������ ������ 1�� �ø��� bfs�� ������ �ֺ��� ���� �������� Ȯ��
			if (visit[i][j] != 1 && picture[i][j] != 0) {
				number_of_area++;
				que.push(make_pair(i, j));
				visit[i][j] = 1;
				int count = 1;

				while (!que.empty()) {
					int now_row = que.front().first;
					int now_col = que.front().second;
					que.pop();

					for (int k = 0; k < 4; k++) {
						int next_row = now_row + dr[k];
						int next_col = now_col + dc[k];

						//���� ��ġ�� ���� ���̰� ���� �湮���� �ʰ�, ���� ���� ��� que�� �ִ´�
						if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n) {
							if (visit[next_row][next_col] != 1 && picture[next_row][next_col] == picture[now_row][now_col]) {
								que.push(make_pair(next_row, next_col));
								count++;
								visit[next_row][next_col] = 1;
							}
						}
					}
				}
				max_size_of_one_area = max(count, max_size_of_one_area);
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	solution(6, 4, { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} });
}