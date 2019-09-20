#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> solution(vector<int> array, vector<vector<int>> commands) {
	vector<int> answer;

	for (int i = 0; i < commands.size(); i++) {
		int from = commands[i][0]-1;
		int to = commands[i][1];
		int find = commands[i][2]-1;

		vector<int>temp;
		for (int j = from; j < to; j++)
			temp.push_back(array[j]);
		sort(temp.begin(), temp.end());

		answer.push_back(temp[find]);
	}
	return answer;
}

int main() {
	solution({ 1,5,2,6,3,7,4 }, { {2,5,3},{4,4,1},{1,7,3} });
}