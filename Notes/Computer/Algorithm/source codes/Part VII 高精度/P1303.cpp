#include<iostream>
#include<string>
using namespace std;


int a[2005];
int b[2005];
int c[4005];
//数据输入处理
int init(int x[]){
    string s;
    cin >> s;
    int length = s.size();
    for(int i = 0; i < s.size(); i++){
        x[i] = s[length - i - 1] - '0';	//把字符串倒着存进数组x
    }
    return length;
}
int main(){
    int length_a = init(a);
    int length_b = init(b);
    int length_c = length_a + length_b;
    for(int i = 0; i < length_a; i++){
        for(int j = 0; j < length_b; j++){
            c[i + j] += a[i] * b[j];
        }
    }
    //处理进位
    for(int i = 0; i < length_c; i++){
        if(c[i] >= 10){
            c[i + 1] += c[i] / 10;
            c[i] %= 10;
        }
    }
    //去掉前导0
    while(c[length_c] == 0 && length_c > 0){
        length_c--;
    }
    for(int i = length_c; i >= 0; i--){
        cout << c[i];
    }
    cout << endl;
    return 0;
}