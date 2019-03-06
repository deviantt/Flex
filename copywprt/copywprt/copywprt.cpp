#include "pch.h"
#include <iostream>

using namespace std;

int* copy(int* ptr, int n) {
	int* arr2 = new int[n];
	for (int i = 0; i < n; i++) {
		arr2[i] = ptr[i];
	}
	return arr2;
}

int main()
{
	int n;
	cin >> n;
	int* arr1 = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	int* ptr2 = copy(arr1, n);
	for (int i = 0; i < n; i++) {
		cout << ptr2[i];
	}
}