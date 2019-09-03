#include <string>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector <pair <pair <string, int>, string> > vec; //HEAD(STR), NUMBER(INT), FILE(STR)

bool comp(const pair <pair <string, int>, string> &a, const pair <pair <string, int>, string> &b)
{
	if (a.first.first == b.first.first)  //head가 같으면 number 순
		return a.first.second < b.first.second;
	return a.first.first < b.first.first;

}
vector<string> solution(vector<string> files) {
	vector<string> answer;
	int i, j, k;
	int num;
	for (i = 0; i < files.size(); i++) {
		for (j = 0; j < files[i].length(); j++) {
			if (isdigit(files[i][j])) { // 숫자라면
				string head;
				string number;
				head = files[i].substr(0, j);
				for (k = 0; k < head.length(); k++)
					head[k] = tolower(head[k]);

				for (k = j; k < j + 5; k++) { //최대 5개의 숫자까지
					if (!isdigit(files[i][k]))  //중간에 문자가 나온다면
						break;
					number.push_back(files[i][k]);
				}

				for (k = 0; k < number.length(); k++) {
					if (number[k] >= '1') {
						num = stoi(number.substr(k, number.length()- k));
						break;
					}
				}
				if (k == number.length())
					num = 0;

				vec.push_back(make_pair(make_pair(head, num), files[i]));
				break;
			}
		}
	}

	stable_sort(vec.begin(), vec.end(), comp);

	for (i = 0; i < vec.size(); i++)
		answer.push_back(vec[i].second);
	return answer;
}

int main()
{
	vector<string> answer = solution({ "img12.png", "img10.png", "img02.png", "img1.png", "IMG01.GIF", "img2.JPG" });
	for (int i = 0; i < answer.size(); i++)
		cout << answer[i] << endl;
}