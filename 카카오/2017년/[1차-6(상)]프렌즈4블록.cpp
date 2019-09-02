#include <string>
#include <vector>
#include <queue>
using namespace std;

int dr[] = { 0,1,1 };
int dc[] = { 1,1,0 };
char MAP[32][32];
int visit[32][32];
int flag = 0;
void moveBlock(int m, int n)
{
	int i, j, k;
	for (i = 0; i < n; i++) {
		for (j = m - 1; j >= 0; j--) {
			if (MAP[j][i] == ' ') { // 빈 공간인 경우
				for (k = j; k >= 0; k--) {
					if (MAP[k][i] != ' ') {
						MAP[j][i] = MAP[k][i];
						MAP[k][i] = ' ';
						break;
					}
				}
			}
		}
	}
}
int solution(int m, int n, vector<string> board) {
	int answer = 0;
	int i, j;
	for (i = 0; i < m; i++)
		for (j = 0; j < n; j++)
			MAP[i][j] = board[i][j];

	while (1) {
		//2x2 블록을 찾는 과정
		flag = 0;
		for (i = 0; i < m-1; i++) {
			for (j = 0; j < n-1; j++) {
				char block = MAP[i][j];
				if (MAP[i][j + 1] == block && MAP[i + 1][j + 1] == block && MAP[i + 1][j] == block && isalpha(block)) {
					visit[i][j] = 2;
					visit[i][j + 1] = 2;
					visit[i + 1][j] = 2;
					visit[i + 1][j + 1] = 2;
					flag = 1;
				}
			}
		}
		if (flag == 0)
			break;
		for (i = 0; i < m ; i++) {
			for (j = 0; j < n ; j++) {
				if (visit[i][j] == 2) {
					visit[i][j] = 0;
					MAP[i][j] = ' ';
					answer++;
				}
			}
		}
		//블록이 떨어지는 과정
		moveBlock(m, n);
	}
	return answer;

}

int main()
{
	printf("%d\n", solution(30, 30, { "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT",  "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT", "TTTTTTTTTTTTTTTTTTTTTTTTTTTTTT" }));
}