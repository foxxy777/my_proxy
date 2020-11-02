#pragma once

#include <time.h>
using namespace std;

class Subject
{
public:
	Subject() {};
};

class RealSubject :public Subject
{
public:
	RealSubject() {}
	void create_method_in_RealSubject() {
		cout << "call func() in RealSubject" << endl;
	}
};

class Record
{
public:
	Record() {}
	void getTime() {
		time_t now = time(0);
		char* str_time = ctime(&now);
		cout << "current time:" << str_time;//c_time之后自带了换行，不用再<<endl;了
	}
};

// 代理类
class Proxy :public Subject
{
private:
	RealSubject* realSubject;
	Record* record;
public:
	Proxy() {
		realSubject = new RealSubject();//在proxy的构造函数里面构造realSubject和Record
		record = new Record();
	}
	void create_method_in_proxy() {
		record->getTime();//在proxy中构造realSubject前后使用record类的getTime记录时间
		realSubject->create_method_in_RealSubject();
		record->getTime();
	}

};



