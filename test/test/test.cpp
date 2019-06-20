#include "pch.h"
#include <iostream>

using namespace std;

template<class T>
class List
{
private:
	struct Elem
	{
		T obj;
		Elem* next;
		unsigned int prior;
	};
	Elem* head1;
	Elem* tmp;
	Elem* tmp1;
	Elem* head;
	Elem* last;
	Elem* iterator;
public:
	List() : head(nullptr)
	{}
	void Add(T val, unsigned int prior)
	{
		if (head == nullptr)
		{
			head = new Elem;
			head->obj = val;
			head->prior = prior;
			head->next = nullptr;
			last = head;
		}
		else
		{
			head1 = head;
			if (prior > head->prior) {
				head = new Elem;
				head->next = head1;
				head->next->obj = head1->obj;
				head->next->prior = head1->prior;
				head->obj = val;
				head->prior = prior;
			}
			else {
				if (prior <= last->prior) {
					last->next = new Elem;
					last->next->obj = val;
					last->next->prior = prior;
					last->next->next = nullptr;
					last = last->next;
				}
				else {
					for (tmp = head; tmp != last; tmp = tmp->next) {
						if (prior >= tmp->next->prior) {
							tmp1 = new Elem;
							tmp1->next = tmp->next;
							tmp->next = tmp1;
							tmp1->obj = val;
							tmp1->prior = prior;
							break;
						}
					}
				}
			}
		}
	}
	void begin()
	{
		iterator = head;
	}
	void next()
	{
		iterator = iterator->next;
	}
	unsigned int showprior() {
		return iterator->prior;
	}
	T& getCurrent()
	{
		return iterator->obj;
	}
	bool isEnd()
	{
		return iterator == nullptr;
	}
	void show() {
		cout << head->obj;
		cout << head->next->obj;
		cout << last->obj;
		if (head->next == last) {
			cout << "  PEPEGA ";
		}
		cout << head1->obj << endl;
		//cout << tmp->obj;
	}
};

int main()
{
	int x;
	List<int> list;
	list.Add(2, 2);
	list.Add(4, 4);
	list.Add(1, 1);
	list.Add(3, 3);
	list.Add(5, 5);
	//for (int i = 0; i < 100; i++) {
	//	x = rand() % 1000;
	//	list.Add(x, x);
	//}
	//54321 output
	for (list.begin(); !list.isEnd(); list.next())
	{
		cout << list.getCurrent() << ' ' << list.showprior() << endl;
	}
}