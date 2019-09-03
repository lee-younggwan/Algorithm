#include <string>
#include <vector>
#include <algorithm>

using namespace std;
vector <pair <double, int> > fail;

int reach[501];
int clear[501];
bool comp(const pair <double, int> &a, const pair <double, int> &b)
{
	if (a.first == b.first)
		return a.second < b.second;
	return a.first > b.first;
}
vector<int> solution(int N, vector<int> stages) {
	vector<int> answer;
	
	int i, j;
	int user = stages.size();
	for (i = 0; i < user; i++) {
		for (j = 1; j < stages[i]; j++) {
			reach[j]++;
			clear[j]++;
		}
		reach[j]++;
	}
	for (i = 1; i <= N; i++)
		fail.push_back(make_pair(double(reach[i] - clear[i]) / double(reach[i]), i));
	
	stable_sort(fail.begin(), fail.end(),comp);
	for (i = 0; i < N; i++) {
		answer.push_back(fail[i].second);
	}
	return answer;
}

int main() {
	solution(5, { 2, 1, 2, 6, 2, 4, 3, 3 });
}