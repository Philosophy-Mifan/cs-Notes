#include<iostream>
#include<cstdio>
#include<vector>
#include<cmath>
using namespace std;
//快速幂  求n^x
int n, x, j, p, a, b;
int ans = 1;
int main() {
    cin >> n >> x >> p;
    a = n, b = x;
    while (x != 0) {
        j = x % 2;	//j就是x的二进制的某一位
        if (j == 1) {
            ans = (ans * n) % p;
        }
        n = (n * n) % p;;
        x /= 2;
    }
    cout << a << "^" << b << " mod " << p << "=" << ans % p << endl;

    return 0;
}