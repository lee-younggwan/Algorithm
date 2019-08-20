#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <vector>
#include <queue>
using namespace std;

int N, M;

int visit[1001];
vector <int> vec[1001];
void dfs(int idx)
{
	int i;
	visit[idx] = 1;

	for (i = 0; i < vec[idx].size(); i++)
	{
		if (!visit[vec[idx][i]])
			dfs(vec[idx][i]);
	}
}
int main()
{
	int i;
	int u, v;
	int cnt = 0;
	scanf("%d %d", &N, &M);

	for (i = 0; i < M; i++)
	{
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}

	for (i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			dfs(i);
			cnt++;
		}
	}
	
	printf("%d\n", cnt);

	return 0;
}