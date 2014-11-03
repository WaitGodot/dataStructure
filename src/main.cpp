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
	a.print();
	cout << a.front() <<"\t"<<a.back()<<"\n";
	a.remove_front();
	a.print();
	
	LOG("list test over!");
}
