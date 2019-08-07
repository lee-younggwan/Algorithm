#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int cnt[4];
string str;
int main()
{
	int i;
	while (!getline(cin, str))
	{
		for (i = 0; i < str.length(); i++)
		{
			if (str[i] - 'a' >= 0 && str[i] - 'a' < 26) // 소문자
				cnt[0]++;
			else if (str[i] - 'a' >= -32 && str[i] - 'a' < -6) //대문자
				cnt[1]++;
			else if (str[i] - 'a' == -65) //공백
				cnt[3]++;
			else
				cnt[2]++;
		}
		for (i = 0; i < 4; i++)
		{
			printf("%d ", cnt[i]);
			cnt[i] = 0;
		}
		printf("\n");
	}
	
	
	
	return 0;
}