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

vector <int> vec[100001];
int visit[100001];
int parent[100001];
int N;
void dfs(int idx)
{
	visit[idx] = 1;

	for (int i = 0; i < vec[idx].size(); i++) {
		if (!visit[vec[idx][i]])
			dfs(vec[idx][i]);
		else {
			parent[idx] = vec[idx][i];
		}
	}
}
int main()
{
	int i;
	int u, v;
	scanf("%d", &N);

	for (i = 1; i <= N-1; i++) {
		scanf("%d %d", &u, &v);
		vec[u].push_back(v);
		vec[v].push_back(u);
	}
	dfs(1);
	for (i = 2; i <= N; i++)
		printf("%d\n", parent[i]);
	return 0;
}