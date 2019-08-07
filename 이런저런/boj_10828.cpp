#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <algorithm>

using namespace std;
stack <int> st;
vector <pair<string, int>> com;
int N;
int main()
{
	int i;
	scanf("%d", &N);
	com.resize(N);

	for (i = 0; i < N; i++)
	{
		cin >> com[i].first;
		if (com[i].first.compare("push") == 0)
		{
			cin >> com[i].second;
			st.push(com[i].second);
		}
		else if (com[i].first.compare("pop") == 0)
		{
			if (st.empty())
				printf("-1\n");
			else {
				printf("%d\n", st.top());
				st.pop();
			}
		}
		else if (com[i].first.compare("size") == 0)
		{
			printf("%d\n", st.size());
		}
		else if (com[i].first.compare("empty") == 0)
		{
			if (st.empty())
				printf("1\n");
			else
				printf("0\n");
		}
		else if (com[i].first.compare("top") == 0)
		{
			if (st.empty())
				printf("-1\n");
			else
				printf("%d\n", st.top());
		}
	}

	return 0;
}