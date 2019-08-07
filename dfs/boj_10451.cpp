#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[1001];
int visit[1001];
int T, N;

void dfs(int idx)
{
	int i;
	visit[idx] = 1;

	for (i = 0; i < graph[idx].size(); i++) {
		if (!visit[graph[idx][i]]) {
			dfs(graph[idx][i]);
		}
	}

}
int main()
{
	int i;
	int u, v;
	int cnt;
	scanf("%d", &T);

	for (int test_case = 0; test_case < T; test_case++) {
		cnt = 0;
		memset(visit, 0, sizeof(visit));
		for (i = 0; i < 1001; i++)
			graph[i].clear();

		scanf("%d", &N);
		for (i = 1; i <= N; i++) {
			scanf("%d", &v);
			if (i == v){
				visit[i] = 1;
				cnt++;
			}
			else
				graph[i].push_back(v);
		}

		for (i = 1; i <= N; i++) {
			if (!visit[i]) {
				dfs(i);
				cnt++;
			}
		}
		printf("%d\n", cnt);

	}

	return 0;
}