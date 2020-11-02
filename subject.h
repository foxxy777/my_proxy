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
		cout << "current time:" << str_time;//c_time֮���Դ��˻��У�������<<endl;��
	}
};

// ������
class Proxy :public Subject
{
private:
	RealSubject* realSubject;
	Record* record;
public:
	Proxy() {
		realSubject = new RealSubject();//��proxy�Ĺ��캯�����湹��realSubject��Record
		record = new Record();
	}
	void create_method_in_proxy() {
		record->getTime();//��proxy�й���realSubjectǰ��ʹ��record���getTime��¼ʱ��
		realSubject->create_method_in_RealSubject();
		record->getTime();
	}

};



