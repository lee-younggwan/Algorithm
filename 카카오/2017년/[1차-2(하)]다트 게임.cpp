#include <string>

using namespace std;

int solution(string dartResult) {
	int answer = 0;
	int score[3];
	char type[3];
	char option[3];;
	int i, j = 0;
	//�����ΰ��, ������ ���, �ɼ��� ���
	for (i = 0; i < dartResult.length(); i++) {
		//�����ΰ��
		if (dartResult[i] - '0' >= 0 && dartResult[i] - '0' < 10) {
			if (dartResult[i + 1] == '0') { //10�̶��
				score[j] = 10;
				i++;
			}
			else
				score[j] = dartResult[i] - '0';
		} //������ ���
		else if (dartResult[i] == 'S' || dartResult[i] == 'D' || dartResult[i] == 'T') {
			type[j] = dartResult[i];
			j++;
		}
		else { //�ɼ��� ���
			option[j - 1] = dartResult[i];
		}
	}
	for (i = 0; i < 3; i++) {
		if (type[i] == 'D')
			score[i] = score[i] * score[i];
		if (type[i] == 'T')
			score[i] = score[i] * score[i] * score[i];

		if (option[i] == '*') { //option�� ���� ���
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