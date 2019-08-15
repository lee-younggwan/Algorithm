#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <iostream>
#include <string.h>
#include <algorithm>
#include <string>
#include <cmath>
#include <vector>
#include <queue>
#include <stack>
using namespace std;

char cube[6][3][3] = {
	{
		{'w','w','w'},
		{'w','w','w' },
		{'w','w','w' }
	},
	{
		{ 'o','o','o'},
		{'o','o','o' },
		{'o','o','o' }
	},
	{
		{ 'b', 'b', 'b'},
		{'b', 'b', 'b' },
		{'b', 'b', 'b' }
	},
	{
		{ 'r', 'r', 'r'},
		{ 'r', 'r', 'r' },
		{ 'r', 'r', 'r' }
	},
	{
		{'g','g','g'},
		{'g','g','g'},
		{'g','g','g'}
	},
	{
		{'y','y','y'},
		{'y','y','y'},
		{'y','y','y'}
	}
};

int T, n;
void rotation(char plane, char dir)
{
	int i, j;
	char temp[3];
	if (plane == 'U') { // 노란색(D)을 제외한 부분의 제일 윗 줄이 영향 
		if (dir == '+') { // cube[1...4][0] ->
			temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1]; temp[2] = cube[4][0][2]; // 초록색(L)의 제일 윗 부분 저장하고
			for (i = 4; i > 1; i--) 
				for (j = 0; j < 3; j++)
					cube[i][0][j] = cube[i-1][0][j];
			for (j = 0; j < 3; j++)
				cube[1][0][j] = temp[j];
		}
		else { // cube[1...4][0] <- 
			temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1]; temp[2] = cube[1][0][2]; // 오렌지색(B)의 제일 윗 부분 저장하고
			for (i = 1; i < 4; i++)
				for (j = 0; j < 3; j++)
					cube[i][0][j] = cube[i + 1][0][j];
			for (j = 0; j < 3; j++)
				cube[4][0][j] = temp[j];
		}
	}
	else if (plane == 'D') { // 흰색(U)을 제외한 부분의 제일 밑 줄이 영향
		if (dir == '-') { // cube[1...4][2] ->
			temp[0] = cube[4][2][0]; temp[1] = cube[4][2][1]; temp[2] = cube[4][2][2]; // 초록색(L)의 제일 밑 부분 저장하고
			for (i = 4; i > 1; i--)
				for (j = 0; j < 3; j++)
					cube[i][2][j] = cube[i - 1][2][j];
			for (j = 0; j < 3; j++)
				cube[1][2][j] = temp[j];
		}
		else { // cube[1...4][2] <- 
			temp[0] = cube[1][2][2]; temp[1] = cube[1][2][1]; temp[2] = cube[1][2][2]; // 오렌지색(B)의 제일 밑 부분 저장하고
			for (i = 1; i < 4; i++)
				for (j = 0; j < 3; j++)
					cube[i][2][j] = cube[i + 1][2][j];
			for (j = 0; j < 3; j++)
				cube[4][2][j] = temp[j];
		}
	}
	else if (plane == 'F') { // 오렌지색(B)을 제외하고 초는 오른쪽 파는 왼쪽 흰은 밑, 노는 윗줄이 영향
		if (dir == '+') {
			temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2]; // 흰색의 밑줄을 저장
			cube[0][2][0] = cube[4][2][2]; cube[0][2][1] = cube[4][1][2]; cube[0][2][2] = cube[4][0][2]; //흰면 밑줄에 초록면 오른쪽줄 저장
			cube[4][0][2] = cube[5][0][0]; cube[4][1][2] = cube[5][0][1]; cube[4][2][2] = cube[5][0][2]; //초록면 오른쪽줄에 노란면 윗줄 저장
			cube[5][0][0] = cube[2][2][0]; cube[5][0][1] = cube[2][1][0]; cube[5][0][2] = cube[2][0][0]; //노란면 윗줄에 파란면 왼쪽줄 저장
			cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2]; //파란면 왼쪽줄에 흰면 밑줄 저장
		}
		else {
			temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2]; // 흰색의 밑줄을 저장
			cube[0][2][0] = cube[2][0][0]; cube[0][2][1] = cube[2][1][0]; cube[0][2][2] = cube[2][2][0]; //흰면 밑줄에 파란면 왼줄 저장
			cube[2][0][0] = cube[5][0][2]; cube[2][1][0] = cube[5][0][1]; cube[2][2][0] = cube[5][0][0]; //파란면 왼쪽줄에 노란면 윗줄 저장
			cube[5][0][0] = cube[4][0][2]; cube[5][0][1] = cube[4][1][2]; cube[5][0][2] = cube[4][2][2]; //노란면 윗줄에 초록면 오른줄 저장
			cube[4][0][2] = temp[2]; cube[4][1][2] = temp[1]; cube[4][2][2] = temp[0]; //초록면 오른쪽줄에 흰면 밑줄 저장
		}
	}
	else if (plane == 'B') {
		if (dir == '-') {
			temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2]; // 흰색의 윗줄을 저장
			cube[0][0][0] = cube[4][2][0]; cube[0][0][1] = cube[4][1][0]; cube[0][0][2] = cube[4][0][0]; //흰면 윗줄에 초록면 왼쪽줄 저장
			cube[4][0][0] = cube[5][2][0]; cube[4][1][0] = cube[5][2][1]; cube[4][2][0] = cube[5][2][2]; //초록면 왼쪽줄에 노란면 밑줄 저장
			cube[5][2][0] = cube[2][2][2]; cube[5][2][1] = cube[2][1][2]; cube[5][2][2] = cube[2][0][2]; //노란면 밑줄에 파란면 오른줄 저장
			cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2]; //파란면 오른줄에 흰면 윗줄 저장
		}
		else {
			temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2]; // 흰색의 윗줄을 저장
			cube[0][0][0] = cube[2][0][2]; cube[0][0][1] = cube[2][1][2]; cube[0][0][2] = cube[2][2][2]; //흰면 윗줄에 파란면 오른줄 저장
			cube[2][0][2] = cube[5][2][2]; cube[2][1][2] = cube[5][2][1]; cube[2][2][2] = cube[5][2][0]; //파란면 오른줄에 노란면 밑줄 저장
			cube[5][0][0] = cube[4][2][0]; cube[5][0][1] = cube[4][1][2]; cube[5][0][2] = cube[4][0][2]; //노란면 밑줄에 초록면 왼줄 저장
			cube[4][0][2] = temp[2]; cube[4][1][2] = temp[1]; cube[4][2][2] = temp[0]; //초록면 왼줄에 흰면 윗줄 저장
		}
	}
	else if (plane == 'L') {

	}
	else if (plane == 'R') {

	}
}
void print()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++)
			printf("%c", cube[0][i][j]);
		printf("\n");
	}
}
int main()
{
	int i, j, test_case;
	char plane, dir;
	string str;
	scanf("%d", &T);

	for (test_case = 0; test_case < T; test_case++) {
		scanf("%d", &n);
		for (i = 0; i < n; i++) {
			cin >> str;
			rotation(str[0], str[1]);
			print();
		}
	}
}
