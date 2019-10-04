#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <vector>
#include <algorithm>
#include <string>
#include <iostream>
using namespace std;

int N, M;
char MAP[11][11];
char COPY[11][11];
vector <int> dir;
int ans = 987654321;
int red_row, red_col, blue_row, blue_col;
int tr_row, tr_col, tb_row, tb_col;
int moveUp() {

	//파란색공의 행의 위치가 빨간색 공의 행의 위치보다 위에 있다면 파란공을 먼저 굴린다
	if (tb_row <= tr_row) {
		//파란공을 위로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//빨간공을 위로 굴린다
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 종료한다(빨간구슬만 구멍에 빠졌기 때문)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//벽이거나 파란구슬이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//빨간색공의 행의 위치가 파란공보다 위에 있다면 빨간 공을 먼저 굴린다
	else {
		//빨간공을 위로 굴린다
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 파랑색 구슬을 굴린후 파란구슬이 구멍에 빠지지 않는다면 종료한다
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//파란공을 위로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row - 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이거나 빨간 공이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}
int moveDown() {
	//파란색공의 행의 위치가 빨간색 공의 행의 위치보다 아래에 있다면 파란공을 먼저 굴린다
	if (tb_row >= tr_row) {
		//파란공을 아래로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//빨간공을 아래로 굴린다
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 종료한다(빨간구슬만 구멍에 빠졌기 때문)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//벽이거나 파란구슬이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//빨간색공의 행의 위치가 파란공보다 아래에 있다면 빨간 공을 먼저 굴린다
	else {
		//빨간공을 아래로 굴린다
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 파랑색 구슬을 굴린후 파란구슬이 구멍에 빠지지 않는다면 종료한다
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//파란공을 아래로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row + 1;
			int next_col = now_col;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이거나 빨간 공이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}

int moveLeft() {
	//파란색공의 열의 위치가 빨간색 공의 열의 위치보다 왼쪽에 있다면 파란공을 먼저 굴린다
	if (tb_col <= tr_col) {
		//파란공을 왼쪽으로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col-1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//빨간공을 왼쪽으로 굴린다
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col-1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 종료한다(빨간구슬만 구멍에 빠졌기 때문)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//벽이거나 파란구슬이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//빨간색공의 열의 위치가 파란공보다 왼쪽에 있다면 빨간 공을 먼저 굴린다
	else {
		//빨간공을 왼쪽으로 굴린다
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col - 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 파랑색 구슬을 굴린후 파란구슬이 구멍에 빠지지 않는다면 종료한다
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//파란공을 왼쪽으로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col - 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이거나 빨간 공이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}

int moveRight() {
	//파란색공의 열의 위치가 빨간색 공의 열의 위치보다 오른쪽에 있다면 파란공을 먼저 굴린다
	if (tb_col >= tr_col) {
		//파란공을 왼쪽으로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//빨간공을 오른쪽으로 굴린다
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 종료한다(빨간구슬만 구멍에 빠졌기 때문)
			else if (COPY[next_row][next_col] == 'O')
				return 1;
			//벽이거나 파란구슬이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'B')
				break;
		}

	}
	//빨간색공의 행의 위치가 파란공보다 오른쪽에 있다면 빨간 공을 먼저 굴린다
	else {
		//빨간공을 오른쪽으로 굴린다
		int flag = 0;
		while (1) {
			int now_row = tr_row;
			int now_col = tr_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'R';
				COPY[now_row][now_col] = '.';
				tr_row = next_row;
				tr_col = next_col;
			}//구멍이라면 파랑색 구슬을 굴린후 파란구슬이 구멍에 빠지지 않는다면 종료한다
			else if (COPY[next_row][next_col] == 'O') {
				COPY[now_row][now_col] = '.';
				flag = 1;
				break;
			}
			//벽이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#')
				break;
		}

		//파란공을 오른쪽으로 굴린다
		while (1) {
			int now_row = tb_row;
			int now_col = tb_col;

			int next_row = now_row;
			int next_col = now_col + 1;

			//빈 칸이라면 공을 옮기고 원래공이 있던 위치는 비운다
			if (COPY[next_row][next_col] == '.') {
				COPY[next_row][next_col] = 'B';
				COPY[now_row][now_col] = '.';
				tb_row = next_row;
				tb_col = next_col;
			}//구멍이라면 종료한다(파란구슬이 구멍에 빠졌기 때문
			else if (COPY[next_row][next_col] == 'O')
				return -1;
			//벽이거나 빨간 공이라면 그 자리에서 종료한다
			else if (COPY[next_row][next_col] == '#' || COPY[next_row][next_col] == 'R')
				break;
		}
		if (flag)
			return 1;
	}

	return 0;
}
void playGame(int cnt) {
	int i, j;
	
	//구슬들의 처음 위치 초기화
	tr_row = red_row, tr_col = red_col;
	tb_row = blue_row, tb_col = blue_col;

	for (i = 0; i < dir.size(); i++) {
		//위로 기울인다.
		if (dir[i] == 0) {
			int res = moveUp();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}
		//아래로 기울인다
		else if (dir[i] == 1) {
			int res = moveDown();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}//왼쪽으로 기울인다
		else if (dir[i] == 2) {
			int res = moveLeft();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}//오른쪽으로 기울인다
		else if (dir[i] == 3) {
			int res = moveRight();
			if (res == -1)
				return;
			else if (res == 1) {
				ans = min(ans, i+1);
				break;
			}
		}
	}
}
void dfs(int depth) {
	if (depth == 10) {
		for (int i = 0; i < N; i++)
			for (int j = 0; j < M; j++)
				COPY[i][j] = MAP[i][j];
		playGame(depth);
		return;
	}
	for (int i = 0; i < 4; i++) {
		if (dir.empty()) {
			dir.push_back(i);
			dfs(depth + 1);
			dir.pop_back();
		}
		else {
			//기울였던 방향으로 또 기울이는 경우거나
			//기울였던 방향의 반대 방향으로 기울이는 경우는 의미가 없는 경우
			if (dir.back() == i)
				continue;
			if (i == 0 && dir.back() == 1)
				continue;
			if (i == 1 && dir.back() == 0)
				continue;
			if (i == 2 && dir.back() == 3)
				continue;
			if (i == 3 && dir.back() == 2)
				continue;

			dir.push_back(i);
			dfs(depth + 1);
			dir.pop_back();
		}
	}
}
int main() {
	scanf("%d %d", &N, &M);

	for (int i = 0; i < N; i++) {
		string temp;
		cin >> temp;
		for (int j = 0; j < M; j++) {
			MAP[i][j] = temp[j];
			if (MAP[i][j] == 'R') {
				red_row = i;
				red_col = j;
			}
			if (MAP[i][j] == 'B') {
				blue_row = i;
				blue_col = j;
			}
		}
	}
	
	//중복순열을 만든다
	dfs(0);

	if (ans == 987654321)
		printf("-1\n");
	else
		printf("%d\n", ans);

	return 0;
}