#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string>
#include <iostream>
#include <vector>
using namespace std;

/*            U
		  0  1  2
		  3  4  5
		  6  7  8
L        __________    R            B
36 37 38|F18 19 20 | 45 46 47 | 27 28 29
39 40 41| 21 22 23 | 48 49 50 | 30 31 32
42 43 44| 24 25 26 | 51 52 53 | 33 34 35
		-----------
		  9  10 11
		  12 13 14
		  15 16 17
		  D
		  https://sangdo913.tistory.com/185

		  */
int N;
int rot[6][12] = {
	{36,37,38,18,19,20,45,46,47,27,28,29},        //U
	{33,34,35,51,52,53,24,25,26,42,43,44},        //D
	{6,7,8,44,41,38,11,10,9,45,48,51},            //F
	{2,1,0,53,50,47,15,16,17,36,39,42},           //B
	{0,3,6,35,32,29,9,12,15,18,21,24},            //L
	{8,5,2,26,23,20,17,14,11,27,30,33}            //R
};
char color[] = {
	'w','w','w','w','w','w','w','w','w',
	'y','y','y','y','y','y','y','y','y',
	'r','r','r','r','r','r','r','r','r',
	'o','o','o','o','o','o','o','o','o',
	'g','g','g','g','g','g','g','g','g',
	'b','b','b','b','b','b','b','b','b'
};
void print() {
	for (int i = 0; i < 54; i++) {
		if (i % 3 == 0 && i != 0)
			printf("\n");
		printf("%c", color[i]);
	}
	printf("\n");
}
void rotate(int face, int cnt) {
	int start;
	if (face == 0)
		start = 0;
	else if (face == 1)
		start = 9;
	else if (face == 2)
		start = 18;
	else if (face == 3)
		start = 27;
	else if (face == 4)
		start = 36;
	else if (face == 5)
		start = 45;

	while (cnt > 0) {
		vector <char> vec;
		for (int i = 0; i < 12; i++)
			vec.push_back(color[rot[face][i]]);

		//인접한 면들의 색상 변경
		char tempcolor[] = { color[vec[0]], color[vec[1]], color[vec[2]] };
		for (int i = 0; i < 12; i++) {
			color[rot[face][i]] = vec[(i + 3) % 12];
			//printf("%c", color[rot[face][i]]);
		}
		/*
		012
		345
		678
		*/
		char temp[] = { color[start], color[start + 1], color[start + 2] };
		color[start + 2] = color[start];
		color[start + 1] = color[start + 3];
		color[start] = color[start + 6];
		color[start + 3] = color[start + 7];
		color[start + 6] = color[start + 8];
		color[start + 7] = color[start + 5];
		color[start + 8] = temp[2];
		color[start + 5] = temp[1];
		//printf("-------------%d----------\n", cnt);
		//print();
		cnt--;
	}

}
char init[7] = "wyrogb";
int main() {
	scanf("%d", &N);
	for (int test_case = 0; test_case < N; test_case++) {
		int n;
		string temp;
		for (int j = 0; j < 6; j++)
			for (int k = 0; k < 9; k++) {
				color[j * 9 + k] = init[j];
			}
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			cin >> temp;
			int face, cnt = 1;

			
				
			if (temp[1] == '-')
				cnt = 3;

			if (temp[0] == 'U')
				rotate(0, cnt);
			else if (temp[0] == 'D')
				rotate(1, cnt);
			else if (temp[0] == 'F')
				rotate(2, cnt);
			else if (temp[0] == 'B')
				rotate(3, cnt);
			else if (temp[0] == 'L')
				rotate(4, cnt);
			else
				rotate(5, cnt);

		}
		for (int i = 0; i < 9; i++) {
			if (i % 3 == 0 && i != 0)
				printf("\n");
			printf("%c", color[i]);
		}
		printf("\n");
	}
	return 0;
}