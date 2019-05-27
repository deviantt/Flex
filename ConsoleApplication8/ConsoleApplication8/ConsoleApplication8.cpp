#include "pch.h"
#include <iostream>
#include <string>

using namespace std;

string kop(int a) {
	if (a % 100 >= 10 && a % 100 <= 19) {
		return " копеек";
	}
	else {
		if (a % 10 == 0) return " копеек";
		if (a % 10 == 1) return " копейка";
		if (a % 10 >= 2 && a % 10 <= 4) return " копейки";
		if (a % 10 >= 5 && a % 10 <= 9) return " копеек";
	}
}

string rub(int a) {
	if (a / 100 % 100 >= 10 && a / 100 % 100 <= 19) {
		return "рублей";
	}
	else {
		if (a / 100 % 10 == 0) return " рублей ";
		if (a / 100 % 10 == 1) return " рубль ";
		if (a / 100 % 10  >= 2 && a / 100 % 10 <= 4) return " рубля ";
		if (a / 100 % 10 >= 5 && a / 100 % 10 <= 9) return " рублей ";
	}
}

void print(int a) {
	cout << a / 100 << rub(a) << a % 100 << kop(a);
}

int main()
{
	setlocale(LC_ALL, "Russian");
	int a;
	cin >> a;
	print(a);
}