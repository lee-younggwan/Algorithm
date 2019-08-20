#include <string>
#include <vector>
#include <algorithm>
using namespace std;

string solution(int n, int t, int m, vector<string> timetable) {
	string answer = "";
	int i, j;
	vector <int> temp;

	sort(timetable.begin(), timetable.end());
	for (i = 0; i < timetable.size(); i++) {
		if (timetable[i] == "23:59")
			continue;
		temp.push_back(stoi(timetable[i].substr(0, 2)) * 60 + stoi(timetable[i].substr(3, 5)));
	}//temp �迭�� ��(minute)���·� ����

	int start = 540;

	int idx = 0;
	int count = 0;
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = idx; j < temp.size(); j++) {
			if (count == m) //��Ʋ�� �ڸ��� ������
				break;
			if (temp[j] <= start) { //ũ���� ���ð��� ������߽ð����� �۰ų� ������
				count++;
				idx++;
			}
			else // ũ���� ���ð��� ������߽ð����� �ʴ� ��� ����
				break;
		}
		start = start + t;
	}
	
	if (count == m) { //������ ������ ��� ����� ź ���, ������ ���-1���̸� �ȴ�
		int res = temp[idx-1] - 1;
		if (res / 60 < 10)
			answer = "0" + to_string(res / 60) + ":";
		else
			answer = to_string(res / 60) + ":";

		if (res % 60 < 10) {
			answer = answer + "0" + to_string(res % 60);
		}
		else
			answer = answer + to_string(res % 60);
	}
	else { //��� ����� �� ź ��� ������ ������ ��߽ð��� ���߸� �ȴ�
		int res = start - t;
		if (res / 60 < 10)
			answer = "0" + to_string(res / 60) + ":";
		else
			answer = to_string(res / 60) + ":";

		if (res % 60 < 10) {
			answer = answer + "0" + to_string(res % 60);
		}
		else
			answer = answer + to_string(res % 60);
	}
	return answer;
}

int main()
{
	//solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
	solution(2, 10, 2, { "09:10"});
	//solution(1, 1, 5, { "08:00", "08:01", "08:02", "08:03" });
}