#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int dr[] = { -1,0,1,0 };
int dc[] = { 0,1,0,-1 };

int N, M;
int total = 0;
int answer = 987654321;
vector<vector<int>> MAP(51, vector<int>(51));
vector <pair <int, int> > virus;
int visit[11] = { 0, };

void bfs() {
	int i, j;
	vector<vector<int>> visited(51, vector<int>(51, 0));
	queue <pair <int, int> > que;
	for (i = 0; i < virus.size(); i++) {
		if (visit[i]) {
			que.push(make_pair(virus[i].first, virus[i].second));
			visited[virus[i].first][virus[i].second] = 1;
		}
	}

	int time = 1;
	int cnt = 0;
	while (!que.empty()) {
		int size = que.size();
		while (size > 0) {
			int now_row = que.front().first;
			int now_col = que.front().second;
			que.pop();

			for (i = 0; i < 4; i++) {
				int next_row = now_row + dr[i];
				int next_col = now_col + dc[i];

				//연구소 안에 있고 아직 방문한적이 없고 벽이 아닌 경우
				if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) {
					if (!visited[next_row][next_col]) {
						if (MAP[next_row][next_col] != 1) {
							if (MAP[next_row][next_col] == 0)
								cnt++;
							que.push(make_pair(next_row, next_col));
							visited[next_row][next_col] = time;
						}
					}
				}
			}
			size--;
		}

		/*printf("---------------%d -------------\n", time);
		for (i = 0; i < N; i++) {
			for (j = 0; j < N; j++)
				printf("%d ", visited[i][j]);
			printf("\n");
		}*/
		if (cnt == total)
			break;
		time++;
	}
	if(cnt == total)
		answer = min(answer, time);
}
void dfs(int idx, int depth) {
	if (depth == M) {
		bfs();
		return;
	}

	for (int i = idx; i < virus.size(); i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}
}
int main() {

	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 2)
				virus.push_back(make_pair(i, j));
			else if (MAP[i][j] == 0)
				total++;
		}
	}
	//M개의 활성시킬 바이러스 조합을 만든다.
	dfs(0, 0);

	if (total == 0) {
		printf("0\n");
		return 0;
	}

	if (answer == 987654321)
		printf("-1\n");
	else
		printf("%d\n", answer);
	return 0;
}