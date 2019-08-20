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
	}//temp 배열에 분(minute)형태로 저장

	int start = 540;

	int idx = 0;
	int count = 0;
	for (i = 0; i < n; i++) {
		count = 0;
		for (j = idx; j < temp.size(); j++) {
			if (count == m) //셔틀에 자리가 다차면
				break;
			if (temp[j] <= start) { //크루의 대기시간이 버스출발시간보다 작거나 같으면
				count++;
				idx++;
			}
			else // 크루의 대기시간이 버스출발시간보다 늦는 경우 종료
				break;
		}
		start = start + t;
	}
	
	if (count == m) { //마지막 버스에 모든 사람이 탄 경우, 마지막 사람-1분이면 된다
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
	else { //모든 사람이 안 탄 경우 버스의 마지막 출발시간에 맞추면 된다
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