#pragma warning (disable:4996)
#include<iostream>
#include<cstdio>
#include<vector>
#include<limits.h>
using namespace std;

int minSubArrayLen(int target, vector<int>& nums) {
	int res = INT_MAX;
	int n = nums.size();	//数组长度：0~n-1
	int left = 0, right = 0;
	int sum = 0;	//存放区间和
	while (right < n) {
		sum += nums[right];
		while (left <= right && sum - nums[left] >= target) {	//每次都往右边缩，去找最符合条件的
			sum -= nums[left];
			left++;
		}
		if (sum >= target) {
			res = min(res, right - left + 1);
		}
		right++;		//不断往右边扩展
	}
	if (res == INT_MAX) {
		res = 0;
	}
	return res;
}
int main() {
	int target, length, x;      //length只是为了方便下述读取数据以及验证，在leetcode中只需要使用上述函数的内容即可
	vector<int>& nums;
	scanf("%d %d", target, length);
	for (int i = 0; i < length; i++) {
		scanf("%d", &x);
		nums.push_back(x);
	}
	int ans = minSubArrayLen(target, nums);
	printf("%d\n", ans);
	return 0;
}