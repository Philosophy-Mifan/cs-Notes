#pragma once
using namespace std;
#include "abstrCal.h"
class AddCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return num1 + num2;
	}
};
//减法 Subtraction
class SubCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return num1 - num2;
	}
};
//乘法 Multiplication
class MulCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return num1 * num2;
	}
};
//除法 Division
class DivCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		if (num2 == 0) {
			cout << "除数不能为0" << endl;
		}
		else {
			return num1 / num2;
		}
	}
};
//取余 Surplus
class SurCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return (int)num1 % (int)num2;	//取余是整数之间取余，使用强制类型转换
	}
};
//乘方 Power
class PowCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return num1 * num1;	//只输出num1的乘方
	}
};
//开根
class SqrtCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return sqrt(num1);
	}
};
//次幂
class PowpCalculator :public AbstractCalculator {
public:
	virtual double getResult() {
		return pow(num1, num2);//计算num1的num2次方
	}
};