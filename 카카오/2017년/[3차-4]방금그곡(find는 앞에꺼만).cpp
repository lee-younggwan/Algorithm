#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

vector < pair <pair <pair <int, int>, string>, string > > vec; //���۽ð�,����ð�,����,�ڵ�

bool comp(const pair <int, string> &a, const pair <int, string> &b)
{
	return a.first > b.first;
}
string solution(string m, vector<string> musicinfos) {
	string answer = "";
	int i, j;
	vector <pair <int, string > > result;

	//���������� "," �������� TIME, TITLE, CODE�� split
	for (i = 0; i < musicinfos.size(); i++) {
		//time ������ HH:MM �̹Ƿ�
		int start = stoi(musicinfos[i].substr(0, 2)) * 60 + stoi(musicinfos[i].substr(3, 2));
		int end = stoi(musicinfos[i].substr(6, 2)) * 60 + stoi(musicinfos[i].substr(9, 2));

		string temp = musicinfos[i].substr(12);
		int find = temp.find(",");

		string title = temp.substr(0, find);
		string code = temp.substr(find + 1);

		vec.push_back(make_pair(make_pair(make_pair(start, end), title), code));
	}

	//split�� ���������� �̿��Ͽ� ��ε� m�� ã��
	for (i = 0; i < vec.size(); i++) {
		int start = vec[i].first.first.first;
		int end = vec[i].first.first.second;
		int time = end - start;
		string title = vec[i].first.second;
		string code = vec[i].second;
		string melody = "";

		//�������� ����� ��ǥ
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

				if (m[m.length() - 1] == 'E' || m[m.length() - 1] == 'B') //m�� ������ ��ε� #�� �Ⱥٴ� ���
					result.push_back(make_pair(time, title));
				else if (m[m.length() - 1] == '#') { //m�� ������ ��ε� #�ΰ��
					result.push_back(make_pair(time, title));
				}
				else { // m�� ������ ���� C,D,F,G,A,�� ��� melody�� #�� �����ϴ��� Ȯ�� 
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