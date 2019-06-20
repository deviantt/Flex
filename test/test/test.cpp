#include "pch.h"
#include <iostream>

using namespace std;

template<class T>
class List
{
	struct ListElem
	{
		T obj;
		ListElem* next;
		unsigned int pr;
	};
	//ListElem* head1;
	ListElem* head;
	ListElem* last;
	ListElem* iterator;
public:
	List() : head(nullptr)
	{}
	void Add(T elem, unsigned int pr)
	{
		if (head == nullptr)
		{
			head = new ListElem;
			head->obj = elem;
			head->pr = pr;
			head->next = nullptr;
			last = head;
		}
		else
		{
			//head1 = head;
			//	while (head1 != last) {
			//		if (pr < head1->pr) {
			//			head1 = new ListElem;
			//			head1->obj = elem;
			//			head1->pr = pr;
			//		}
			//		head1 = head1->next;
			//	}
			if (pr > head->pr) {
				head = new ListElem;
				head->next = head;
				head->next->obj = head->obj;
				head->next->pr = head->pr;
				head->obj = elem;
				head->pr = pr;

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
		//cout << head->next->next->obj;
		cout << last->obj;
	}
};

int main()
{
	List<int> list;
	list.Add(1,1);
	//list.Add(2,2);
	list.Add(2,2);
	//list.Add(3,3);
	//list.Add(5,5);
	//for (list.begin(); !list.isEnd(); list.next())
	//{
	//	cout << list.getCurrent() << ' ';
	//}
	//cout << endl;
	list.show();
	//53124
}