#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <algorithm>
using namespace std;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };
int T, N, W, H;
int ans = 9999;
int total = 0;
void copyArray(int a[15][12], int b[15][12]) {
	for (int i = 0; i < H; i++)
		for (int j = 0; j < W; j++)
			a[i][j] = b[i][j];
}
void print(int arr[15][12]) {
	for (int i = 0; i < H; i++) {
		for (int j = 0; j < W; j++)
			printf("%d ", arr[i][j]);
		printf("\n");
	}
}
void dfs(int j, int n, int copy[15][12], int count) {

	//종료조건
	if (n == N) {
		int res = 0;
		for (int i = 0; i < H; i++) {
			for (int j = 0; j < W; j++) {
				if (copy[i][j] > 0) {
					res++;
				}
			}
		}

		ans = min(ans, res);
		return;
	}
	int temp[15][12];
	copyArray(temp, copy);

	int bead = 0;
	queue <pair <pair <int, int>, int > > que;
	// n번째 벽돌을 j 열에서 떨어트림

	for (int i = 0; i < H; i++) {
		if (temp[i][j] != 0) {
			bead = temp[i][j];
			que.push(make_pair(make_pair(i, j),temp[i][j]));
			break;
		}
	}

	//벽돌을 깨트린다
	while (!que.empty()) {
		int now_row = que.front().first.first;
		int now_col = que.front().first.second;
		int scale = que.front().second - 1;
		que.pop();
		temp[now_row][now_col] = 0;
		count++;

		for (int i = 0; i < scale; i++) {
			for (int j = 0; j < 4; j++) {
				int next_row = now_row + dr[j] * (i + 1);
				int next_col = now_col + dc[j] * (i + 1);

				if (next_row >= 0 && next_row < H && next_col >= 0 && next_col < W) {
					if (temp[next_row][next_col] != 0) {
						count++;
						que.push(make_pair(make_pair(next_row, next_col),temp[next_row][next_col]));
						temp[next_row][next_col] = 0;
					}
				}
			}
		}
	}

	//벽독을 떨어트린다.
	for (int i = 0; i < W; i++) {
		for (int j = H - 1; j >= 0; j--) {
			//빈공간인 경우
			if (temp[j][i] == 0) {
				for (int k = j; k >= 0; k--) {
					if (temp[k][i] > 0) {
						temp[j][i] = temp[k][i];
						temp[k][i] = 0;
						break;
					}
				}
			}
		}
	}
	//printf("----%d-------%d----\n",j, n);
	//print(temp);
	for (int i = 0; i < W; i++) {
		dfs(i, n + 1, temp, count);
	}

}
int main() {

	int i, j, k;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &N, &W, &H);
		ans = 9999;
		total = 0;
		int MAP[15][12];
		for (i = 0; i < H; i++)
			for (j = 0; j < W; j++) {
				scanf("%d", &MAP[i][j]);
				if (MAP[i][j] > 0)
					total++;
			}

		for (j = 0; j < W; j++) {
			int temp[15][12];
			copyArray(temp, MAP);
			dfs(j, 0, temp, 0);
		}

		printf("#%d %d\n", test_case, ans);
	}

	return 0;
}