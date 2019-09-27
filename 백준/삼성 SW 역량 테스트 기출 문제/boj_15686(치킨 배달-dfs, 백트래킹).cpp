#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int N, M;
int MAP[51][51];
int check[14];
int dist[101];
int ans = 9999;
vector <pair<int, int>> chicken;
vector <pair<int, int>> home;

void dfs(int idx, int cnt)
{
	int i, j, sum;
	// 선택한 치킨집의 개수가 M이라면 거리를 구한다
	if (cnt == M)
	{
		memset(dist, 9999, sizeof(dist));
		for (i = 0; i < chicken.size(); i++)
			if (check[i])  // i번째 치킨집이 선택되었다면
				for (j = 0; j < home.size(); j++)  // home[j]에서 i번째 치킨집까지
					dist[j] = min(dist[j], abs(home[j].first - chicken[i].first) + abs(home[j].second - chicken[i].second));
		sum = 0;
		for (i = 0; i < home.size(); i++)
			sum = sum + dist[i];

		ans = min(ans, sum);
		return;
	}
	for (i = idx; i < chicken.size(); i++) {
		if (check[i] == 0) {
			check[i] = 1;
			dfs(i, cnt + 1);
			check[i] = 0;
		}
	}
}
int main()
{
	int i, j;
	scanf("%d %d", &N, &M);
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) {
			scanf("%d", &MAP[i][j]);
			if (MAP[i][j] == 2)
				chicken.push_back(make_pair(i, j));
			if (MAP[i][j] == 1)
				home.push_back(make_pair(i, j));
		}
	dfs(0, 0);
	printf("%d\n", ans);
}