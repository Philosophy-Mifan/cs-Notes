#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int L, N, M, ans;
int arr[50005];

bool check(int mid) {
	int x = 0;	//移走石块的数量
	int now = 0, nex = 0;	//next是关键字
	while (nex < N + 1) {
		nex++;
		if (arr[nex] - arr[now] < mid) {
			x++;
		}
		else {
			now = nex;
		}
	}
	if (x <= M) {
		return 1;
	}
	else {
		return 0;
	}
}
int main() {
	cin >> L >> N >> M;
	for (int i = 1; i <= N; i++) {
		cin >> arr[i];
	}
	arr[N + 1] = L;		//终点
	int left = 1, right = L, mid = 0;
	int ans;
	while (left <= right) {
		mid = (left + right) / 2;
		if (check(mid) == 1) {
			ans = mid;
			left = mid + 1;
		}
		else {
			right = mid - 1;
		}
	}
	cout << ans << endl;
	return 0;
}