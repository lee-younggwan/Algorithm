#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	string temp;
	while (getline(cin, temp))
	{
		cout << temp << endl;
	}
	return 0;
}