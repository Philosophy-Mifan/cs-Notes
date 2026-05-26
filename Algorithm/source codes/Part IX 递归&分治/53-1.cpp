#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int maxSubArray(vector<int>& nums){
    int ans = INT_MIN;
    int length = nums.size();
    for(int i = 0; i < length; i++){
        int sum = 0;
        for(int j = i; j < length; j++){
            sum += nums[j];
            ans = max(ans, sum);
        }
    }
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