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
	getline(cin, str); //�ʱ⹮��
	cursor = str.length(); //�ʱ� Ŀ���� ��ġ
	len = str.length();

	scanf("%d", &n);

	for (i = 0; i < n; i++)
	{
		cin >> cmd;

		if (cmd == 'L')
		{
			if (cursor != 0) // ������ �Ǿ��� �ƴ϶��
				cursor--;
		}
		else if (cmd == 'D')
		{
			if (cursor != len) // ������ �ǵڰ� �ƴ϶��
				cursor++;
		}
		else if (cmd == 'B')
		{
			if (cursor != 0) //������ �Ǿ��� �ƴ϶��
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