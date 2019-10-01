#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, H;
int visit[31][11];
int conn[31][11];
int ans = 987654321;
void print() {
	printf("-----------------------\n");
	for (int i = 1; i <= H; i++) {
		for (int j = 1; j <= N; j++) {
			printf("%d ", visit[i][j]);
		}
		printf("\n");
	}
}
void playGame(int cnt) {
	//세로선마다 사다리를 탄다
	//if (visit[4][1] && visit[4][2])
		//printf("herehererherherehe\n");
	int check = 0;
	//print();
	for (int i = 1; i <= N; i++) {
		int now_ver = i;
		for (int j = 1; j <= H; j++) {
			//가로선이 놓아져 있으면 세로선의 값을 변경
			if (visit[j][now_ver] != 0) {
				//가로선이 오른쪽으려 연결되어 있다면
				if (conn[j][now_ver] == 1)
					now_ver = now_ver + 1;
				//왼쪽으로 연결되어 있다면
				else if (conn[j][now_ver] == -1)
					now_ver = now_ver - 1;
			}
		}
		//다 내려왔을 때 현재 세로선의 위치가 i와 다르다면 실패
		if (now_ver != i) {
			check = 1;
			break;
		}
	}
	if (check == 0) {
		ans = min(ans, cnt);
	}
}
//세로선, 가로선, 깊이를 인자로
void dfs(int ver, int hor, int depth) {
	//추가한 가로선 개수가 3보다 큰 경우
	if (depth > 3)
		return;

	//사다리 게임을 시작
		playGame(depth);

	for (int i = ver; i <= N-1; i++) {
		if (i != ver)
			hor = 1;
		for (int j = hor; j <= H; j++) {
			if (visit[j][i] == 0) {
				//두 가로선이 연속하거나 접하면 안된다
				if (visit[j][i+1] == 0) {
					//i번 세로선과 i+1번 세로선을 j번 점섬위치에서 연결
					visit[j][i] = 2;
					visit[j][i+1] = 2;
					conn[j][i] = 1;
					conn[j][i + 1] = -1;
					//세로선이 바뀐경우...
					if (i != ver)
						dfs(i, 1, depth + 1);
					else
						dfs(i, j, depth + 1);
					conn[j][i + 1] = 0;
					conn[j][i] = 0;
					visit[j][i+1] = 0;
					visit[j][i] = 0;
				}
			}
		}
	}
}
int main() {
	int a, b;
	for (int i = 0; i < 31; i++) {
		for (int j = 0; j < 11; j++) {
			visit[i][j] = 0;
			conn[i][j] = 0;
		}
	}

	scanf("%d %d %d", &N, &M, &H);

	for (int i = 0; i < M; i++) {
		//b번 세로선과 b+1번 세로선을 a번 점선위치에서 연결
		scanf("%d %d", &a, &b);
		visit[a][b] = 1;
		visit[a][b+1] = 1;
		conn[a][b] = 1;
		conn[a][b+1] = -1;
	}

	dfs(1,1,0);

	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);
	return 0;
}