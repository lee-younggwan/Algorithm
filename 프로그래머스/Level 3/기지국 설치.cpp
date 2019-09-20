#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <vector>
using namespace std;

int solution(int n, vector<int> stations, int w)
{
	int answer = 0;
	int pre_min = stations[0] - w;
	int pre_max = stations[0] + w;
	while (pre_min > 1) {
		pre_min = pre_min - 2 * w-1;
		answer++;
	}
	pre_min = 0;

	for (int i = 1; i < stations.size(); i++) {
		int now_min = stations[i] - w;
		int now_max = stations[i] + w;
		while (now_min - pre_max > 1) {
			now_min = now_min - 2 * w-1;
			answer++;
		}
		pre_max = now_max;
		pre_min = now_min;
	}
	
	while (pre_max < n) {
		pre_max = pre_max + 2 * w+1;
		answer++;
	}
	return answer;
}

int main() {
	solution(16, { 9 }, 2);
}