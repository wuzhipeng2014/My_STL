// STLTest.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
#include <vector>
#include "My_Iterator.h"

using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	vector<string> sv;
	sv.push_back("first");
	sv.push_back("second");
	sv.push_back("third");
	sv.push_back("fourth");
	auto iter = sv.begin();
	auto re= my_stl::value_type(iter);
	cout << typeid(re).name() << endl;
	return 0;
}

