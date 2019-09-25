#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <algorithm>
#include <vector>
using namespace std;

int N, M, K;
int r, c, s;
int MAP[51][51];
int visit[6];
int answer = 987654321;
vector <pair <pair <int, int>, int> > rotation;
void print(int copy[][51]) {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= M; j++)
			printf("%d ", copy[i][j]);
		printf("\n");
	}
}
void findMin(vector<int>order) {
	int i, j, k;
	int COPY[51][51];

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			COPY[i][j] = MAP[i][j];
	for (i = 0; i < order.size(); i++) {
		int r = rotation[order[i]].first.first;
		int c = rotation[order[i]].first.second;
		int s = rotation[order[i]].second;

		int size = 2 * s + 1; //���簢���� ũ��
		while (size > 1) {
			vector <int> vec;
			//��,������,�Ʒ�,���� �ٱ��� ���� ������� ���� �ִ´�
			for (j = c - s; j <= c + s; j++)
				vec.push_back(COPY[r - s][j]);

			for (j = r - s + 1; j <= r + s - 1; j++)
				vec.push_back(COPY[j][c + s]);

			for (j = c + s; j >= c - s; j--)
				vec.push_back(COPY[r + s][j]);

			for (j = r + s - 1; j >= r - s + 1; j--)
				vec.push_back(COPY[j][c - s]);

			//���� ���� ���� �� ĭ�� ȸ����Ų��
			int idx = 0;
			for (j = c - s; j <= c + s; j++)
				COPY[r - s][j] = vec[(vec.size() - 1 + idx++) % vec.size()];

			for (j = r - s + 1; j <= r + s - 1; j++)
				COPY[j][c + s] = vec[(vec.size() - 1 + idx++) % vec.size()];

			for (j = c + s; j >= c - s; j--)
				COPY[r + s][j] = vec[(vec.size() - 1 + idx++) % vec.size()];

			for (j = r + s - 1; j >= r - s + 1; j--)
				COPY[j][c - s] = vec[(vec.size() - 1 + idx++) % vec.size()];
			//printf("--------------%d---\n", size);
			//print(COPY);

			s--;
			size = size - 2;
		}
	}
	for (i = 1; i <= N; i++) {
		int sum = 0;
		for (j = 1; j <= M; j++) {
			sum = sum + COPY[i][j];
		}
		answer = min(answer, sum);
	}

}
void dfs(int depth, vector<int>order) {
	//��� ������ �� ���� ��� ȸ���� ��Ű�� �ּҰ��� ã�´�
	if (depth == K) {
		findMin(order);
		return;
	}

	for (int i = 0; i < K; i++) {
		if (!visit[i]) {
			visit[i] = 1;
			order.push_back(i);
			dfs(depth + 1, order);
			order.pop_back();
			visit[i] = 0;
		}
	}
}
int main() {
	int i, j;
	scanf("%d %d %d", &N, &M, &K);

	for (i = 1; i <= N; i++)
		for (j = 1; j <= M; j++)
			scanf("%d", &MAP[i][j]);

	for (i = 0; i < K; i++) {
		scanf("%d %d %d", &r, &c, &s);
		rotation.push_back(make_pair(make_pair(r, c), s));
	}

	//ȸ���� �� �ִ� ��� ���������� �����
	dfs(0, {});

	printf("%d\n", answer);
}