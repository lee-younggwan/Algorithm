#define _CRT_SECURE_NO_WARNINGS
#include <vector>
#include <queue>
using namespace std;


// 전역 변수를 정의할 경우 함수 내에 초기화 코드를 꼭 작성해주세요.

vector<int> solution(int m, int n, vector<vector<int>> picture) {
	int number_of_area = 0;
	int max_size_of_one_area = 0;
	int i, j;
	int visit[101][101];
	for (i = 0; i < 101; i++)
		for (j = 0; j< 101; j++)
			visit[i][j] = 0;

	int dr[] = { -1,0,1,0 };
	int dc[] = { 0,1,0,-1 };

	queue <pair <int, int> > que;
	for (i = 0; i < m; i++) {
		for (j = 0; j < n; j++) {
			//색칠하지 않은 영역이 아니고 방문한적이 없는 경우
			//영역의 개수를 1개 늘리고 bfs를 돌려서 주변에 같은 영역으로 확장
			if (visit[i][j] != 1 && picture[i][j] != 0) {
				number_of_area++;
				que.push(make_pair(i, j));
				visit[i][j] = 1;
				int count = 1;

				while (!que.empty()) {
					int now_row = que.front().first;
					int now_col = que.front().second;
					que.pop();

					for (int k = 0; k < 4; k++) {
						int next_row = now_row + dr[k];
						int next_col = now_col + dc[k];

						//다음 위치가 범위 안이고 아직 방문하지 않고, 색이 같은 경우 que에 넣는다
						if (next_row >= 0 && next_row < m && next_col >= 0 && next_col < n) {
							if (visit[next_row][next_col] != 1 && picture[next_row][next_col] == picture[now_row][now_col]) {
								que.push(make_pair(next_row, next_col));
								count++;
								visit[next_row][next_col] = 1;
							}
						}
					}
				}
				max_size_of_one_area = max(count, max_size_of_one_area);
			}
		}
	}
	vector<int> answer(2);
	answer[0] = number_of_area;
	answer[1] = max_size_of_one_area;
	return answer;
}

int main() {
	solution(6, 4, { {1, 1, 1, 0},{1, 1, 1, 0},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1},{0, 0, 0, 1} });
}