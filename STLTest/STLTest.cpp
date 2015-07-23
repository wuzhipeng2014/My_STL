// STLTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include <list>
#include "My_Iterator.h"

using  std::string;
using std::vector;
using std::cout;
using std::endl;
using std::list;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> sv;
	sv.push_back("first");
	sv.push_back("second");
	sv.push_back("third");
	sv.push_back("fourth");
	list<int> il;
	il.push_back(1);
	il.push_back(2);
	il.push_back(3);

	auto iter_il = il.begin();
	
	auto iter = sv.begin();
	auto re= my_stl::value_type(iter);
	cout << typeid(re).name() << endl;
	auto type = my_stl::iterator_category(iter);
	cout << "iter的类型为：";
	cout << typeid(type).name() << endl;


	my_stl::advance(iter, 2);
	cout << *iter << endl;

	/*int * p;
	auto re1 = my_stl::value_type(p);
	cout << typeid(re1).name() << endl;

	cout << "输出迭代器的类型" << endl;
	 auto re3 = my_stl::iterator_category(iter);
	cout << typeid(re3).name() << endl;

	auto re4 = my_stl::iterator_category(iter_il);
	cout << typeid(re4).name() << endl;
*/

	return 0;
	
	
}

