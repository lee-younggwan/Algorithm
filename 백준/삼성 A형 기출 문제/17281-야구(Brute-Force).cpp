#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N;
int order[10];
int hitter[51][10];
int visit[10];
int answer = 0;
int playGame() {
	int i, j;
	int player, out, idx = 0, score = 0;

	//이닝별로 플레이
	for (i = 0; i < N; i++) {
		//3아웃 되기전까지
		int loo[3] = { 0, };
		out = 0;
		while (out != 3) {
			player = order[idx++ % 9];

			//1루타
			if (hitter[i][player] == 1) {
				if (loo[2] == 1) { //3루에 사람이 있다면
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2루에 사람이 있다면
					loo[2] = 1;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1루에 사람이 있다면
					loo[1] = 1;
					loo[0] = 0;
				}
				loo[0] = 1;

			}//2루타
			else if (hitter[i][player] == 2) {
				if (loo[2] == 1) { //3루에 사람이 있다면
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2루에 사람이 있다면
					score++;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1루에 사람이 있다면
					loo[2] = 1;
					loo[0] = 0;
				}
				loo[1] = 1;

			}//3루타
			else if (hitter[i][player] == 3) {
				if (loo[2] == 1) { //3루에 사람이 있다면
					score++;
					loo[2] = 0;
				}
				if (loo[1] == 1) { //2루에 사람이 있다면
					score++;
					loo[1] = 0;
				}
				if (loo[0] == 1) { //1루에 사람이 있다면
					score++;
					loo[0] = 0;
				}
				loo[2] = 1;

			}//홈런
			else if (hitter[i][player] == 4) {
				for (j = 0; j < 3; j++) {
					if (loo[j] == 1) {
						loo[j] = 0;
						score++;
					}
				}
				score++;
			}//아웃
			else
				out++;
		}
	}
	return score;
}
void dfs(int depth) {

	if (depth == 9) {
		answer = max(answer, playGame());
		return;
	}

	//선수의 순서 조합을 만든다
	for (int i = 0; i < 9; i++) {
		if (visit[i] == 0) {
			visit[i] = 1;
			order[i] = depth;
			dfs(depth + 1);
			visit[i] = 0;
		}
	}
}
int main() {
	int i, j;

	scanf("%d", &N);

	for (i = 0; i < N; i++)
		for (j = 0; j < 9; j++)
			scanf("%d", &hitter[i][j]);

	//4번째 타자는 1번 선수
	//4번째는 이미 뽑음
	order[3] = 0;
	visit[3] = 1;
	dfs(1);

	printf("%d\n", answer);
	return 0;
}