#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <stack>
#include <algorithm>
#include <string.h>
using namespace std;
int T, N;

int visit[10];
int comp_row, comp_col;
int home_row, home_col;
vector <pair <int, int> > vec;
int ans = 987654321;
void dfs(int now_row, int now_col, int n, int dist) {
	if (n == N) {
		dist = dist + abs(now_row - home_row) + abs(now_col - home_col);
		ans = min(ans, dist);
		return;
	}

	for (int i = 0; i < N; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			dist = dist + abs(now_row - vec[i].first) + abs(now_col - vec[i].second);
			dfs(vec[i].first, vec[i].second, n + 1, dist);
			dist = dist - (abs(now_row - vec[i].first) + abs(now_col - vec[i].second));
			visit[i] = 0;
		}
	}
}
int main() {
	int i, j, r, c;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d", &N);
		scanf("%d %d %d %d", &comp_row, &comp_col, &home_row, &home_col);

		ans = 987654321;
		vec.clear();
		memset(visit, 0, sizeof(visit));
		for (i = 0; i < N; i++) {
			scanf("%d %d", &r, &c);
			vec.push_back(make_pair(r, c));
		}
		dfs(comp_row,comp_col,0,0);

		printf("#%d %d\n", test_case, ans);
	}	
}