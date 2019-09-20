#define _CRT_SECURE_NO_WARNINGS
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

int solution(vector<int> A, vector<int> B) {
	int answer = 0;

	sort(A.begin(), A.end());
	sort(B.begin(), B.end());

	//B의 가장 큰값은 A의 가장 큰 값과 매칭.. 
	//A가 더 큰 경우 B의 가장 작은 값과 매칭...
	int min = 0, max = B.size() - 1;
	for (int i = A.size()-1; i >= 0; i--) {
		if (B[max] > A[i]) {
			answer++;
			max--;
		}
	}
	return answer;
}