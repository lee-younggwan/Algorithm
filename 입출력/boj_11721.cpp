#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int i;
	string str;

	getline(cin, str);

	for (i = 0; i < str.length(); i++)
	{
		if (i % 10 == 0 && i != 0)
			printf("\n");
		printf("%c", str[i]);
	}

	return 0;
}