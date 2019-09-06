#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair <pair <string, double>, int > &a, const pair <pair <string, double>, int > &b) {
	if (a.first.second == b.first.second)
		return a.second < b.second;
	return a.first.second > b.first.second;
}
int solution(string word, vector<string> pages) {
	int answer = 0;
	int i, j;
	vector <pair <pair <string, double>, int > > addr; //현재 page의 주소와 점수, 인덱스를 위한 addr
	vector <pair <string, double> > link[20]; //현재 page에서 외부로 나가는 링크의 주소와 현재 page의 링크점수

	int wlen = word.length();
	for (i = 0; i < wlen; i++)
		word[i] = tolower(word[i]);

	for (i = 0; i < pages.size(); i++) {
		string temp = pages[i];
		

		//html tag내의 word와 일치하는 지를 찾음
		int idx1 = temp.find("<html");
		int idx2 = temp.find("</html>");
		//html 태그내의 모든 단어를 소문자로
		for (j = idx1; j < idx2; j++)
			temp[j] = tolower(temp[j]);

		idx1 = temp.find("<meta property=\"og:url\" content=");
		string meta = "<meta property=\"og:url\" content=";
		int len = meta.length();
		idx2 = temp.find("/>", idx1);
		//head tag 내의 url  주소를 저장
		addr.push_back(make_pair(make_pair(temp.substr(idx1 + len+1, idx2 - idx1 - 2-len), 0), i));

		double basicPoint = 0;
		while (1) {
			if (temp.find(word, idx1) != string::npos) { //idx1부터 word를 찾는다
				int find = temp.find(word, idx1);
				//찾은 word의 앞뒤문자가 알파벳이 아닌 경우
				if (!isalpha(temp[find - 1]) && !isalpha(temp[find + wlen])) {
					basicPoint++;
				}
				idx1 = find + wlen;
			}
			else
				break;
		}

		addr[i].first.second = basicPoint;


		double exterLink = 0;
		while (1) {
			if (temp.find("<a href") != string::npos) {
				int find = temp.find("<a href");
				int idx2 = temp.find(">", find);
				string url = temp.substr(find + 9, idx2 - find - 10);
				temp = temp.substr(idx2);
				exterLink++;
				link[i].push_back(make_pair(url, 0));
			}
			else
				break;
		}

		for (j = 0; j < link[i].size(); j++)
			link[i][j].second = basicPoint / exterLink;
	}

	for (i = 0; i < addr.size(); i++) {
		for (j = 0; j < link[i].size(); j++) {
			for (int k = 0; k < addr.size(); k++) {
				if (link[i][j].first == addr[k].first.first) {
					addr[k].first.second += link[i][j].second;
				}
			}
		}
	}

	stable_sort(addr.begin(), addr.end(), comp);

	return addr.front().second;
}
	
int main()
{
	//solution("Muzi", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://careers.kakao.com/interview/list\"/>\n</head>  \n<body>\n<a href=\"https://programmers.co.kr/learn/courses/4673\"></a>#!MuziMuzi!)jayg07con&&\n\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://www.kakaocorp.com\"/>\n</head>  \n<body>\ncon%\tmuzI92apeach&2<a href=\"https://hashcode.co.kr/tos\"></a>\n\n\t^\n</body>\n</html>" });
	solution("blind", { "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://a.com\"/>\n</head>  \n<body>\nBlind Lorem Blind ipsum dolor Blind test sit amet, consectetur adipiscing elit. \n<a href=\"https://b.com\"> Link to b </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://b.com\"/>\n</head>  \n<body>\nSuspendisse potenti. Vivamus venenatis tellus non turpis bibendum, \n<a href=\"https://a.com\"> Link to a </a>\nblind sed congue urna varius. Suspendisse feugiat nisl ligula, quis malesuada felis hendrerit ut.\n<a href=\"https://c.com\"> Link to c </a>\n</body>\n</html>", "<html lang=\"ko\" xml:lang=\"ko\" xmlns=\"http://www.w3.org/1999/xhtml\">\n<head>\n  <meta charset=\"utf-8\">\n  <meta property=\"og:url\" content=\"https://c.com\"/>\n</head>  \n<body>\nUt condimentum urna at felis sodales rutrum. Sed dapibus cursus diam, non interdum nulla tempor nec. Phasellus rutrum enim at orci consectetu blind\n<a href=\"https://a.com\"> Link to a </a>\n</body>\n</html>" });
}