#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n, m;
int a[105][105];
int b[105][105];	//前缀和数组
int ans;	//最大的边长
int l;	//边长
int s;	//区域和
int main() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> a[i][j];
			b[i][j] = b[i][j - 1] + b[i - 1][j] - b[i - 1][j - i] + a[i][j];
		}
	}
	ans = 1;
	l = 2;
	while (l <= min(n, m)) {
		for (int i = l; i <= n; i++) {
			for (int j = 1; j <= m; j++) {	//枚举正方形的右下角下标
				s = b[i][j] - b[i - 1][j] - b[i][j - 1] + b[i - 1][j - 1];
				if (s == l * l) {
					ans = max(ans, l);
				}
			}
		}
		l++;
	}
	cout << ans << endl;
	return 0;
}
