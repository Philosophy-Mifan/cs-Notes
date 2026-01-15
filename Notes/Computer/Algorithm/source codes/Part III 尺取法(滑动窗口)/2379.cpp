#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
using namespace std;

int minimumRecolors(string blocks, int k) {
	int n = blocks.size();
	int cnt = 0;	//记录每个区间内的白色块的个数
	int left = 0;
	int right = k - 1;
	for (int i = left; i <= right; i++) {
		if (blocks[i] == 'W') {
			cnt++;
		}
	}
	int ans = cnt;
	while (right + 1 < n) {		//在遍历时不能越界！！也就是右指针在右移时不能超出block.size()
		if (blocks[right] == 'W') {
			cnt++;
		}
		right++;
		if (blocks[left] == 'W') {
			cnt--;
		}
		left++;
		ans = min(ans, cnt);
	}
	return ans;
}
int main() {
	int k;
	string blocks;
	cin >> blocks;
	scanf("%d", &k);
	int ans = minimumRecolors(blocks, k);
	printf("%d\n", ans);
	return 0;
}