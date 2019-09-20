#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int visit[10001] = { 0, };
vector<string> answer;
bool dfs(string from, int depth, vector<vector<string>> tickets, vector <string> path) {
	if (depth == tickets.size()) {
		answer = path;
		return true;
	}
	for (int i = 0; i < tickets.size(); i++) {
		//아직 항공권을 사용 안한 경우
		if (!visit[i] && tickets[i][0] == from) {
			visit[i] = 1;
			vector <string> temp = path;
			temp.push_back(tickets[i][1]);
			if (dfs(tickets[i][1], depth + 1, tickets, temp))
				return true;
			visit[i] = 0;
		}
	}
	return false;
}
vector<string> solution(vector<vector<string>> tickets) {
	sort(tickets.begin(), tickets.end());
	vector<string>temp;
	temp.push_back("ICN");
	dfs("ICN", 0, tickets, temp);

	return answer;
}

int main() {
	solution({ {"ICN", "JFK"}, {"HND", "IAD"}, {"JFK", "HND"} });
}