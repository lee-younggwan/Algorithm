#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <string.h>
using namespace std;

int T, N, M;

int main() {
	int a, b;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &M);
		
		
		int visit[501] = { 0, };
		vector <int> vec[501];
		visit[1] = 1;
		for (int i = 0; i < M; i++) {
			scanf("%d %d", &a, &b);
			vec[a].push_back(b);
			vec[b].push_back(a);
			if (a == 1)
				visit[b] = 1;
		}
		int ans = vec[1].size();
		for (int i = 0; i < vec[1].size(); i++) {
			for (int j = 0; j < vec[vec[1][i]].size(); j++) {
				if (!visit[vec[vec[1][i]][j]]) {
					ans++;
					visit[vec[vec[1][i]][j]] = 1;
				}
			}

		}

		printf("#%d %d\n", test_case, ans);
	}
	return 0;
}