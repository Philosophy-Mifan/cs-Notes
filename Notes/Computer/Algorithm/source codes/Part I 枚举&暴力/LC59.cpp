#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;
vector<vector<int>> generateMatrix(int n) {	//将力扣中的默认代码直接放过来即可，类不用考虑
	vector<vector<int>> mat(n, vector<int>(n));
 	int left = 0;
 	int top = 0;
	int right = n - 1;
	int bottom = n - 1;
 	int num = 1;
 	while (num <= n * n) {
     	//left->right
     	for (int i = left; i <= right; i++) {
         	mat[top][i] = num++;
     	}
     	top++;
     	//top->bottom
     	for (int i = top; i <= bottom; i++) {
         	mat[i][right] = num++;
     	}
     	right--;
     	//right->left
     	for (int i = right; i >= left; i--) {
         	mat[bottom][i] = num++;
     	}
     	bottom--;
     	//bottom->top
     	for (int i = bottom; i >= top; i--) {
         	mat[i][left] = num++;
     	}
     	left++;
	}
	return mat;
}
int main(){		//在本地测试时，无需与力扣中的输出格式一致，在本地只测试输出是否合理即可
    int n;
	scanf("%d", &n);
	vector<vector<int>> a = generateMartix(n);
	for (int i = 0; i < n; i++) {
    	for (int j = 0; j < n; j++) {
        	printf("%d ", a[i][j]);
    	}
    printf("\n");
	}
return 0;
}