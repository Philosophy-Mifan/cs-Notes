#include<iostream>
#include<cstdio>

int n;
int a[10005], b[10005], g[10005], k[10005];
int x, y;
int num;

int main(){
	scanf("%d", &n);
	for (int i = 0; i < n; i++){
		scanf("%d %d %d %d", &a[i], &b[i], &g[i], &k[i]);
	}
	scanf("%d %d", &x, &y);
	for (int i = n; i >= 0; i--){
		if (x >= a[i] && y >= b[i] && x <= a[i] + g[i] && y <= b[i] + k[i]){
			num = i + 1;
			break;
		}
		else{
			num = -1;
		}
	}
	printf("%d", num);
	return 0;
}