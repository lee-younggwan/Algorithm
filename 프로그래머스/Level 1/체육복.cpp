#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(int n, vector<int> lost, vector<int> reserve) {
	int answer = 0;
	
	vector <int> temp;
	int visit[31] = { 0, };
	for (int i = 0; i < lost.size(); i++) {
		for (int j = 0; j < reserve.size(); j++) {
			if (lost[i] == reserve[j]) {
				reserve.erase(reserve.begin() + j);
				temp.push_back(lost[i]);
				break;
			}
		}
	}

	for (int i = 0; i < temp.size(); i++) {
		for (int j = 0; j < lost.size(); j++) {
			if (temp[i] == lost[j]) {
				lost.erase(lost.begin() + j);
				break;
			}
		}
	}
	for (int i = 0; i < lost.size(); i++)
		visit[lost[i]] = 1;

	//여분을 들고있는 학생
	for (int i = 0; i < reserve.size(); i++) {
		if (reserve[i] == 1) {
			if (visit[2] == 1)
				visit[2] = 0;
		}
		else if (reserve[i] == 30) {
			if (visit[29] == 1)
				visit[29] = 0;
		}
		else {
			if (visit[reserve[i] - 1] == 1)
				visit[reserve[i] - 1] = 0;
			else if (visit[reserve[i] + 1] == 1)
				visit[reserve[i] + 1] = 0;
		}
	}
	for (int i = 1; i <= n; i++)
		if (visit[i] == 0)
			answer++;

	return answer;
}

int main() {
	solution(5, { 2,4 }, { 1,3,5 });
}