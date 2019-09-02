#include <string>
#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

char number[] = { '0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F' };
string changeNum(int n, int num)
{
	int i;
	string result = "";
	while (1) {
		int mod = num % n;
		result += number[mod];
		num = num / n;
		if (num == 0)
			break;
	}
	reverse(result.begin(), result.end());
	return result;

}
//���� n, �̸� ���� ������ ���� t, ���ӿ� �����ϴ� �ο� m, Ʃ���� ���� p �� �־�����.
string solution(int n, int t, int m, int p) {
	string answer = "";
	string result = "";
	int i, j;

	int num = 0;
	while (1) {
		if (result.length() > t*m)
			break;
		result += changeNum(n, num);
		num++;
	}
	int count = 0;
	for (i = 0; i < result.length(); i++) {
		if (count == t)
			break;
		if (i%m == p - 1) {
			answer += result[i];
			count++;
		}
	}
	//reverse(answer.begin(), answer.end());
	return answer;
}
int main()
{
	cout << solution(16, 16, 2, 2) << endl;
}