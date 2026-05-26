#include <iostream>
#include <string>
#include "myCal.h"
using namespace std;

int main() {
	char select;
	double a = 0, b = 0;
	bool flag = 0;
	while (1) {
		menu();
		cout << "请输入序号进行选择：";
		cin >> select;
		switch (select)
		{
		case '1':
			Add(a, b);
			break;
		case '2':
			Sub(a, b);
			break;
		case '3':
			Mul(a, b);
			break;
		case '4':
			Div(a, b);
			break;
		case '5':
			Surplus(a, b);
			break;
		case '6':
			Pow(a);
			break;
		case '7':
			Sqrt(a);
			break;
		case '8':
			Powp(a, b);
			break;
		case 'Q':
			flag = quit();
			if (flag) {
				return 0;
			}
			break;
		default:
			flag = quit();
			if (flag) {
				exit(0);
			}
			break;
		}
	}
	return 0;
}