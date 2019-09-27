#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;

int dr[] = { -1,0,1,0 }; //상우하좌
int dc[] = { 0,1,0,-1 };

int R, C, T;
int MAP[51][51];
queue <pair <int, int> > que;
vector <pair <int, int> > vec;
int phase = 1;
int answer = 0;
void print() {
	printf("--------%d phase-----------\n", phase++);
	for (int i = 0; i < R; i++) {
		for (int j = 0; j < C; j++) {
			printf("%d ", MAP[i][j]);
		}
		printf("\n");
	}
}
void runCleaner() {
	int i, j;
	vector <int> circle;
	//위쪽 공기청정기의 바람은 반시계방향으로 순환
	//(0,0) 부터 (now_row, C)까지
	//밑변, 오른쪽, 위, 왼 순으로 vector에 집어 넣는다.
	int now_row = vec[0].first;
	for (i = 0; i < C; i++)
		circle.push_back(MAP[now_row][i]);
	for (i = now_row - 1; i >= 1; i--)
		circle.push_back(MAP[i][C - 1]);
	for (i = C - 1; i >= 0; i--)
		circle.push_back(MAP[0][i]);
	for (i = 1; i < now_row ; i++)
		circle.push_back(MAP[i][0]);

	int idx = 0;
	for (i = 0; i < C; i++)
		MAP[now_row][i] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = now_row - 1; i >= 1; i--)
		MAP[i][C - 1] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = C - 1; i >= 0; i--)
		MAP[0][i] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = 1; i < now_row ; i++)
		MAP[i][0] = circle[(circle.size() - 1 + idx++) % circle.size()];

	MAP[now_row][0] = -1;
	MAP[now_row][1] = 0;
	//---------------------------------------------------------------//

	//밑쪽 공기청정기의 바람은 시계방향으로 순환
	//(now_row,0) 부터 (R, C)까지
	//윗, 오른쪽, 아래, 왼 순으로 vector에 집어 넣는다.
	now_row = vec[1].first;
	idx = 0;
	circle.clear();
	for (i = 0; i < C; i++)
		circle.push_back(MAP[now_row][i]);
	for (i = now_row + 1; i <= R - 2; i++)
		circle.push_back(MAP[i][C - 1]);
	for (i = C - 1; i >= 0; i--)
		circle.push_back(MAP[R - 1][i]);
	for (i = R - 2; i > now_row; i--)
		circle.push_back(MAP[i][0]);

	for (i = 0; i < C; i++)
		MAP[now_row][i] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = now_row + 1; i <= R - 2; i++)
		MAP[i][C - 1] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = C - 1; i >= 0; i--)
		MAP[R - 1][i] = circle[(circle.size() - 1 + idx++) % circle.size()];
	for (i = R - 2; i > now_row; i--)
		MAP[i][0] = circle[(circle.size() - 1 + idx++) % circle.size()];

	MAP[now_row][0] = -1;
	MAP[now_row][1] = 0;
	for (i = 0; i < R; i++)
		for (j = 0; j < C; j++)
			if (MAP[i][j] != -1 && MAP[i][j] != 0)
				que.push(make_pair(i, j));
	//print();
}
int main() {
	int i, j;
	scanf("%d %d %d", &R, &C, &T);

	for (i = 0; i < R; i++) {
		for (j = 0; j < C; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == -1)
				vec.push_back(make_pair(i, j)); //공기청정기의 위치
			else if (MAP[i][j] > 0)
				que.push(make_pair(i, j)); //미세먼지가 있는 위치
		}
	}

	int time = 0;
	while (!que.empty()) {
		if (time == T) {
			int sum = 0;
			for (i = 0; i < R; i++) {
				for (j = 0; j < C; j++) {
					if (MAP[i][j] != -1)
						sum = sum + MAP[i][j];
				}
			}
			answer = sum;
			break;
		}
		//미세먼지를 확산시킨다
		//확산은 미세먼지가 있는 칸에서 동시에 일어남
		vector<vector<int>> visit(51, vector<int>(51, 0));
		int size = que.size();
		while (size > 0) {

			int now_row = que.front().first;
			int now_col = que.front().second;
			int spread = MAP[now_row][now_col] / 5; //확산되는 양은 Ar,c/5
			int count = 0;
			que.pop();

			for (i = 0; i < 4; i++) {
				int next_row = now_row + dr[i];
				int next_col = now_col + dc[i];

				//(r, c)에 있는 미세먼지는 인접한 네 방향으로 확산된다.
				//인접한 방향에 공기청정기가 있거나, 칸이 없으면 그 방향으로는 확산이 일어나지 않는다.
				if (next_row >= 0 && next_row < R && next_col >= 0 && next_col < C) {
					if (MAP[next_row][next_col] != -1) {
						visit[next_row][next_col] += spread;
						count++;
					}
				}
			}
			//que.push(make_pair(now_row, now_col));
			//(r, c)에 남은 미세먼지의 양은 Ar,c - (Ar,c/5)×(확산된 방향의 개수)
			MAP[now_row][now_col] = MAP[now_row][now_col] - spread * count;
			size--;
		}

		//미세먼지를 확산
		for (i = 0; i < R; i++) {
			for (j = 0; j < C; j++) {
				MAP[i][j] += visit[i][j];
			}
		}

		//공기청정기를 작동시킨다
		runCleaner();

		time++;
	}

	printf("%d\n", answer);

	return 0;
}