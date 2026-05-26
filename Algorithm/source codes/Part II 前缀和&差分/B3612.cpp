#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int n, m, l, r;
int a[100005], sum[100005];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
		sum[i] = sum[i - 1] + a[i];
	}
	scanf("%d", &m);
	for (int i = 1; i <= m; i++) {
		scanf("%d %d", &l, &r);
		printf("%d\n", sum[r] - sum[l - 1]);
	}
	return 0;
}