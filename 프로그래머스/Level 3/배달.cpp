#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

vector <pair <int, int> > vec[51];
int visit[51];
int flag[51];
void dfs(int n, int total, int K) {
	if (total > K)
		return;

	flag[n] = 1;
	for (int i = 0; i < vec[n].size(); i++) {
		int town = vec[n][i].first;
		int dist = vec[n][i].second;

		if (!visit[town]) {
			visit[town] = 1;
			dfs(town, total + dist, K);
			visit[town] = 0;
		}
	}
}
int solution(int N, vector<vector<int> > road, int K) {
	int i, j;
	int answer = 0;
	for (i = 0; i < road.size(); i++) {
		int from = road[i][0];
		int to = road[i][1];
		int dist = road[i][2];

		vec[from].push_back(make_pair(to, dist));
		vec[to].push_back(make_pair(from, dist));
	}
	visit[1] = 1;
	dfs(1, 0, K);
	for (i = 1; i <= N; i++)
		if (flag[i] == 1)
			answer++;
	return answer;
}

int main() {
	solution(6, { {1,2,1},{1,3,2},{2,3,2},{3,4,3},{3,5,2},{3,5,3},{5,6,1} },4);
}