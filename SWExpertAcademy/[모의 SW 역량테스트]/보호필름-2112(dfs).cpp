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

int MAP[14][21];
int COPY[14][21];
int T, D, W, K;
int ans = 9999;
void copyRow(int A[], int B[])
{
	for (int i = 0; i < W; i++)
		A[i] = B[i];
}
void dfs(int row, int cnt)
{
	int i, j;
	int temp[21];
	if (cnt >= ans) // 약품 투입횟수가 ans보다 큰경우 
		return;

	if (row >= D) { // 마지막 행까지 다 퍼뜨린 경우
		for (i = 0; i < W; i++) {
			int cont = 1;
			for (j = 0; j < D - 1; j++) {
				if (cont == K)
					break;
				if (MAP[j][i] == MAP[j + 1][i])
					cont++;
				else
					cont = 1;
			}
			if (cont != K)
				return;
		}
		ans = min(ans, cnt);
	}
	// 1. 현재 행에 아무것도 퍼뜨리지 않는 경우
	// 2. 현재 행에 A 특성을 퍼뜨리는 경우
	// 3. 현재 행에 B 특성을 퍼뜨리는 경우

	dfs(row + 1, cnt); // 1번

	copyRow(temp, MAP[row]); // 2번
	for (i = 0; i < W; i++)
		MAP[row][i] = 0;
	dfs(row + 1, cnt + 1);
	copyRow(MAP[row], temp);

	copyRow(temp, MAP[row]); // 3번
	for (i = 0; i < W; i++)
		MAP[row][i] = 1;
	dfs(row + 1, cnt + 1);
	copyRow(MAP[row], temp);
}
int main()
{
	int i, j;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d %d", &D, &W, &K);
		for (i = 0; i < D; i++)
			for (j = 0; j < W; j++) {
				scanf("%d", &MAP[i][j]); // 0은 A 1은 B
				COPY[i][j] = MAP[i][j];
			}
		ans = 9999;
		dfs(0, 0);
		printf("#%d %d\n", test_case, ans);
	}
}
