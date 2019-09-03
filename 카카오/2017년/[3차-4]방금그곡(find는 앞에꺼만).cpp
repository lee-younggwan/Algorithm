#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector < pair <pair <pair <int, int>, string>, string > > vec; //시작시간,종료시간,제목,코드

bool comp(const pair <int, string> &a, const pair <int, string> &b)
{
	return a.first > b.first;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int i, j;
	vector <pair <int, string > > result;

	//음악정보를 "," 기준으로 TIME, TITLE, CODE를 split
	for (i = 0; i < musicinfos.size(); i++) {
		//time 정보는 HH:MM 이므로
		int start = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
		int end = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));

		string temp = musicinfos[i].substr(12);
		int find = temp.find(",");

		string title = temp.substr(0, find);
		string code = temp.substr(find + 1);

		vec.push_back(make_pair(make_pair(make_pair(start, end), title), code));
	}

	//split된 음악정보를 이용하여 멜로디 m을 찾음
	for (i = 0; i < vec.size(); i++) {
		int start = vec[i].first.first.first;
		int end = vec[i].first.first.second;
		int time = end - start;
		string title = vec[i].first.second;
		string code = vec[i].second;
		string melody = "";

		//라디오에서 재생된 음표
		int cnt = 0;
		j = 0;
		while (cnt < time) {
			melody += code[j% code.length()];
			if (code[j% code.length() + 1] == '#') {
				melody += "#";
				j++;
			}
			cnt++;
			j++;
		}
		while (1) {
			if (melody.find(m) != string::npos) {
				int find = melody.find(m);

				if (m[m.length() - 1] == 'E' || m[m.length() - 1] == 'B') //m의 마지막 멜로디에 #이 안붙는 경우
					result.push_back(make_pair(time, title));
				else if (m[m.length() - 1] == '#') { //m의 마지막 멜로디가 #인경우
					result.push_back(make_pair(time, title));
				}
				else { // m의 마지막 음이 C,D,F,G,A,인 경우 melody가 #을 포함하는지 확인 
					if (melody[find + m.length()] != '#')
						result.push_back(make_pair(time, title));
				}
				melody = melody.substr(find + m.length());
			}
			else
				break;
		}
	}

	if (result.size() == 0)
		answer = "(None)";
	else if (result.size() > 1) {
		stable_sort(result.begin(), result.end(), comp);
		answer = result[0].second;
	}
	else
		answer = result[0].second;

	cout << answer;

	return answer;
}
int main()
{
	solution("BC", { "12:00,12:05,HELLO,ABC#", "12:00,12:07,WORLD,BC#BC" });
}