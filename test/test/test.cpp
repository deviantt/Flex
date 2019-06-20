#include "pch.h"
#include <iostream>

using namespace std;

template<class T>
class List
{
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
					//tmp = head;
					//tmp->obj = head->obj;
					//tmp->prior = head->prior;
					//while (tmp!=last) {
					//	if (prior >= tmp->next->prior) {
					//		tmp->next = new Elem;
					//		tmp->next->obj = val;
					//		tmp->next->prior = prior;
					//		break;
					//	}
					//	tmp = tmp->next;
					//}
					for (tmp = head; tmp != last; tmp = tmp->next) {
							if (prior >= tmp->next->prior) {
								//tmp1 = tmp;
								tmp->next = new Elem;
								tmp->next->obj = val;
								tmp->next->prior = prior;

								break;
							}
							if (f = 1) break;
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
	List<int> list;
	list.Add(2,2);
	list.Add(4,4);
	list.Add(5,5);
	list.Add(1,1);
	list.Add(3, 3);
	//54321 output
	for (list.begin(); !list.isEnd(); list.next())
	{
		cout << list.getCurrent() << ' ';
	}
	cout << endl;
	list.show();
}