#include <string>
#include <vector>
#include <algorithm>
using namespace std;

bool comp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.second < b.second;
}
int solution(vector<int> food_times, long long k) {
	int answer = 0;
	long long i, j;
	long long sum = 0;

	vector <pair<int, int>> vec;
	for (i = 0; i < food_times.size(); i++) {
		vec.push_back(make_pair(food_times[i], i + 1)); //food_times���� index�� ����
		sum += food_times[i];
	}
	if (sum <= k) //food_times�� ������ k���� ������ ���̻� ���� ������ �����Ƿ� -1
		return -1;

	long long size = food_times.size();
	sort(vec.begin(), vec.end());

	long long len = size; //���� ������ ��
	long long cur = 0;
	long long before = 0;
	
	while (1) {
		long long min = vec[cur].first; // ���� ���� ��
		
		if (k < len*(min-before)) {
			sort(vec.begin() + cur, vec.end(), comp);
			return vec[cur + k % len].second;
		}

		for (i = cur; i < size; i++) {
			if (min != vec[i].first) {
				cur = i;
				break;
			}
		}

		k = k - len * (min-before);
		len = size - cur; // ���� ������ ��
		before = min;
	}

}
int main() {
	solution({ 123456789, 987654321, 897654321, 789654321 }, 500000000);
}