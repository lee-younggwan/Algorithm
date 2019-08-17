#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

int MAP[21][21];
int T, N, M;
int ans = 0;

bool checked(int K, int home)
{
	if (M*home - (K * K + (K - 1)*(K - 1)) >= 0)
		return true;
	return false;
}
void bfs(int row, int col)
{
	int visit[21][21];
	int home = 0;
	int K = 1;
	int q_size;
	queue <pair <int, int> > que;

	que.push(make_pair(row, col));
	visit[row][col] = 1;
	if (MAP[row][col])
		home++;

	while (!que.empty()) {
		q_size = que.size();
		if (checked(K, home)) {
			ans = max(ans, home);
		}
		if (K == N + 1)
			return;

		while (q_size--) {
			int now_row = que.front().first;
			int now_col = que.front().second;
			que.pop();

			for (int i = 0; i < 4; i++) {
				int next_row = now_row + dr[i];
				int next_col = now_col + dc[i];

				if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
					if (visit[next_row][next_col] != 1) {
						if (MAP[next_row][next_col])
							home++;
						que.push(make_pair(next_row, next_col));
						visit[next_row][next_col] = 1;
					}
				}
			}
		}
		K++;
	}
}
int main()
{
	int i, j;
	cin >> T;

	for (int test_case = 1; test_case <= T; test_case++) {
		ans = -99999;
		cin >> N >> M;
		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				cin >> MAP[i][j];

		for (i = 0; i < N; i++)
			for (j = 0; j < N; j++)
				bfs(i, j);

		cout << "#" << test_case << " " << ans << "\n";
	}
}