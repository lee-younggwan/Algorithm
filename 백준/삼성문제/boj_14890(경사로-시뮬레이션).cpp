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
//������Լ�
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

			//���� ĭ�� ������ ĭ�� ���̰� ���� ���
			if (MAP[next_row][i] == MAP[now_row][i]) {
				now_row = next_row;
				continue;
			}
			else if (abs(MAP[next_row][i] - MAP[now_row][i]) == 1) { // ���� ĭ�� ������ ĭ�� ���� ���̰� 1�� ���
				len = 0;
				if (MAP[now_row][i] > MAP[next_row][i]) { // ���� ĭ�� ���� ĭ���� ���� ��� ����ĭ ����ĭ���� ���θ� ���´�
					temp_row = next_row;
					while (len != L) {
						if (MAP[temp_row][i] == MAP[next_row][i]) { // ���� ĭ�� ���� ���� ���ΰ� ��ġ���� üũ�� �ʿ����
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
				else { //���� ĭ�� ���� ĭ���� ���� ��� ����ĭ���� ���� ĭ���� ���θ� ���´�

					temp_row = now_row;
					while (len != L) {
						if (MAP[temp_row][i] == MAP[now_row][i] && visit[temp_row] != 1) { // ���� ĭ�� ���� ���� ���ΰ� ��ġ���� üũ
							visit[temp_row] = 1;
							temp_row--;
							len++;
						}
						else
							break;
					}
				}
			}
			else // ���̵� �ٸ��� ĭ�� ���̰� 1�� �ƴ� ���
				break;
			if (len == L)
				now_row = next_row;
			else
				break;
		}
	}
}

//�� ��� �Լ�
//row�� i�� �׻� ���� col�� ������Ű�鼭 ���
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

			//���� ĭ�� ������ ĭ�� ���̰� ���� ���
			if (MAP[i][next_col] == MAP[i][now_col]) {
				now_col = next_col;
				continue;
			}
			else if (abs(MAP[i][next_col] - MAP[i][now_col]) == 1) { // ���� ĭ�� ������ ĭ�� ���� ���̰� 1�� ���
				len = 0;
				if (MAP[i][now_col] > MAP[i][next_col]) { // ���� ĭ�� ���� ĭ���� ���� ��� ����ĭ ����ĭ���� ���θ� ���´�
					temp_col = next_col;
					while (len != L) {
						if (MAP[i][temp_col] == MAP[i][next_col]) { // ���� ĭ�� ���� ���� ���ΰ� ��ġ���� üũ�� �ʿ����
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
				else { //���� ĭ�� ���� ĭ���� ���� ��� ����ĭ���� ���� ĭ���� ���θ� ���´�
					temp_col = now_col;
					while (len != L) {
						if (MAP[i][temp_col] == MAP[i][now_col] && visit[temp_col] != 1) { // ���� ĭ�� ���� ���� ���ΰ� ��ġ���� üũ
							visit[temp_col] = 1;
							temp_col--;
							len++;
						}
						else
							break;
					}
				}
			}
			else // ���̵� �ٸ��� ĭ�� ���̰� 1�� �ƴ� ���
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