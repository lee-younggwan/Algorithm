#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
using namespace std;

#define MAX 3000001

vector <int> graph[MAX];
int visit[MAX];
int A, P;

int main()
{
	int i = 0;
	int num;
	int sum = 0;
	scanf("%d %d", &A, &P);

	graph[0].push_back(A);
	graph[A].push_back(0);
	visit[A] = 1;
	num = A;
	i = 1;
	while (1)
	{
		sum = 0;
		while (num)
		{
			sum += (int)pow((num % 10), P);
			num /= 10;
		}
		if (visit[sum] == 1) { // 이미 방문했다면
			printf("%d\n", graph[sum].front());
			break;
		}
		//방문하지 않았다면
		visit[sum] = 1;
		graph[i].push_back(sum);
		graph[sum].push_back(i);
		num = sum;
		i++;
	}

	return 0;
}