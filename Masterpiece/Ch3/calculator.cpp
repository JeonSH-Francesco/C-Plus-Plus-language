Adder.h

#pragma once
#ifndef ADDER_H
#define ADDER_H

//덧셈 모듈 클래스
class Adder{
	int op1, op2;
public:
	Adder(int a, int b);
	int process();
};
#endif
===========
Adder.cpp

#include "Adder.h"

Adder::Adder(int a, int b) {
	op1 = a;
	op2 = b;
}

int Adder::process() {
	return op1 + op2;
}


=================

Calculator.h

#pragma once
#ifndef Cal_h
#define Cal_h
//계산기 클래스
class Calculator {
public:
	void run();
};

#endif
=========================
Calcultor.cpp
#include <iostream>
using namespace std;

#include "Adder.h"
#include "Calculator.h"

void Calculator::run() {
	cout << "두개의 수를 입력하세요~>> : ";
	int a, b;
	cin >> a >> b;	//정수 2개 입력
	Adder adder(a, b); // 덧셈기 생성
	cout << adder.process(); //덧셈 계산
}
=======
main.cpp
#include "Calculator.h"
int main() {
	Calculator calc;
	calc.run();
}
