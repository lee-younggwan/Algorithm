#include <string>
#include <vector>
#include <iostream>
#include <math.h>
using namespace std;

vector <string> set1;
vector <string> set2;

int solution(string str1, string str2) {
	int answer = 0;
	int i, j;

	for (i = 0; i < str1.length();) {
		if (isalpha(str1[i]) && isalpha(str1[i + 1])) { // �� ���ھ� ������ �� �������� ���
			str1[i] = tolower(str1[i]);
			str1[i + 1] = tolower(str1[i + 1]);
			string temp;
			temp.append(1, str1[i]); temp.append(1, str1[i + 1]);
			set1.push_back(temp);
			i++;
		}
		else { //�����ڰ� �ƴ� ���
			if (!isalpha(str1[i]) && !isalpha(str1[i + 1])) //�Ѵ� �����ڰ� �ƴѰ��
				i = i + 2;
			else if (!isalpha(str1[i])) // ù��°�� �����ڰ� �ƴѰ��
				i++;
			else if (!isalpha(str1[i + 1])) //�ι�°�� �����ڰ� �ƴ� ���
				i = i + 2;
		}
	}
	for (i = 0; i < str2.length();) {
		if (isalpha(str2[i]) && isalpha(str2[i + 1])) { // �� ���ھ� ������ �� �������� ���
			str2[i] = tolower(str2[i]);
			str2[i + 1] = tolower(str2[i + 1]);
			string temp;
			temp.append(1, str2[i]); temp.append(1, str2[i + 1]);
			set2.push_back(temp);
			i++;
		}
		else { //�����ڰ� �ƴ� ���
			if (!isalpha(str2[i]) && !isalpha(str2[i + 1])) //�Ѵ� �����ڰ� �ƴѰ��
				i = i + 2;
			else if (!isalpha(str2[i])) // ù��°�� �����ڰ� �ƴѰ��
				i++;
			else if (!isalpha(str2[i + 1])) //�ι�°�� �����ڰ� �ƴ� ���
				i = i + 2;
		}
	}
	if (set1.empty() && set2.empty())
		return 65536;
	vector <string> temp1 = set1;
	vector <string> temp2 = set2;
	//�������� ���Ѵ�
	int count = 0;
	for (i = 0; i < temp1.size(); i++) {
		for (j = 0; j < temp2.size(); j++) {
			if (temp1[i] == temp2[j]) {
				temp2.erase(temp2.begin() + j);
				count++;
				break;
			}
		}
	}
	//�������� ���Ѵ�
	int uni = set1.size() + set2.size() - count;
	if(uni == 0)
		return 65536;
	double temp = double(count) / double(uni);
	
	answer = temp * 65536;
	return answer;
}
int main()
{
	printf("%d\n", solution("aa1+aa2", "AAAA12"));
}