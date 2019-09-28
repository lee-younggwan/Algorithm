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
int A[11][11]; // 각 칸에 추가되는 양분의 양
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
			// i,j 위치에 나무가 심어져 있다면 
			if (!TREE[i][j].empty()) {
				//나이가 어린 나무부터
				sort(TREE[i][j].begin(), TREE[i][j].end(), comp);
				for (k = 0; k < TREE[i][j].size(); k++) {
					//자신의 나이만큼 양분을 먹고 나이가 1증가한다
					if (ENERGY[i][j] >= TREE[i][j][k]) {
						ENERGY[i][j] -= TREE[i][j][k];
						TREE[i][j][k]++;
					}
					else
						break;
				}//죽은 나무를 양분으로
				for (int t = k; t < TREE[i][j].size(); t++) {
					ENERGY[i][j] += TREE[i][j][t] / 2;
				}
				//죽은 나무는 지운다(k부터 끝까지, 정렬되어있으니)
				TREE[i][j].erase(TREE[i][j].begin() + k, TREE[i][j].end());
			}
		}
	}
}
void fall() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			if (!TREE[i][j].empty()) {
				//번식하는 나무는 나이가 5의 배수
				for (int k = 0; k < TREE[i][j].size(); k++) {
					if (TREE[i][j][k] % 5 == 0) {
						int now_row = i;
						int now_col = j;
						//인접한 8개의 칸에 나이가 1인 나무가 생긴다
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
		spring(); //봄과 여름
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