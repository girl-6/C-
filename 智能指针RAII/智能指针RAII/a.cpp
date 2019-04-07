#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include <stdio.h>
#include <string >
#include<iostream>
using namespace std;


//	// ʹ��RAII˼����Ƶ�SmartPtr��
//template<class T> 
//class SmartPtr 
//{
//public:
//	SmartPtr(T* ptr = nullptr) 
//		: _ptr(ptr)    
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			cout << "~Smarptr" << endl;
//		}
///	}
//private:    
//	T* _ptr;
//};
//void MergeSort(int* a, int n)
//{
//	int* tmp = (int*)malloc(sizeof(int)*n);
//	SmartPtr<int> sp(tmp);      //����ָ���й�tmp��Դ
//	//��tmp�����ͷ������йܣ���tmpδ����ͷ�������ͷ�
//	throw "aaa";
//	free(tmp);
//}
//int main()
//{
//	try
//	{ 
//		int a[5] = { 4, 5, 2, 3, 1 };        
//		MergeSort(a, 5); 
//	}
//	catch (const exception&e)    
//	{
//		cout << e.what() << endl; 
//	}
//	system("pause");
//	return 0;
//}


  //����ָ���ԭ��RAII+ָ����Ϊ
//template<class T> 
//class SmartPtr
//{
//public:
//
//	SmartPtr(T* ptr = nullptr)
//		: _ptr(ptr)
//	{}
//	~SmartPtr()
//	{
//		if (_ptr)
//		{
//			delete _ptr;
//			cout << "~Smarptr" << endl;
//		}
//	}        
//	T& operator*() { return *_ptr; }
//	T* operator->() { return _ptr; }
//private:
//	T* _ptr;
//};
//struct Date 
//{
//	int _year;    
//	int _month;    
//	int _day;
//	void Display()
//	{
//		cout << _year << "-" << _month << "-" << _day << endl;
//	}
//};
//
//int main()
//{
//	SmartPtr<int> sp1(new int);
//    *sp1 = 10;     //sp1.operator*() = 10;
//    cout << *sp1 << endl;
//	SmartPtr<Date> sp2(new Date);
//	 //��Ҫע���������Ӧ����sp2.operator->()->_year = 2019;    
//	 //����Ӧ����sp2->->_year�����﷨��Ϊ�˿ɶ��ԣ�ʡ����һ��->   
//	sp2->_year = 2019;
//	sp2->_month = 1;
//	sp2->_day = 1;
//	sp2->Display();
//	system("pause");
//	return 0;
//}

// C++���е�����ָ�붼������memory���ͷ�ļ���
#include <memory>
class Date
{
public:
	Date() { cout << "Date()" << endl; }
	~Date(){ cout << "~Date()" << endl; }
	int _year;
	int _month;
	int _day;
};


// 1.C++98����ָ��auto_ptr��ģ��ʵ�֣�ת�ƹ���Ȩ
//namespace LY
//{
//	template<class T>
//	class AutoPtr//ģ��ʵ��auto_ptr
//	{
//	public:
//		AutoPtr(T* Ptr=NULL)
//			:_Ptr(Ptr)
//		{}
//		~AutoPtr()
//		{
//			if (_Ptr)
//			{
//				cout << "delete:" << _Ptr << endl;
//				delete _Ptr;
//			}
//		}
//		// LY::AutoPtr<int> copy(ap);��������
//		AutoPtr(AutoPtr<T>& ap)
//			:_Ptr(ap._Ptr)
//		{
//			ap._Ptr = nullptr;
//		}
//		AutoPtr<T>& operator=(AutoPtr<T>&ap)    //��ֵ����
//		{
//			if (this != &ap)   //����Ƿ��Լ����Լ���ֵ
//			{
//				if (_Ptr)       //�ͷŵ�ǰ������Դ
//					delete _Ptr;
//				_Ptr = ap._Ptr;      //ת��ap����Դ����ǰ������
//				ap._Ptr = NULL;
//			}
//			return *this;
//		}
//		T& operator*() { return *_Ptr; }
//		T* operator->(){ return _Ptr; }
//	private:
//		T* _Ptr;
//	};
//}
//int main()
//{
//	LY::AutoPtr<Date> ap(new Date);
//	LY::AutoPtr<Date> copy(ap);
//	/*auto_ptr<Date> ap(new Date);
//	auto_ptr<Date> copy(ap);*/
//	//ap->_year = 2019;        //�������
//	copy->_year = 2019;      //��������
//	system("pause");
//	return 0;
//}


// 2.C++11 unique_ptrģ��ʵ�֣��򵥴ֱ��ķ�����
//namespace LY
//{
//	template<class T>
//	class UniquePtr
//	{
//	public:
//		UniquePtr(T* ptr)
//			:_Ptr(ptr)
//		{}
//
//		~UniquePtr()
//		{
//			cout << "deleteU:" << _Ptr << endl;
//			delete _Ptr;
//		}
//		T& operator*()     {	return *_Ptr; }
//		T* operator->()    {	return _Ptr;  }
//
//	private:
//		//C++98��������ʽ��ֻ������ʵ��+����Ϊ˽��
//		//��������Ϊ˽�У���������Ҳ�޷�ʵ�֣����ܷ�����
//		//ֻ���������޴���Ϊ�˷�ֹϵͳ����Ĭ�ϵĿ������캯��
//		/*UniquePtr(UniquePtr<T> const& );
//		UniquePtr&<T> operator=(UniquePtr<T> const&);*/
//
//		//C++11��������ʽ��=delete
//		UniquePtr(UniquePtr<T> const&) = delete;
//		UniquePtr&<T> operator=(UniquePtr<T> const&) = delete;
//		T* _Ptr;
//	};
//}
//int main()
//{
//	//unique_ptr<Date> ap(new Date);
//	//unique_ptr<Date> copy(ap);   //���벻ͨ��
//	LY::UniquePtr<Date> ap(new Date);
//	LY::UniquePtr<Date> copy(ap);   //���벻ͨ��
//	//ap->_year = 2019;   //��������
//	system("pause");
//	return 0;
//}


// 3.C++11 shared_ptr��ģ��ʵ�֣����ü�����֧�ֿ���������ʹ��
//namespace LY
//{
//	template <class T>
//	class SharedPtr
//	{
//	public:
//		SharedPtr(T* ptr)
//			:_Ptr(ptr)
//			, _pcount(new int(1))
//			, _pmtx(new mutex)//�����̰߳�ȫ���⣬��ֻ֤��һ���̶߳�pcount����++
//		{}
//		~SharedPtr()
//		{
//			/*if (--(*_pcount) == 0)
//			{
//			cout << "delete:" << _ptr << endl;
//			delete _ptr;
//			delete _pcount;
//			}*/
//			Release();
//		}
//
//		//LY::SharedPtr<int> copy(sp);
//		SharedPtr(SharedPtr<int> const& sp)
//			:_Ptr(sp._Ptr)
//			, _pcount(sp._pcount)
//			, _pmtx(sp._pmtx)
//		{
//			if (_Ptr)//����һ����ָ�����ü���
//				AddRefcount();
//		}
//
//		//sp = sp1
//		SharedPtr<int>& operator=(SharedPtr<int> const& sp)
//		{//�ȼ��sp�Ƿ������һ��ָ����Դ�Ķ�����������ͷ���Դ
//			if (_Ptr != sp._Ptr)//���������ͬ�Ķ���Ž��и�ֵ
//			{
//				Release();//�ͷ�ԭ���Ŀռ䣬ָ���µĿռ�
//
//				_Ptr = sp._Ptr;
//				_pcount = sp._pcount;
//				_pmtx = sp._pmtx;
//
//				AddRefcount();
//			}
//
//			return *this;
//		}
//
//		int AddRefcount()
//		{
//			//��֤��ԭ�Ӳ���
//			_pmtx->lock();
//			++(*_pcount);
//			_pmtx->unlock();
//
//			return *_pcount;
//		}
//
//		void Release()
//		{
//			bool deleteflag = false;
//			//���ü�����һ���������0�������һ��ʹ����Դ�Ķ��󣬾��ͷ���Դ
//			if (--(*_pcount) == 0)
//			{
//				cout << "deleteS:" << _Ptr << endl;
//				delete _Ptr;
//				delete _pcount;
//				deleteflag = true;
//			}
//			if (deleteflag == true)//��������һ������Ҳ������Դ�ͷ�
//				delete _pmtx;
//		}
//		T& operator*()   {	return *_Ptr;}
//		T* operator->()  {	return _Ptr; }
//		int use_count()  {	return *_pcount;}
//		T* Get() { return _Ptr; }
//	private:
//		T* _Ptr;    //ָ�������Դ��ָ��
//		int* _pcount;     // ���ü���
//		mutex* _pmtx;     //������
//	};
//}
//int main()
//{
//	LY::SharedPtr<int> sp1(new int(10));
//	LY::SharedPtr<int> sp2(sp1);
//	*sp2 = 20;
//	cout << sp1.LY::SharedPtr<int>::use_count<< endl;
//	cout << sp2.LY::SharedPtr<int>::use_count << endl;
//	system("pause");
//	return 0;
//}


		//�̰߳�ȫ����
//void SharePtrFunc(SharedPtr<Date>& sp, size_t n)
//{
//	cout << sp.Get() << endl;
//	for (size_t i = 0; i < n; ++i)
//	{
//		// ��������ָ�뿽����++����������ָ��������--�������������̰߳�ȫ�ġ�
//		//SharedPtr<Date> copy(sp);
//		// ��������ָ����ʹ������Դ�������̰߳�ȫ�ġ��������ǿ�����Щֵ�����߳�++��2n�Σ�������
//		//�տ����Ľ������һ���Ǽ���2n
//		copy->_year++;
//		copy->_month++;
//		copy->_day++;
//	}
//}
//int main()
//{
//	SharedPtr<Date> p(new Date);
//	cout << p.Get() << endl;
//
//	const size_t n = 100;
//	thread t1(SharePtrFunc, p, n);
//	thread t2(SharePtrFunc, p, n);
//	t1.join();
//	t2.join();
//	cout << p->_year << endl;
//	cout << p->_month << endl;
//	cout << p->_day << endl;
//	return 0;
//}


		//ѭ����������
//#include <iostream>
//#include <memory>
//using namespace std;
//
//struct ListNode
//{
//	int _data;
//	shared_ptr<ListNode> _prev;
//	shared_ptr<ListNode> _next;
//	~ListNode()
//	{
//		cout << "~ListNode()" << endl;
//	}
//};
//int main()
//{
//	shared_ptr<ListNode> node1(new ListNode);
//	shared_ptr<ListNode> node2(new ListNode);
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	node1->_next = node2;
//	node2->_prev = node1;
//	cout << node1.use_count() << endl;
//	cout << node2.use_count() << endl;
//	return 0;
//}

		//ѭ�����õĽ������
// ��������������ü����ĳ����£��ѽڵ��е�_prev��_next�ĳ�weak_ptr�Ϳ�����
// ԭ����ǣ�node1->_next = node2;��node2->_prev = node1;ʱweak_ptr��_next��_prev��������
//node1��node2�����ü�����

struct ListNode
{
	int _data;
	weak_ptr<ListNode> _prev;
	weak_ptr<ListNode> _next;
	~ListNode(){ cout << "~ListNode()" << endl; }
};
int main()
{
	shared_ptr<ListNode> node1(new ListNode);
	shared_ptr<ListNode> node2(new ListNode);
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	node1->_next = node2;
	node2->_prev = node1;
	cout << node1.use_count() << endl;
	cout << node2.use_count() << endl;
	return 0;
}
