#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;

int a[505];
int b[505];
int c[505];
//数据输入处理
int init(int x[]) {
    string s;
    cin >> s;
    int length = s.size();
    for (int i = 0; i < s.size(); i++) {
        x[i] = s[length - i - 1] - '0';	//把字符串倒着存到数组中，这是为了方便对齐最低位以进行计算
    }
    return length;
}
//算a+b
int main() {
    int length_a = init(a);
    int length_b = init(b);
    int length_c = max(length_a, length_b);
    for (int i = 0; i < length_c; i++) {
        c[i] += a[i] + b[i];	//不要直接=，c[i]可能会有本身就该进位的数字
        //大于10则进位
        if (c[i] >= 10) {
            c[i + 1]++;
            c[i] -= 10;
        }
    }
        //计算结果是否产生进位导致length_c没有完全存入
    if (c[length_c] != 0) {
        cout << c[length_c];
    }
    for (int i = length_c - 1; i >= 0; i--) {
        cout << c[i];
    }
    cout << endl;
    return 0;
}