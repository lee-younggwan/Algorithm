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

int dr[] = { -1, -1, -1, 0, 1, 1, 1, 0 }; //���ʺ��� ���������� 8��
int dc[] = { -1, 0, 1, 1, 1, 0, -1, -1 };
int A[11][11]; //���
int MAP[11][11] = { 5, };
int N, M, K;
vector  <pair<int, int>> vec[101]; // y, ����
bool compare(const  pair<int, int> &a, const  pair<int, int> &b) 
{
	return a.second < b.second;
}
bool compare2(const  pair<int, int> &a, const  pair<int, int> &b)
{
	return a.second > b.second;
}
void spring()
{
	int i, j;
	int row, col, age, food;
	for (i = 0; i < N; i++) {
		if (vec[i].size() > 1) { // ���� ���� ������ 2�� �̻� �ɾ��� �ִٸ� � �������� ����� �Դ´�
			sort(vec[i].begin(), vec[i].end(), compare);
			for (j = 0; j < vec[i].size(); j++) {
				row = i; col = vec[i][j].first; age = vec[i][j].second; food = 0;
				while (food != age) { // MAP[row][col]�� ����� �ִٸ� age�� �ɶ����� �Դ´�
					if (MAP[row][col]) {
						food = food++;
						MAP[row][col]--;
					}
					else { // ����� ������ �״´�...
						break;
					}
				}
				if (food != age) { //����� ��� �׾��ٸ� �װͺ��� ���̰� ���� �����鵵 �״´�
					//vec[i].erase(vec[i].begin + j, vec[i].end());
					vec[i][j].second = age * -1;
				}
				else
					vec[i][j].second = age + 1;
			}
		}
		else if(vec[i].size() == 1){
			row = i; col = vec[i][0].first; age = vec[i][0].second; food = 0;
			while (food != age) { // MAP[row][col]�� ����� �ִٸ� age�� �ɶ����� �Դ´�
				if (MAP[row][col]) {
					food = food++;
					MAP[row][col]--;
				}
				else  // ����� ������ �״´�...
					break;
			}
			if (food != age)  //����� ��� �׾��ٸ� �װͺ��� ���̰� ���� �����鵵 �״´�
				vec[i][0].second = age * -1;
			//vec[i].pop_back();
			else
				vec[i][0].second = age + 1;
		}

	}
}
void summer()
{
	int i, j;
	int row, col, age, food;
	for (i = 0; i < N; i++) {
		if (vec[i].size() > 1) {
			for (j = 0; j < vec[i].size(); j++) {
				row = i; col = vec[i][j].first; age = vec[i][j].second; food = 0;
				if (age < 0) { //���� �������	
					MAP[row][col] += (age*-1) / 2;
				}
			}
			sort(vec[i].begin(), vec[i].end(), compare2);
			for (j = 0; j < vec[i].size(); j++)
				if (vec[i][j].second < 0) {
					vec[i].erase(vec[i].begin() + j, vec[i].end());
					break;
				}
		}
		else if(vec[i].size() == 1){
			row = i; col = vec[i][0].first; age = vec[i][0].second; food = 0;
			if (age < 0) { //���� �������
				MAP[row][col] += (age*-1) / 2;
				vec[i].pop_back();
			}
		}
	}
}
void fall()
{
	int i, j;
	int row, col, age, food;
	for (i = 0; i < N; i++) {
		int temp = vec[i].size();
		for (j = 0; j < temp; j++) {
			row = i; col = vec[i][j].first; age = vec[i][j].second; food = 0;
			if (age % 5 == 0) {
				for (int k = 0; k < 8; k++) {
					int next_row = row + dr[k];
					int next_col = col + dc[k];
					if (next_row >= 0 && next_row < N && next_col >= 0 && next_col < N) 
						vec[next_row].push_back(make_pair(next_col, 1));
				}
			}
		}
	}
}
void winter()
{
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			MAP[i][j] += A[i][j];
}
void print() {
	int i, j;
	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			printf("%d ", MAP[i][j]);
		printf("\n");
	}
	printf("\n");
	for (i = 0; i < N; i++) {
		for (j = 0; j < vec[i].size(); j++)
			printf("<%d %d %d> ", i, vec[i][j].first, vec[i][j].second);
		printf("\n");
	}
	printf("-----------------\n");
}
int main()
{
	int i, j;
	int x, y, z;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			scanf("%d", &A[i][j]); // ���
	for (i = 0; i < M; i++) {
		scanf("%d %d %d", &x, &y, &z);
		vec[x - 1].push_back(make_pair(y - 1, z)); // ��ġ�� ����
	}

	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			MAP[i][j] = 5;
	for (int year = 0; year < K; year++) {
		spring();
		summer();
		fall();
		winter();
		print();
	}

	int sum = 0;
	for (i = 0; i < N; i++)
		sum = sum + vec[i].size();
	printf("%d\n", sum);
}
