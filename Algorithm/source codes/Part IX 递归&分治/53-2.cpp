#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int mid_sum(vector<int>& nums, int left, int right, int mid){
    int leftMax = INT_MIN; //向左延伸的最大值
    int sum = 0;
    for(int i = mid; i >= left; i--){
        sum += nums[i];
        leftMax = max(leftMax, sum);
    }
    int rightMax = INT_MIN; //向右延伸的最大值
    sum = 0;
    for(int i = mid + 1; i <= right; i++){
        sum += nums[i];
        rightMax = max(rightMax, sum);
    }
    return leftMax + rightMax;
}

int maxSub(vector<int>& nums, int left, int right){
    if (left == right){     //递归边界
        return nums[left];
    }
    // 分治
    int mid = left + (right - left) / 2;
    int leftMax = maxSub(nums, left, mid);
    int rightMax = maxSub(nums, mid + 1, right);
    // 跨越中点
    int midium_sum = mid_sum(nums, left, right, mid);
    return max(max(leftMax, rightMax), midium_sum);
}

int maxSubArray(vector<int>& nums) {
    int ans = INT_MIN;
    int n = nums.size();
    ans = maxSub(nums, 0 ,n - 1);
    return ans;
}

int main(){
    int n, k, x;
    vector<int> nums;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        nums.push_back(x);
    }
    int ans = maxSubArray(nums);
    cout << ans << endl;
    return 0;
}