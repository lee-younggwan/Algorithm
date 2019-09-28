#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>
using namespace std;

int N;
int ans1 = -1000000001;
int ans2 = 1000000001;
vector <int> num;
int expr[4] = { 0, };

void calCulate(vector <int> comb) {
	int sum = num[0];
	for (int i = 0; i < N-1; i++) {
		if(comb[i] == 0){//µ¡¼À
			sum = sum + num[i + 1];
		}//»¬¼À
		else if (comb[i] == 1) {
			sum = sum - num[i + 1];
		}//°ö¼À
		else if (comb[i] == 2) {
			sum = sum * num[i + 1];
		}//³ª´°¼À
		else {
			sum = sum / num[i + 1];
		}
	}/*
	printf("-------------\n");
	for (int i = 0; i < N - 1; i++) {
		printf("%d ", num[i]);
		if (comb[i] == 0)
			printf("+ ");
		else if (comb[i] == 1)
			printf("- ");
		else if (comb[i] == 2)
			printf("* ");
		else
			printf("/");
	}
	printf(" %d = %d\n", num[N-1], sum);
	*/
	ans1 = max(sum, ans1);
	ans2 = min(sum, ans2);
}
void dfs(int idx, int depth, vector <int> comb) {
	if (depth == N - 1) {
		calCulate(comb);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (expr[i] > 0) {
			expr[i]--;
			comb.push_back(i);
			dfs(i, depth + 1, comb);
			comb.pop_back();
			expr[i]++;
		}
	}
}
int main() {
	scanf("%d", &N);
	for (int i = 0; i < N; i++) {
		int temp;
		scanf("%d", &temp);
		num.push_back(temp);
	}
	for (int i = 0; i < 4; i++)
		scanf("%d", &expr[i]);

	dfs(0, 0, {});
	printf("%d\n", ans1);
	printf("%d\n", ans2);
	return 0;
}