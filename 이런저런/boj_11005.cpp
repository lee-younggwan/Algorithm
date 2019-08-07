#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>
using namespace std;

vector <int> vec;
int main()
{
	int N;
	int B, c;

	scanf("%d %d", &N, &B);

	while (1)
	{
		c = N % B;
		vec.push_back(c);
		N = N / B;
		if (N == 0)
			break;
	}
	for (int i = vec.size() - 1; i >= 0; i--)
	{
		if(vec[i] > 10)
			printf("%c", vec[i]-10+'A');
		else
			printf("%d", vec[i]);
	}
	return 0;
}