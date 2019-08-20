#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int main()
{
	int M, D;
	int i;
	int day = 0;
	char temp[7][5] = { "SUN","MON", "TUE", "WED", "THU" ,"FRI", "SAT" };

	scanf("%d %d", &M, &D);

	for (i = 1; i < M; i++)
	{
		switch (i)
		{
		case 1: day = day + 31;
			break;
		case 2: day = day + 28;
			break;
		case 3: day = day + 31;
			break;
		case 4: day = day + 30;
			break;
		case 5: day = day + 31;
			break;
		case 6: day = day + 30;
			break;
		case 7: day = day + 31;
			break;
		case 8: day = day + 31;
			break;
		case 9: day = day + 30;
			break;
		case 10: day = day + 31;
			break;
		case 11: day = day + 30;
			break;
		case 12: day = day + 31;
			break;
		}
	}
	day = day + D;
	printf("%s\n", temp[day % 7]);

	return 0;
}