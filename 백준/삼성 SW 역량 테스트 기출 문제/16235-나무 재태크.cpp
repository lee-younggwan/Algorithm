#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dr[] = { -1,-1,-1,0,1,1,1,0 };
int dc[] = { -1,0,1,1,1,0,-1,-1 };
vector <int> TREE[11][11];
vector <pair <pair <int, int>, int> > die;
int ENERGY[11][11];
int A[11][11]; // �� ĭ�� �߰��Ǵ� ����� ��
int N, M, K;
void print() {
	printf("------------------------------------\n");
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (TREE[i][j].empty())
				printf("( 0 )");
			else {
				printf("( ");
				for (int k = 0; k < TREE[i][j].size(); k++) {
					printf("%d ", TREE[i][j][k]);
				}
				printf(")");
			}
		}
		printf("\n");
	}
}
bool comp(const int &a, const int &b) {
	return a < b;
}
void spring() {
	int i, j, k;
	for (i = 1; i <= N; i++) {
		for (j = 1; j <= N; j++) {
			// i,j ��ġ�� ������ �ɾ��� �ִٸ� 
			if (!TREE[i][j].empty()) {
				//���̰� � ��������
				sort(TREE[i][j].begin(), TREE[i][j].end(), comp);
				for (k = 0; k < TREE[i][j].size(); k++) {
					//�ڽ��� ���̸�ŭ ����� �԰� ���̰� 1�����Ѵ�
					if (ENERGY[i][j] >= TREE[i][j][k]) {
						ENERGY[i][j] -= TREE[i][j][k];
						TREE[i][j][k]++;
					}
					else
						break;
				}//���� ������ �������
				for (int t = k; t < TREE[i][j].size(); t++) {
					ENERGY[i][j] += TREE[i][j][t] / 2;
				}
				//���� ������ �����(k���� ������, ���ĵǾ�������)
				TREE[i][j].erase(TREE[i][j].begin() + k, TREE[i][j].end());
			}
		}
	}
}
void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!TREE[i][j].empty()) {
				//�����ϴ� ������ ���̰� 5�� ���
				for (int k = 0; k < TREE[i][j].size(); k++) {
					if (TREE[i][j][k] % 5 == 0) {
						int now_row = i;
						int now_col = j;
						//������ 8���� ĭ�� ���̰� 1�� ������ �����
						for (int t = 0; t < 8; t++) {
							int next_row = now_row + dr[t];
							int next_col = now_col + dc[t];
							if (next_row >= 1 && next_row <= N && next_col >= 1 && next_col <= N) {
								TREE[next_row][next_col].push_back(1);
							}
						}
					}
				}
			}
		}
	}
}
void winter() {
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++)
			ENERGY[i][j] += A[i][j];
}
int main() {

	scanf("%d %d %d", &N, &M, &K);
	for (int i = 1; i <= N; i++)
		for (int j = 1; j <= N; j++) {
			scanf("%d", &A[i][j]);
			ENERGY[i][j] = 5;
		}

	for (int i = 0; i < M; i++) {
		int x, y, z;
		scanf("%d %d %d", &x, &y, &z);
		TREE[x][y].push_back(z);
	}

	for (int i = 0; i < K; i++) {
		spring(); //���� ����
		fall();
		winter();
		//print();

	}

	int answer = 0;
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			answer += TREE[i][j].size();
		}
	}

	printf("%d\n", answer);
	return 0;
}