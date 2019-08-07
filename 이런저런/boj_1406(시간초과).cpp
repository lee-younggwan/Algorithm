#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <queue>
#include <algorithm>

using namespace std;

string str, temp;
int main()
{
	int i, n;
	char cmd;
	int cursor;
	int len;
	getline(cin, str); //초기문자
	cursor = str.length(); //초기 커서의 위치
	len = str.length();

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		cin >> cmd;

		if (cmd == 'L')
		{
			if (cursor != 0) // 문장의 맨앞이 아니라면
				cursor--;
		}
		else if (cmd == 'D')
		{
			if (cursor != len) // 문장의 맨뒤가 아니라면
				cursor++;
		}
		else if (cmd == 'B')
		{
			if (cursor != 0) //문장의 맨앞이 아니라면
			{
				str.erase(cursor-1, 1);
				len--;
				cursor--;
			}
		}
		else if (cmd == 'P')
		{
			cin >> temp;
			str.insert(cursor, temp);
			len++;
			cursor++;
		}

	}
	cout << str;
	return 0;
}