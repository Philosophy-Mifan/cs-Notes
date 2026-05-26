#include <iostream>
#include <vector>
#include <queue>
using namespace std;
priority_queue<long long, vector<long long>, greater<long long>> q;   //小顶优先级高
int n, x, y;
long long ans;
int main(){
    cin >> n;
    for(i = 0; i < n; i++){
        cin >> x;
        q.push(x);
    }
    for(int i = 0; i < n - 1; i++){
        x = q.top();
        q.pop();
        y = q.top();
        q.pop();
        ans += x + y;
        q.push(x + y);
    }
    cout << ans << endl;
    return 0;
}
