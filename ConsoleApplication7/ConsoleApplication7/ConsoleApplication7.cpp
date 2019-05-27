#include "pch.h"
#include <iostream>
#include <string.h>
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
		return " рублей";
	}
	else {
		if (a / 100 % 10 == 0) return " рублей ";
		if (a / 100 % 10 == 1) return " рубль ";
		if (a / 100 % 10 >= 2 && a / 100 % 10 <= 4) return " рубля ";
		if (a / 100 % 10 >= 5 && a / 100 % 10 <= 9) return " рублей ";
	}
}

void rubkop(int a) {
	cout << a / 100 << rub(a) << a % 100 << kop(a);
}

class Product {
public:
	char* name = 0;
	unsigned int year = 0;
};
template<class T>
class List {
public:
	~List() {
		while (head != nullptr) {
			Node<T>* next = head->next;
			delete head;
			head = next;
		}
	}
	void addFirst(T book) {
		Node<T> *temp = new Node<T>;
		temp->data = book;
		temp->next = NULL;
		if (head == NULL) {
			head = temp;
			return;
		}
		temp->next = head;
		head = temp;
	}
	void getNode() {

	}
	void print() {
		Node<T> *temp = head;
		while (temp != nullptr) {
			cout << temp->data.name << ": ";
			rubkop(temp->data.year);
			cout << endl;
			temp = temp->next;
		}
	}
private:
	template<class T>
	class Node {
	public:
		T data;
		Node* next;
	};
	Node<T>* head = nullptr;
};


int main()
{
	setlocale(LC_ALL, "Russian");
	int sum = 0, n = 0;
	cout << "Введите количество покупок: ";
	cin >> n;
	List<Product> list;
	for (int i = 0; i < n; i++) {
		Product book;

		char* in = new char[10];
		cout << "Product " << i << ". Name: ";
		cin >> in;

		book.name = new char[strlen(in) + 1];
		strcpy_s(book.name, 11, in);
		book.name[strlen(in)] = '\0';
		cout << "Product " << i << ". Cost: ";
		cin >> book.year;
		sum += book.year;

		list.addFirst(book);
	}
	cout << endl;
	list.print();
	cout << "SUM: ";
	rubkop(sum);
	cout << endl << endl << endl;
	return 0;
}