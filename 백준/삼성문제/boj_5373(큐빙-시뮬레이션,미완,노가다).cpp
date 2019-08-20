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
	if (plane == 'U') { // �����(D)�� ������ �κ��� ���� �� ���� ���� 
		if (dir == '+') { // cube[1...4][0] ->
			temp[0] = cube[4][0][0]; temp[1] = cube[4][0][1]; temp[2] = cube[4][0][2]; // �ʷϻ�(L)�� ���� �� �κ� �����ϰ�
			for (i = 4; i > 1; i--) 
				for (j = 0; j < 3; j++)
					cube[i][0][j] = cube[i-1][0][j];
			for (j = 0; j < 3; j++)
				cube[1][0][j] = temp[j];
		}
		else { // cube[1...4][0] <- 
			temp[0] = cube[1][0][0]; temp[1] = cube[1][0][1]; temp[2] = cube[1][0][2]; // ��������(B)�� ���� �� �κ� �����ϰ�
			for (i = 1; i < 4; i++)
				for (j = 0; j < 3; j++)
					cube[i][0][j] = cube[i + 1][0][j];
			for (j = 0; j < 3; j++)
				cube[4][0][j] = temp[j];
		}
	}
	else if (plane == 'D') { // ���(U)�� ������ �κ��� ���� �� ���� ����
		if (dir == '-') { // cube[1...4][2] ->
			temp[0] = cube[4][2][0]; temp[1] = cube[4][2][1]; temp[2] = cube[4][2][2]; // �ʷϻ�(L)�� ���� �� �κ� �����ϰ�
			for (i = 4; i > 1; i--)
				for (j = 0; j < 3; j++)
					cube[i][2][j] = cube[i - 1][2][j];
			for (j = 0; j < 3; j++)
				cube[1][2][j] = temp[j];
		}
		else { // cube[1...4][2] <- 
			temp[0] = cube[1][2][2]; temp[1] = cube[1][2][1]; temp[2] = cube[1][2][2]; // ��������(B)�� ���� �� �κ� �����ϰ�
			for (i = 1; i < 4; i++)
				for (j = 0; j < 3; j++)
					cube[i][2][j] = cube[i + 1][2][j];
			for (j = 0; j < 3; j++)
				cube[4][2][j] = temp[j];
		}
	}
	else if (plane == 'F') { // ��������(B)�� �����ϰ� �ʴ� ������ �Ĵ� ���� ���� ��, ��� ������ ����
		if (dir == '+') {
			temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2]; // ����� ������ ����
			cube[0][2][0] = cube[4][2][2]; cube[0][2][1] = cube[4][1][2]; cube[0][2][2] = cube[4][0][2]; //��� ���ٿ� �ʷϸ� �������� ����
			cube[4][0][2] = cube[5][0][0]; cube[4][1][2] = cube[5][0][1]; cube[4][2][2] = cube[5][0][2]; //�ʷϸ� �������ٿ� ����� ���� ����
			cube[5][0][0] = cube[2][2][0]; cube[5][0][1] = cube[2][1][0]; cube[5][0][2] = cube[2][0][0]; //����� ���ٿ� �Ķ��� ������ ����
			cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2]; //�Ķ��� �����ٿ� ��� ���� ����
		}
		else {
			temp[0] = cube[0][2][0]; temp[1] = cube[0][2][1]; temp[2] = cube[0][2][2]; // ����� ������ ����
			cube[0][2][0] = cube[2][0][0]; cube[0][2][1] = cube[2][1][0]; cube[0][2][2] = cube[2][2][0]; //��� ���ٿ� �Ķ��� ���� ����
			cube[2][0][0] = cube[5][0][2]; cube[2][1][0] = cube[5][0][1]; cube[2][2][0] = cube[5][0][0]; //�Ķ��� �����ٿ� ����� ���� ����
			cube[5][0][0] = cube[4][0][2]; cube[5][0][1] = cube[4][1][2]; cube[5][0][2] = cube[4][2][2]; //����� ���ٿ� �ʷϸ� ������ ����
			cube[4][0][2] = temp[2]; cube[4][1][2] = temp[1]; cube[4][2][2] = temp[0]; //�ʷϸ� �������ٿ� ��� ���� ����
		}
	}
	else if (plane == 'B') {
		if (dir == '-') {
			temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2]; // ����� ������ ����
			cube[0][0][0] = cube[4][2][0]; cube[0][0][1] = cube[4][1][0]; cube[0][0][2] = cube[4][0][0]; //��� ���ٿ� �ʷϸ� ������ ����
			cube[4][0][0] = cube[5][2][0]; cube[4][1][0] = cube[5][2][1]; cube[4][2][0] = cube[5][2][2]; //�ʷϸ� �����ٿ� ����� ���� ����
			cube[5][2][0] = cube[2][2][2]; cube[5][2][1] = cube[2][1][2]; cube[5][2][2] = cube[2][0][2]; //����� ���ٿ� �Ķ��� ������ ����
			cube[2][0][0] = temp[0]; cube[2][1][0] = temp[1]; cube[2][2][0] = temp[2]; //�Ķ��� �����ٿ� ��� ���� ����
		}
		else {
			temp[0] = cube[0][0][0]; temp[1] = cube[0][0][1]; temp[2] = cube[0][0][2]; // ����� ������ ����
			cube[0][0][0] = cube[2][0][2]; cube[0][0][1] = cube[2][1][2]; cube[0][0][2] = cube[2][2][2]; //��� ���ٿ� �Ķ��� ������ ����
			cube[2][0][2] = cube[5][2][2]; cube[2][1][2] = cube[5][2][1]; cube[2][2][2] = cube[5][2][0]; //�Ķ��� �����ٿ� ����� ���� ����
			cube[5][0][0] = cube[4][2][0]; cube[5][0][1] = cube[4][1][2]; cube[5][0][2] = cube[4][0][2]; //����� ���ٿ� �ʷϸ� ���� ����
			cube[4][0][2] = temp[2]; cube[4][1][2] = temp[1]; cube[4][2][2] = temp[0]; //�ʷϸ� ���ٿ� ��� ���� ����
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
