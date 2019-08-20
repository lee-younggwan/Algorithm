#include <string>
#include <vector>
#include <queue>

using namespace std;

vector <string> cache;
int solution(int cacheSize, vector<string> cities) {
	int answer = 0;
	int i, j;

	if (cacheSize == 0)
		return cities.size() * 5;

	for (i = 0; i < cities.size(); i++) {
		for (j = 0; j < cities[i].length(); j++)
			cities[i][j] = toupper(cities[i][j]);

		if (cache.empty()) { //캐쉬가 빈 경우 miss
			cache.push_back(cities[i]);
			answer += 5;
		}
		
		else if (cache.size() < cacheSize) { //캐쉬 크기가 캐시사이즈만큼 안되는 경우
			for (j = 0; j < cache.size(); j++) {
				if (cache[j] == cities[i]) {
					cache.erase(cache.begin() + j);
					answer += 1;
					cache.push_back(cities[i]);
					break;
				}
			}
			if (j == cache.size()) {
				cache.push_back(cities[i]);
				answer += 5;
			}

		}
		else {
			for (j = 0; j < cache.size(); j++) {
				if (cache[j] == cities[i]) {
					cache.erase(cache.begin() + j);
					answer += 1;
					cache.push_back(cities[i]);
					break;
				}
			}
			if (j == cache.size()) {
				cache.erase(cache.begin());
				answer += 5;
				cache.push_back(cities[i]);
			}
		}
	}
	return answer;
}

int main()
{
	//int result = solution(3, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "Jeju", "Pangyo", "Seoul", "NewYork", "LA" });
	//int result = solution(5, { "Jeju", "Pangyo", "Seoul", "NewYork", "LA", "SanFrancisco", "Seoul", "Rome", "Paris", "Jeju", "NewYork", "Rome" });
	int result = solution(2, { "jeju","pangyo","Newyork","newyork" });
	printf("%d\n", result);
}