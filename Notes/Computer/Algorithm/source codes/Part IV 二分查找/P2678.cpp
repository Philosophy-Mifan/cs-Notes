#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int main() {
	int L, N, M;
	int arr[50005];
	cin >> L >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> arr[i];
	}
	arr[N + 1] = L;		//终点
	int left = 1, right = L, mid = 0;
	while (left < right) {
		mid = (left + right) / 2;
	}
}