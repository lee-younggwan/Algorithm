#include <string>
#include <vector>

using namespace std;

vector<string> solution(int n, vector<int> arr1, vector<int> arr2) {
	vector<string> answer;
	for (int i = 0; i < n; i++) {
		int c = arr1[i] | arr2[i];
		string temp;
		for (int j = 0; j < n; j++) {
			temp.append(to_string(c % 2));
			c = c / 2;
		}
		string result;
		for (int j = n - 1; j >= 0; j--) {
			if (temp[j] == '1')
				result.append("#");
			else
				result.append(" ");
		}
		answer.push_back(result);
	}
	return answer;
}