#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int score[3];
	char type[3];
	char option[3];;
	int i, j = 0;
	//점수인경우, 영역인 경우, 옵션인 경우
	for (i = 0; i < dartResult.length(); i++) {
		//점수인경우
		if (dartResult[i] - '0' >= 0 && dartResult[i] - '0' < 10) {
			if (dartResult[i + 1] == '0') { //10이라면
				score[j] = 10;
				i++;
			}
			else
				score[j] = dartResult[i] - '0';
		} //영역인 경우
		else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			type[j] = dartResult[i];
			j++;
		}
		else { //옵션인 경우
			option[j - 1] = dartResult[i];
		}
	}
	for (i = 0; i < 3; i++) {
		if (type[i] == 'D')
			score[i] = score[i] * score[i];
		if (type[i] == 'T')
			score[i] = score[i] * score[i] * score[i];

		if (option[i] == '*') { //option이 있을 경우
			if (i == 0)
				score[i] = score[i] * 2;
			else {
				score[i] = score[i] * 2;
				score[i - 1] = score[i - 1] * 2;
			}
		}
		else if (option[i] == '#')
			score[i] = score[i] * -1;
	}
	for (i = 0; i < 3; i++)
		answer += score[i];
	return answer;
}