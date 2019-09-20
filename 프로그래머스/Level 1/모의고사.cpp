#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	if (a == b)
		return a.second < b.second;
	return a.first > b.first;
}
vector<int> solution(vector<int> answers) {
	vector<int> answer;
	string temp = "";
	string a = "12345";
	string b = "21232425";
	string c = "3311224455";
	for (int i = 0; i < answers.size(); i++)
		temp = temp + to_string(answers[i]);

	int len = temp.length();
	while (a.length() < len)
		a = a + a;
	while (b.length() < len)
		b = b + b;
	while (c.length() < len)
		c = c + c;

	int A = 0, B = 0, C = 0;
	for (int i = 0; i < len; i++) {
		if (temp[i] == a[i])
			A++;
		if (temp[i] == b[i])
			B++;
		if (temp[i] == c[i])
			C++;
	}
	
	vector <pair <int, int> > vec;
	vec.push_back(make_pair(A, 1)), vec.push_back(make_pair(B, 2)), vec.push_back(make_pair(C, 3));

	sort(vec.begin(), vec.end(), comp);
	answer.push_back(vec[0].second);
	if (vec[0].first == vec[1].first) {
		answer.push_back(vec[1].second);
		if (vec[1].first == vec[2].first)
			answer.push_back(vec[2].second);
	}
	return answer;
}

int main() {
	solution({ 1, 1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1,1});
}