#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;
int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int ans = 0;
        vector<int> diff;   //差值数组
        int n = reward1.size();
        for(int i = 0; i < n; i++){
            ans += reward2[i];   //先全部选reward2的奶酪
            diff.push_back(reward1[i] - reward2[i]); //计算差值
        }
        sort(diff.begin(), diff.end(), greater<int>());
        for(int i = 0; i < k; i++){
            ans += diff[i];
        }
        return ans;
}
int main(){
    int n, k, x;
    vector<int> reward1, reward2;
    cin >> n >> k;
    for(int i = 0; i < n; i++){
        cin >> x;
        reward1.push_back(x);
    }
    for(int i = 0; i < n; i++){
        cin >> x;
        reward2.push_back(x);
    }
    cout << miceAndCheese(reward1, reward2, k) << endl;
    return 0;
}