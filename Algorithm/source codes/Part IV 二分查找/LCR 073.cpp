#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
long getTime(vector<int>& piles, int mid) {
	long time = 0;
	int n = piles.size();
	for (int i = 0; i < n; i++) {
		time += piles[i] / mid;
		if (piles[i] % mid != 0) {
			time++;
		}
	}
	return time;
}
int minEatingSpeed(vector<int>& piles, int h) {
	int left = 1;
	int mid, time, ans;
	int n = piles.size();
	int right = piles[0];
	for (int i = 1; i < n; i++) {
		right = max(right, piles[i]);
	}
	while (left <= right) {
		mid = (left + right) / 2;
		time = getTime(piles, mid);
		if (time <= h) {
			ans = mid;	//可能是答案，但需要继续找更小的mid
			right = mid - 1;
		}
		else {
			left = mid + 1;
		}
	}
	return ans;
}
int main() {
	vector<int> piles;
	int n, h, a;
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		cin >> a;
		piles.push_back(a);
	}
	int ans = minEatingSpeed(piles, h);
	cout << ans << endl;
	return 0;
}