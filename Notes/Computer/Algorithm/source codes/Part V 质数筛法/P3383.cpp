#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

int prime[6000005], k = 0;
bool isPrime[100000005];	//isPrime[i] = 1 就是质数
void GetPrime(int n) {
	memset(isPrime, 1, sizeof(isPrime));	//初始全为质数
	prime[1] = 0;
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			prime[++k] = i;
		}
		//枚举质数表-----质数表中的数据是升序的
		for (int j = 1; j <= k && i * prime[j] <= n; j++) {
			isPrime[i * prime[j]] = 0;	//把x标记成合数
			//保证只筛选到以prime[j]为最小质因数的数
			if (i % prime[j] == 0) {
				break;
			}//保证了只筛选到以prime[j]为最小质因数的数，如果继续循环，让i乘上后面的质数，得到的合数就不是被prime[j]筛选掉的
		}
	}
}
int main() {
	std::ios::sync_with_stdio(0);
	std::cin.tie(NULL);
	int n, q;
	cin >> n >> q;
	GetPrime(n);
	while (q--) {
		int k;
		cin >> k;
		cout << prime[k] << '\n';
	}
	return 0;
}