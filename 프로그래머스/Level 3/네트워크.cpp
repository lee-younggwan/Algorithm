#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>

using namespace std;

int visit[201] = { 0, };

void dfs(int c, int N, vector<vector<int>> vec) {
	visit[c] = 1;

	for (int i = 0; i < N; i++) {
		if (!visit[i]) {
			if(vec[c][i])
				dfs(i, N, vec);
		}
	}
}
int solution(int n, vector<vector<int>> computers) {
	int answer = 0;

	for (int i = 0; i < n; i++) {
		if (!visit[i]) {
			answer++;
			dfs(i, n, computers);
		}
	}

	return answer;
}