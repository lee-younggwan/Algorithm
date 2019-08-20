#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <math.h>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dr[] = { 0, -1, 1, 0, 0 }; // 상 하 좌 우
int dc[] = { 0, 0, 0, -1, 1 };

vector <pair <int, int> > people;
vector <pair <int, int> > stair;
vector < int> stair_1;
vector <int > stair_2;
int MAP[11][11];
int T, N;
int p_num;
int ans = 9999;
int count_stair1()
{
	if (stair_1.empty())
		return 0;
	//1번 계단을 계산
	int used[3] = { 0, };
	int time = 0;
	int idx = 0;
	int down = MAP[stair[0].first][stair[0].second]; // 내려가는데 걸리는 시간

	vector <int > temp = stair_1;
	sort(temp.begin(), temp.end()); // 도착한 순서대로 정렬
	time = temp[0];

	while (1) {
		for (int i = 0; i < 3; i++) {
			if (used[i] == 0 && temp[idx] <= time) {
				used[i] = down;
				idx++;
				if (idx == temp.size() - 1) {
					return time + down;
				}
			}
			else {
				used[i]--;
			}
		}
		time++;
	}

}
int count_stair2()
{
	if (stair_2.empty())
		return 0;
	//1번 계단을 계산
	int used[3] = { 0, };
	int time = 0;
	int idx = 0;
	int down = MAP[stair[1].first][stair[1].second]; // 내려가는데 걸리는 시간

	vector <int > temp = stair_2;
	sort(temp.begin(), temp.end()); // 도착한 순서대로 정렬
	time = temp[0];

	while (1) {
		for (int i = 0; i < 3; i++) {
			if (used[i] == 0 && temp[idx] <= time) {
				used[i] = down;
				idx++;
				if (idx == temp.size() - 1) {
					return time + down;
				}
			}
			else {
				used[i]--;
			}
		}
		time++;
	}

}
void dfs(int idx, int num) 
{

	if (idx >= people.size()) {

		ans = min(ans, max(count_stair1(), count_stair2()));
		return;
	}
	if (num == 1) {
		int dist = abs(people[idx].first - stair[0].first) + abs(people[idx].second - stair[0].second);
		stair_1.push_back(dist);
	}
	else if (num == 2) {
		int dist = abs(people[idx].first - stair[0].first) + abs(people[idx].second - stair[0].second);
		stair_2.push_back(dist);
	}
	//1번 계단으로 가는 경우와 2번 계단으로 가는 경우 2가지가 있음
	dfs(idx + 1, 1);
	stair_1.pop_back();

	dfs(idx + 1, 2);
	stair_2.pop_back();

}
int main()
{
	int i, j;
	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		
		scanf("%d", &N);
		for(i=0;i<N;i++)
			for (j = 0; j < N; j++) {
				scanf("%d", &MAP[i][j]);
				if (MAP[i][j] == 1) // 사람인 경우
					people.push_back(make_pair(i, j));
				if (MAP[i][j] > 1) // 계단인 경우, 항상 2개 있음
					stair.push_back(make_pair(i, j));
			}
		dfs(0, 1);
		dfs(0, 2);
		printf("%d\n", ans);

	}
}