#include "myFunc.h"
void Add(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new AddCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << " + " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//减法的实现
void Sub(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new SubCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << " - " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//乘法的实现
void Mul(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new MulCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << " * " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//除法的实现
void Div(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new DivCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << " / " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//取余的实现
void Surplus(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new SurCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << " % " << p->num2 << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//乘方的实现
void Pow(double a) {
	cout << "请输入a的值:" << endl;
	cin >> a;
	AbstractCalculator* p = new PowCalculator;
	p->num1 = a;
	cout << p->num1 << " 的平方 " << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//开根的实现
void Sqrt(double a) {
	cout << "请输入a的值:" << endl;
	cin >> a;
	AbstractCalculator* p = new SqrtCalculator;
	p->num1 = a;
	cout << p->num1 << " 的开方 " << " = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//次幂的实现
void Powp(double a, double b) {
	cout << "请输入a和b的值（使用空格隔开）:" << endl;
	cin >> a >> b;
	AbstractCalculator* p = new PowpCalculator;
	p->num1 = a;
	p->num2 = b;
	cout << p->num1 << "的" << p->num2 << "次方 = " << p->getResult() << endl;
	delete p;
	cout << "请按任意键继续" << endl;
	system("pause");
	system("cls");
}
//菜单函数
void menu() {
	cout << "*************************" << endl
		<< "******   1.加法    ******" << endl
		<< "******   2.减法    ******" << endl
		<< "******   3.乘法    ******" << endl
		<< "***** 4.除法(整除) *****" << endl
		<< "******   5.取余    ******" << endl
		<< "******   6.乘方    ******" << endl
		<< "******   7.开根    ******" << endl
		<< "******   8.次幂    ******" << endl
		<< "******   Q.Exit    ******" << endl
		<< "*************************" << endl;
}
//退出函数
bool quit() {
	char select;
	cout << "确定退出吗？[Y/N]" << endl;
	cin >> select;
	if (select == 'Y' || select == 'y') {
		cout << "欢迎下次使用" << endl;
		return 1;
	}
	else {
		system("cls");
		return 0;
	}
}