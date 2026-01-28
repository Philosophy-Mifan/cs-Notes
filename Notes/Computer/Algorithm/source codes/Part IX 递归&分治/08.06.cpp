#include<iostream>
#include<vector>
using namespace std;
void move(int n, vector<int>& A, vector<int>& B, vector<int>& C){
        if(n == 1){
            C.push_back(A.back());
            A.pop_back();
            return;
        }
        move(n - 1, A, C, B);
        C.push_back(A.back());
        A.pop_back();
        move(n - 1, B, A, C);
    }
void hanota(vector<int>& A, vector<int>& B, vector<int>& C) {
        int n = A.size();
        move(n, A, B, C);
    }

int main(){
    int n, k, x;
    vector<int> a, b, c;
    cin >> n;
    for(int i = 0; i < n; i++){
        cin >> x;
        a.push_back(x);
    }
    hanota(a, b, c);
    for(int i = 0; i < n; i++){
        cout << c[i] << " ";
    }
    
    return 0;
}