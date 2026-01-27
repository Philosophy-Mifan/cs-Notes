#include<iostream>
#include<vector>
#include<queue>
#include<algorithm>
using namespace std;
int n;
int h[305];
int main(){
    cin >> n;
    for (int i = 1; i <= n; i++) {
        cin >> h[i];
    }
    h[0] = 0;   //地面
    sort(h, h + n + 1); //nlogn
    int left = 0, right = n;
    long long ans = 0;
    while (left < right) { //n
        ans += (h[right] - h[left]) * (h[right] - h[left]);
        left++;
        ans += (h[right] - h[left]) * (h[right] - h[left]);
        right--;
    }
    cout << ans << endl;
    return 0;
}