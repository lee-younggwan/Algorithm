#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <queue>
#include <iostream>
#include <algorithm>
#include <string>
#include <set>
using namespace std;

int T, N, K;
int main() {
	int i, j;

	scanf("%d", &T);
	for (int test_case = 1; test_case <= T; test_case++) {
		scanf("%d %d", &N, &K);
		set <string, greater<string>> s;
		string temp = "";
		cin >> temp;

		int rotate = N / 4;
		for (i = 0; i < N; i = i + rotate)
			s.insert(temp.substr(i, rotate));

		for (i = 1; i < rotate; i++) { // N-1번의 회전을 하면서 생기는 모든 조합
			char last = temp[temp.length() - 1]; // 마지막 문자 저장
			for (j = temp.length() - 1; j >= 1; j--) {
				temp[j] = temp[j - 1];
			}
			temp[0] = last;
			for (j = 0; j < N; j = j + rotate)
				s.insert(temp.substr(j, rotate));
		}
		set<string>::iterator iter;
		int count = 0;
		string result = "";
		for (iter = s.begin(); iter != s.end(); ++iter) {
			//cout << *iter << " ";
			if (count == K - 1)
				result = *iter;
			count++;
		}
		
		int ans = 0;
		int len = result.length() - 1;
		for (i = 0; i < result.length(); i++) {
			if(result[i] >= '0' && result[i] <= '9')
				ans = ans + (result[i] - '0')*pow(16, len--);
			else if(result[i] >= 'A' && result[i] <= 'F')
				ans = ans + (result[i] - 55)*pow(16, len--);
		}

		//ans = (int)strtol(result.c_str(), NULL, 16);
		printf("#%d %d\n", test_case, ans);
	
	}
	return 0;
}