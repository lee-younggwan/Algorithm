#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//B�� ���� ū���� A�� ���� ū ���� ��Ī.. 
	//A�� �� ū ��� B�� ���� ���� ���� ��Ī...
	int min = 0, max = B.size() - 1;
	for (int i = A.size()-1; i >= 0; i--) {
		if (B[max] > A[i]) {
			answer++;
			max--;
		}
	}
	return answer;
}