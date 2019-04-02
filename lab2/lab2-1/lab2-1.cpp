#include "pch.h"
#include <iostream>

using namespace std;

int main()
{
	int k = 0, f = 0;
	int *arr = new int[255];
	char *in = new char[255];
	cout << "Input constants: " << endl;
	do {
		cin.getline(in, 200);
		arr[k] = 0;
		int minus = 0;
		for (int i = 0; i < strlen(in); i++) {
			if (in[i] < '0' && in[i] > '9') {
					cout << "Wrong input!";
					break;
			}
		}	
		for (int i = 0; i < strlen(in); i++) {
			if (in[0] == 'e' && in[1] == 'n' && in[2] == 'd') {
				f = 1;
				break;
			}
			if (in[0] == '-') {
				minus = 1;
				in[0] = '0';
			}
			if (in[i] == '0' ) {
				arr[k] += 0;
			}
			else {
				in[i] -= '0';
				arr[k] += in[i] * pow(10, (strlen(in) - (i + 1)));
			}
		}
		if (minus == 1) arr[k] = (-1) * arr[k];
		k++;
	} while (f == 0);
	for (int i = 0; i < k - 1; i++) cout << arr[i] << ' ';
	k = k - 2;
	cout << endl << k << endl;
	delete[] in;
	char op[255];
	char *deistv = new char[255];
	cout << "Input operations: " << endl;
	int opCount = 0;
	cin.getline(deistv, 255);
	for (int i = 0; i < strlen(deistv); i++) {
		if (deistv[i] == '+' || deistv[i] == '-' || deistv[i] == '/' || deistv[i] == '*') {
			op[opCount] = deistv[i];
			opCount++;
		}
		else continue;
	}
	for (int i = 0; i < 10; i++) cout << op[i] << ' ';
	cout << endl;
	delete[] deistv;
	int res = arr[0];
	for (int i = 0; i < k; i++) {
		switch (op[i]) {
		case '+': 
			res += arr[i+1];
			break;
		case '-':
			res -= arr[i+1];
			break;
		case '/':
			res /= arr[i+1];
			break;
		case '*':
			res *= arr[i+1];
			break;
		}
	}
	delete[] arr;
	cout << res;
	return 0;
}