#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <algorithm>
#include <vector>
#include <queue>
#include <string>
using namespace std;

int N;
string expr;
int visit[20];
long long int answer = -987654321;

void print() {
	for (int i = 0; i < N; ) {
		if (visit[i]) {
			printf("( %c %c %c )", expr[i], expr[i + 1], expr[i + 2]);
			i = i + 3;
		}
		else {
			printf("%c ", expr[i]);
			i++;
		}
	}
	printf("= ");
}
void calCulate() {
	
	vector <int> num;
	vector <char> oper;
	for (int i = 0; i < N;) {
		//괄호 안에 있다면
		if (visit[i]) {
			int total = 0;
			int a = expr[i] - '0';
			int b = expr[i + 2] - '0';

			if (expr[i + 1] == '+')
				total = a + b;
			else if (expr[i + 1] == '-')
				total = a - b;
			else if (expr[i + 1] == '*')
				total = a * b;

			num.push_back(total);
			i = i + 3;
		}
		else {
			if (expr[i] >= '0' && expr[i] <= '9')
				num.push_back(expr[i] - '0');
			else
				oper.push_back(expr[i]);
			i++;
		}
	}

	long long int sum = num[0];
	for (int i = 0; i < oper.size(); i++) {
		if (oper[i] == '+')
			sum = sum + num[i + 1];
		else if (oper[i] == '-')
			sum = sum - num[i + 1];
		else
			sum = sum * num[i + 1];
	}
	//print();
	//printf("%lld\n", sum);
	//printf("-------------------------\n");
	answer = max(answer, sum);
}
void dfs(int idx, int depth) {
	
	calCulate();

	//i = 1부터 i= N-1까지 i=i+2
	//ex) A+B라고 할때 A가 괄호에 들어가 있지 않다면 A+B 괄호 쌍을 만들 수 있다
	for (int i = idx; i < N-1; i=i+2) {
		if (visit[i - 1] != 1) {
			visit[i - 1] = 1;
			visit[i] = 1;
			visit[i + 1] = 1;

			dfs(i, depth + 1);

			visit[i + 1] = 0;
			visit[i] = 0;
			visit[i - 1] = 0;
		}
	}
}
int main() {
	scanf("%d", &N);
	cin >> expr;

	dfs(1, 0);

	printf("%lld\n", answer);
}