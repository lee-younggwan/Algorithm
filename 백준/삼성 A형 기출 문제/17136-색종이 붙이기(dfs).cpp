#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <queue>
#include <vector>
using namespace std;

//https://lmcoa15.tistory.com/83

vector<vector<int>> MAP(10, vector<int>(10));
vector<vector<int>> visit(10, vector<int>(10));
int paper[6] = { 0,5,5,5,5,5 };
int answer = -1;
bool Check(int now_row, int now_col, int len) {

	for (int i = now_row; i < now_row + len; i++) {
		for (int j = now_col; j < now_col + len; j++) {
			if (MAP[i][j] == 0) {
				return false;
			}
		}
	}

	return true;
}
void Attach(int now_row, int now_col, int len) {
	for (int i = now_row; i < now_row + len; i++) {
		for (int j = now_col; j < now_col + len; j++) {
			if (MAP[i][j] == 0)
				MAP[i][j] = 1;
			else
				MAP[i][j] = 0;
		}
	}
}

bool allZero() {
	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			if (MAP[i][j] == 1) {
				return false;
			}
		}
	}
	return true;
}
void dfs(int cnt) {

	int i, j;
	if (answer != -1 && cnt > answer)
		return;

	if (allZero()) {
		if (answer == -1)
			answer = cnt;
		else
			answer = min(answer, cnt);
		return;
	}

	for (i = 0; i < 10; i++) {
		for (j = 0; j < 10; j++) {
			if (MAP[i][j] == 1)
				break;
		}
		if (j != 10)
			break;
	}

	for (int len = 5; len >= 1; len--) {
		//색종이가 없다면
		if (paper[len] == 0)
			continue;

		// len x len 크기의 색종이를 붙일 수 있다면
		if (i + len <= 10 && j + len <= 10) {
			if (Check(i, j, len)) {
				Attach(i, j, len);
				paper[len]--;

				dfs(cnt + 1);

				paper[len]++;
				Attach(i, j, len);
			}
		}
	}

}
int main() {

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++) {
			scanf("%d", &MAP[i][j]);
		}
	}
	dfs(0);

	printf("%d\n", answer);

	return 0;
}