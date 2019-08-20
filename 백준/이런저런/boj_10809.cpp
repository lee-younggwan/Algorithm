#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

int arr[26];
string str;
int main()
{
	int i;
	getline(cin, str);
	for (i = 0; i < 26; i++)
		arr[i] = -1;

	for (i = 0; i < str.length(); i++)
	{
		if(arr[str[i] - 'a'] == -1)
			arr[str[i] - 'a'] = i;
	}
	for (i = 0; i < 26; i++)
		printf("%d ", arr[i]);
	
	return 0;
}