#include <iostream>
#include <string>
using namespace std;

class Student;

class Person
{
public:
	friend void Display(const Person& p, const Student &s);
protected:
	string _name;
};
class Student :public Person
{
protected:
	int _stuNum;
};
void Display(const Person& p, const Student& s)
{
	cout << p._name << endl;
	//cout << s._stuNum << endl;    //���뱨����Ϊ��Ԫ��ϵ�޷��̳�
}

int main()
{
	Person p;
	Student s;
	Display(p, s);
	system("pause");
	return 0;
}