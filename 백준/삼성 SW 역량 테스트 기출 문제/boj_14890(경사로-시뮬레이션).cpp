#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int N, L;
int MAP[101][101];
int visit[101];
int ans = 0;
int len;
//열계산함수
void matrix_col()
{
	int i;
	int now_row, next_row, temp_row;

	for (i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		now_row = 0;
		while (1) {
			if (now_row == N - 1) {
				ans++;
				break;
			}
			next_row = now_row + 1;

			//현재 칸과 오른쪽 칸의 높이가 같은 경우
			if (MAP[next_row][i] == MAP[now_row][i]) {
				now_row = next_row;
				continue;
			}
			else if (abs(MAP[next_row][i] - MAP[now_row][i]) == 1) { // 현재 칸과 오른쪽 칸의 높이 차이가 1인 경우
				len = 0;
				if (MAP[now_row][i] > MAP[next_row][i]) { // 현재 칸이 다음 칸보다 높은 경우 현재칸 다음칸부터 경사로를 놓는다
					temp_row = next_row;
					while (len != L) {
						if (MAP[temp_row][i] == MAP[next_row][i]) { // 다음 칸에 놓는 경우는 경사로가 겹치는지 체크할 필요없음
							visit[temp_row] = 1;
							temp_row++;
							len++;
						}
						else
							break;
					}

					if (len == L)
						next_row = temp_row - 1;
				}
				else { //현재 칸이 다음 칸보다 낮은 경우 현재칸부터 이전 칸으로 경사로를 놓는다

					temp_row = now_row;
					while (len != L) {
						if (MAP[temp_row][i] == MAP[now_row][i] && visit[temp_row] != 1) { // 이전 칸에 놓는 경우는 경사로가 겹치는지 체크
							visit[temp_row] = 1;
							temp_row--;
							len++;
						}
						else
							break;
					}
				}
			}
			else // 높이도 다르고 칸의 차이가 1도 아닌 경우
				break;
			if (len == L)
				now_row = next_row;
			else
				break;
		}
	}
}

//행 계산 함수
//row는 i로 항상 같고 col을 증가시키면서 계산
void matrix_row()
{
	int i;
	int now_col, next_col, temp_col;

	for (i = 0; i < N; i++) {
		memset(visit, 0, sizeof(visit));
		now_col = 0;
		while (1) {
			if (now_col == N - 1) {
				ans++;
				break;
			}
			next_col = now_col + 1;

			//현재 칸과 오른쪽 칸의 높이가 같은 경우
			if (MAP[i][next_col] == MAP[i][now_col]) {
				now_col = next_col;
				continue;
			}
			else if (abs(MAP[i][next_col] - MAP[i][now_col]) == 1) { // 현재 칸과 오른쪽 칸의 높이 차이가 1인 경우
				len = 0;
				if (MAP[i][now_col] > MAP[i][next_col]) { // 현재 칸이 다음 칸보다 높은 경우 현재칸 다음칸부터 경사로를 놓는다
					temp_col = next_col;
					while (len != L) {
						if (MAP[i][temp_col] == MAP[i][next_col]) { // 다음 칸에 놓는 경우는 경사로가 겹치는지 체크할 필요없음
							visit[temp_col] = 1;
							temp_col++;
							len++;
						}
						else
							break;
					}

					if (len == L)
						next_col = temp_col - 1;
				}
				else { //현재 칸이 다음 칸보다 낮은 경우 현재칸부터 이전 칸으로 경사로를 놓는다
					temp_col = now_col;
					while (len != L) {
						if (MAP[i][temp_col] == MAP[i][now_col] && visit[temp_col] != 1) { // 이전 칸에 놓는 경우는 경사로가 겹치는지 체크
							visit[temp_col] = 1;
							temp_col--;
							len++;
						}
						else
							break;
					}
				}
			}
			else // 높이도 다르고 칸의 차이가 1도 아닌 경우
				break;
			if (len == L)
				now_col = next_col;
			else
				break;
		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &L);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &MAP[i][j]);

	matrix_row();
	matrix_col();
	printf("%d\n", ans);
}