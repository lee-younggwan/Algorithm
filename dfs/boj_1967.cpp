#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { -1, 0, 1, 0 };
int dc[] = { 0, 1, 0, -1 };

vector <pair <int, int>> vec[100001];
int visit[100001];
int N;
int ans = -1;
int node;
void dfs(int idx, int dist)
{
	visit[idx] = 1;
	if (ans < dist) {
		ans = dist;
		node = idx;
	}
	for (int i = 0; i < vec[idx].size(); i++) {
		if (!visit[vec[idx][i].first]) {
			dfs(vec[idx][i].first, dist + vec[idx][i].second);
		}
	}
}
int main()
{
	int i, temp;
	int u, v;
	scanf("%d", &N);

	for (i = 1; i < N; i++) {
		scanf("%d %d %d", &temp, &u, &v);

		vec[temp].push_back(make_pair(u, v));
		vec[u].push_back(make_pair(temp, v));
	}

	dfs(1, 0);
	memset(visit, 0, sizeof(visit));
	ans = 0;
	dfs(node, 0);
	printf("%d\n", ans);
	return 0;
}