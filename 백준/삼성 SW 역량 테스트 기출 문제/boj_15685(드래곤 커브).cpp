#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

int dr[] = { 0, -1, 0, 1 };
int dc[] = { 1, 0, -1, 0 };
int N;
int visit[102][102];

int main()
{
	int i, j, k;
	int x, y, d, g;
	scanf("%d", &N);
	for (i = 0; i < N; i++) {
		scanf("%d %d %d %d", &x, &y, &d, &g);

		vector <int> dragon;
		dragon.push_back(d);

		for (j = 0; j < g; j++) {
			vector <int> temp = dragon;
			for (k = dragon.size() - 1; k >= 0; k--)
				dragon.push_back((temp[k] + 1) % 4);
		}

		visit[y][x] = 1;
		for (j = 0; j < dragon.size(); j++) {
			y = y + dr[dragon[j]];
			x = x + dc[dragon[j]];

			if (x >= 0 && x < 101 && y >= 0 && y < 101)
				visit[y][x] = 1;
		}
	}
	int ans = 0;
	for (i = 0; i <= 100; i++)
		for (j = 0; j <= 100; j++)
			if (visit[i][j])
				if (visit[i][j + 1] == 1 && visit[i + 1][j] == 1 && visit[i + 1][j + 1] == 1)
					ans++;

	printf("%d\n", ans);
}