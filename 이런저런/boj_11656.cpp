#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string str;
int main()
{
	int i, len;
	getline(cin, str);
	len = str.length();
	vector <string> vec(len);

	for (i = 0; i < len; i++)
	{
		vec[i] = str;
		str.erase(0, 1);
	}
	sort(vec.begin(), vec.end());
	for (i = 0; i < len; i++)
		cout << vec[i] << "\n";
	return 0;
}