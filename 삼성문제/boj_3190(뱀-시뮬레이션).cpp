#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0, 1, 0 ,-1 }; // 동 남 서 북 방향
int dc[] = { 1, 0, -1, 0 };

queue <pair <int, int> >que;

int N, K, L;
int MAP[101][101];
int visit[101][101];
int sec[101];
char command[101];
int dir;
int time;
int phase;
int main()
{
	int i;
	int x, y;

	scanf("%d", &N);
	scanf("%d", &K);
	for (i = 0; i < K; i++) {
		scanf("%d %d", &x, &y);
		MAP[x-1][y-1] = 1; //사과의 위치, 문제에서는 1행 1열부터 시작이므로
	}

	scanf("%d", &L);
	for (i = 0; i < L; i++)
		scanf("%d %c", &sec[i], &command[i]);

	//처음방향, 시간, 단계(방향전환) 초기화
	dir = 0; 
	time = 0;
	phase = 0;

	que.push(make_pair(0, 0));
	int now_row = 0;
	int now_col = 0;
	visit[0][0] = 1;

	while (!que.empty()) {

		time++;
		int next_row = now_row + dr[dir];
		int next_col = now_col + dc[dir];

		//벽 or 자기자신과 부딪힌 경우
		if (next_row < 0 || next_row >= N || next_col < 0 || next_col >= N || visit[next_row][next_col] == 1) {
			printf("%d\n", time);
			break;
		}
		que.push(make_pair(next_row, next_col));
		visit[next_row][next_col] = 1;

		//사과가 있는 경우
		if (MAP[next_row][next_col]) {
			MAP[next_row][next_col] = 0; //사과를 먹는다
		}
		else { //사과가 없는 경우 que에서 pop을 하고 visit을 0으로 바꾼다
			int tail_row = que.front().first;
			int tail_col = que.front().second;
			que.pop();

			visit[tail_row][tail_col] = 0;
		}

		//time이 방향을 변환할 시간이 되었을 경우
		if (time == sec[phase]) {
			if (command[phase] == 'L')  //왼쪽 90도 회전이라면
				dir = (dir + 3) % 4;
			else
				dir = (dir + 5) % 4;
			phase++;
		}
		now_row = next_row;
		now_col = next_col;
	}
}