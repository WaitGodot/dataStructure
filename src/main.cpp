#include <iostream>
#include "macroConfig.h"
#include "array.h"
#include "list.h"

using namespace std;
using namespace dataStructure;

static void array_test();
static void list_test();

int main()
{
	array_test();
	list_test();

	cout<<"c plus plus --> Hello World!\n";
	return 0;
}

void array_test()
{
	array<int> a;
	a.print();
	a.insert(10);
	a.print();
	a.insert(20);
	a.print();
	a.remove();
	a.print();
	a.remove(0);
	a.print();
	a.insert(30);
	a.insert(31);
	a.insert(32);
	a.insert(33);
	for(int i = 0 ; i < a.size(); i++)
	{
		cout << a[i] << "\t";
	}
	cout<< a.find(1);
	cout<< a.cfind(2);
	cout << a.size() << a.empty() << "\n";
	//cout << a.find(-1);
	
	a.insert(34);
	cout << a.find(5);
	cout << "array test over!\n";
}

void list_test()
{
	list<int> a;
	a.print();
	a.insert(20);
	a.print();
	a.insert(30);
	a.print();
	a.remove(30);
	a.print();
	a.insert(30);
	a.insert(31);
	a.insert(32);
	a.insert(33);
	a.insert(34);
	a.insert(35);
	a.print();
	LOG("iterator test!");
	a.remove(a.begin());
	cout << a.front() <<"\t"<<a.back()<<"\n";
	a.print();
	LOG("............................");
	a.remove_front();
	a.print();
	for(list<int>::iterator it = a.begin();it!=a.end();++it){
		cout<< (*it) << "\t";
	}
	LOG("list test over!");
}
