#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int N;
vector <pair<int, int>> v;
int main()
{
	int i;
	scanf("%d", &N);

	v.resize(N);
	for (i = 0; i < N; i++)
		scanf("%d %d", &v[i].second, &v[i].first);

	sort(v.begin(), v.end());

	for (i = 0; i < N; i++)
		printf("%d %d\n", v[i].second, v[i].first);
	return 0;
}