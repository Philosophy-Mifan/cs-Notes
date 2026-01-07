#include<iostream>
#include<cstdio>
using namespace std;
int score[5][5] = {
	{0, 0, 1, 1, 0},
	{1, 0, 0, 1, 0},
	{0, 1, 0, 0, 1},
	{0, 0, 1, 0, 1},
	{1, 1, 0, 0 ,0}
};
int N, Na, Nb;
int a[205], b[205];
int score_a, score_b;
int x, y;
int main() {
	scanf("%d %d %d", &N, &Na, &Nb);
	for (int i = 0; i < Na; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < Nb; i++) {
		scanf("%d", &b[i]);
	}
	for (int i = 0; i < N; i++) {
		score_a += score[a[x]][b[y]];
		score_b += score[b[y]][a[x]];
		x = (x + 1) % Na;
		y = (y + 1) % Nb;
	}
	printf("%d %d", score_a, score_b);
	return 0;
}