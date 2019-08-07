#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

vector <int> graph[1001];
queue <int> que;

int visit[1001]; 
int N, M, V; // 정점, 간선, 탐색을 시작할 정점의 번호

void dfs(int idx)
{
	int i;
	visit[idx] = 1;
	printf("%d ", idx);

	for (i = 0; i < graph[idx].size(); i++)
	{
		if (!visit[graph[idx][i]])
			dfs(graph[idx][i]);
	}
}
void bfs(int idx)
{
	que.push(idx);
	visit[idx] = 1;
	while (!que.empty())
	{
		int now = que.front();
		que.pop();
		printf("%d ", now);

		for (int i = 0; i < graph[now].size(); i++)
		{
			if (!visit[graph[now][i]])
			{
				que.push(graph[now][i]);
				visit[graph[now][i]] = 1;
			}
		}
	}
}
int main()
{
	int i;
	int u, v;
	scanf("%d %d %d", &N, &M, &V);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		graph[u].push_back(v);
		graph[v].push_back(u);
	}

	for (i = 1; i <= N; i++)
		sort(graph[i].begin(), graph[i].end());

	dfs(V); 
	printf("\n");
	memset(visit, 0, sizeof(visit));
	bfs(V);

	return 0;
}