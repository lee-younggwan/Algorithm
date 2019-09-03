#include <string>
#include <vector>
#include <map>
#include <iostream>
using namespace std;

vector<string> solution(vector<string> record) {
	vector<string> answer;
	vector <pair <string, string> > vec;
	map <string, string> m;
	int i,j;

	for (i = 0; i < record.size(); i++) {
		char ELC = record[i][0];
		string id = "";
		string name = "";
		string temp = record[i];

		if (ELC == 'E') {
			int find = temp.find(" ");
			temp = temp.substr(find + 1);

			find = temp.find(" ");
			id = temp.substr(0, find);
			name = temp.substr(find + 1);
			
			if (m.count(id) > 0) 
				m.erase(id);
			m.insert(make_pair(id, name));

			vec.push_back(make_pair(id, "´ÔÀÌ µé¾î¿Ô½À´Ï´Ù."));
		}
		else if (ELC == 'L') {
			int find = temp.find(" ");
			temp = temp.substr(find + 1);

			find = temp.find(" ");
			id = temp.substr(0, find);
	
			vec.push_back(make_pair(id, "´ÔÀÌ ³ª°¬½À´Ï´Ù."));
		}
		else {
			int find = temp.find(" ");
			temp = temp.substr(find + 1);

			find = temp.find(" ");
			id = temp.substr(0, find);
			name = temp.substr(find + 1);

			m.erase(id);
			m.insert(make_pair(id, name));
		}
	}
	for (i = 0; i < vec.size(); i++) {
		string name;
		name = m.find(vec[i].first)->second;
		answer.push_back(name + vec[i].second);
	}
	return answer;
}

int main()
{
	vector<string> answer = solution({ "Enter uid1234 Muzi", "Enter uid4567 Prodo", "Leave uid1234", "Enter uid1234 Prodo", "Change uid4567 Ryan" });
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}