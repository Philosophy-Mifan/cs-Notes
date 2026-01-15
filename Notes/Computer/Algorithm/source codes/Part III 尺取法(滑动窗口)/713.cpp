#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
int numSubarrayProductLessThanK(vector<int>& nums, int k) {
	int res = 0;
	int n = nums.size();
	int left = 0, right = 0;
	int sub = 1;	//乘积
	while (right < n) {
		sub *= nums[right];
		while (left < right && sub >= k) {
			sub /= nums[left];
			left++;
		}
		if (sub < k) {
			res += (right - left + 1);
		}
		right++;
	}
	return res;
}
int main() {
	int k = 0, n = 0, x = 0;
	vector<int> nums;
	scanf("%d %d", &k, &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &x);
		nums.push_back(x);
	}
	int ans = numSubarrayProductLessThanK(nums, k);
	printf("%d\n", ans);
	return 0;
}