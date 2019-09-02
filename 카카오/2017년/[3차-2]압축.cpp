#include <string>
#include <iostream>
#include <vector>

using namespace std;

vector <pair <string, int > > vec[26];
int cnt = 26;
vector<pair<int, int>> findW(string msg)
{
	int i, len;
	int idx = msg[0] - 'A';
	string temp = "";
	temp += msg[0];

	len = 0;
	int val = 0;
	for (i = 0; i < vec[idx].size();) {
		if (vec[idx][i].first == temp) {
			val = i;
			if (len < msg.length()) {
				len++;
				temp += msg[len];
				i = 0;
			}
			else
				break;
		}
		else
			i++;
	}
	vec[idx].push_back(make_pair(temp, ++cnt));
	vector <pair<int, int>> result;
	result.push_back({ len, val });
	return result;
}
vector<int> solution(string msg) {
	vector<int> answer;
	int i;
	for (i = 0; i < 26; i++) {
		char temp = 'A' + i;
		string temp2 = "";
		temp2 += temp;
		vec[i].push_back(make_pair(temp2, i + 1));
	}

	while (msg.length()) {
		//가장 긴 문자열 w를 찾는다
		int idx = msg[0] - 'A';
		vector <pair <int, int> > result = findW(msg);
		int len = result.front().first; 
		int val = result.front().second;
		msg.erase(0,len);
		answer.push_back(vec[idx][val].second);
	}
	

	return answer;
}
int main()
{	
	string temp = "A";

	vector <int> answer = solution("ABABABABABABABAB");
	for (int i = 0; i < answer.size(); i++)
		printf("%d ", answer[i]);
}