#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N;
int popul[11];
int visit[11];
int answer = 987654321;
vector<int> vec[11];

bool checkCond(vector <int> sect1, vector <int> sect2) {
	//선거구에 구역이 하나도 없다면
	if (sect1.size() == 0 || sect2.size() == 0)
		return false;

	//선거구에 있는 구역들이 연결되어 있는지 확인
	//BFS로 확인
	for (int i = 0; i < sect1.size() - 1; i++) {
		queue <int> que;
		que.push(sect1[i]);
		int find = sect1[i + 1];
		int check = 0;
		int flag[11] = { 0, };
		flag[sect1[i]] = 1;
		while (!que.empty()) {
			int now_area = que.front();
			que.pop();

			if (now_area == find) {
				check = 1;
				break;
			}

			for (int j = 0; j < vec[now_area].size(); j++) {
				if (visit[vec[now_area][j]] == 1)
					if (flag[vec[now_area][j]] != 1) {
						flag[vec[now_area][j]] = 1;
						que.push(vec[now_area][j]);
					}
			}
		}
		if (check == 0)
			return false;
	}

	for (int i = 0; i < sect2.size() - 1; i++) {
		queue <int> que;
		que.push(sect2[i]);
		int find = sect2[i + 1];
		int check = 0;
		int flag[11] = { 0, };
		flag[sect2[i]] = 1;
		while (!que.empty()) {
			int now_area = que.front();
			que.pop();

			if (now_area == find) {
				check = 1;
				break;
			}

			for (int j = 0; j < vec[now_area].size(); j++) {
				if (visit[vec[now_area][j]] != 1)
					if (flag[vec[now_area][j]] != 1) {
						flag[vec[now_area][j]] = 1;
						que.push(vec[now_area][j]);
					}
			}
		}
		if (check == 0)
			return false;
	}

	return true;
}
void divSector() {
	vector <int> sect1, sect2;
	for (int i = 1; i <= N; i++) {
		if (visit[i])
			sect1.push_back(i);
		else
			sect2.push_back(i);
	}

	if (checkCond(sect1, sect2)) {
		int sum = 0;
		for (int i = 0; i < sect1.size(); i++) {
			sum = sum + popul[sect1[i]];
		}
		for (int i = 0; i < sect2.size(); i++) {
			sum = sum - popul[sect2[i]];
		}
		answer = min(answer, abs(sum));
	}
}
void dfs(int idx, int depth) {
	if (depth == N)
		return;

	divSector();

	for (int i = idx; i <= N; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			dfs(i, depth + 1);
			visit[i] = 0;
		}
	}
}
int main() {

	int i, j, temp;
	scanf("%d", &N);

	//1번 구역부터 N번구역 까지의 인구
	for (i = 1; i <= N; i++)
		scanf("%d", &popul[i]);

	//1번 구역부터 N번구역 까지 각 구역과 인접한 구역의 정보
	for (i = 1; i <= N; i++) {
		int M;
		scanf("%d", &M);
		for (j = 0; j < M; j++) {
			scanf("%d", &temp);
			vec[i].push_back(temp);
		}
	}

	dfs(1, 0);

	if (answer != 987654321)
		printf("%d\n", answer);
	else
		printf("-1\n");

	return 0;
}