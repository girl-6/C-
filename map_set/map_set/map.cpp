#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#include<string>
#include<iostream>
#include<map>
#include <functional>
#include<vector>
using namespace std;

//��ֵ��
//template<class K, class V>
//struct pair
//{
//	typedef K first_type;
//	typedef V second_type;
//
//	K first;
//	V second;
//	pair()
//		:first(K())
//		, second(V())
//	{}
//
//	pair(const K& a, const V&b)
//		: first(a)
//		, second(b)
//	{}
//};

//make_pair �Ǻ���ģ�壬����pair������ֱ���Ƴ���������
//template<class K, class V>
//pair<K, V> make_pair(const K&k, const V&v)
//{
//	return pair<K, V>(k, v);
//}


	//map ��ʹ��--�ֵ�
	void test_map()
	{
		map<string, string> m1;
		map<string, string>m2{ { "apple", "ƻ��" },
		{ "banan", "�㽶" }, { "orange", "����" } };
		cout << m2["apple"] << endl;     //ƻ��
		cout << m2["peach"] << endl;     //�մ�
		
		//������ʹ��
		map<string, string>::iterator it = m2.begin();
		while (it != m2.end())
		{
			cout << (*it).first << ":" << (*it).second << "  ";
			it++;
		}
		cout << endl;
	}

	//map ��operator[]
void TestMap() {    // ����һ���յ�map����ʱm��һ��Ԫ�ض�û��    
	map<string, string> m;

	/*    operator[]��ԭ���ǣ�      
	��<key, T()>����һ����ֵ�ԣ�Ȼ�����insert()�������ü�ֵ�Բ��뵽map��      
	���key�Ѿ����ڣ�����ʧ�ܣ�insert�������ظ�key����λ�õĵ�����      
	���key�����ڣ�����ɹ���insert���������²���Ԫ������λ�õĵ�����      
	operator[]������insert����ֵ��ֵ���е�value����    */   
	// ��<"apple", "">����map�У�����ɹ�������value�����ã�����ƻ������ֵ�������ý����    
	// ���޸���"apple"��Ӧ��value""Ϊ"ƻ��"    
	m["apple"] = "ƻ��";        
	// ��<"apple", "">����map�У�����ʧ�ܣ���<"apple", "ƻ��">�е�"ƻ��"����    
	cout << m["apple"] << endl;    
	cout << m.size() << endl;

	// ��banan����map�У��ú������쳣��    
	//m.at("banan"); 
} 

void TestMap2()
{
	map<string, string> m;

	// ��map�в���Ԫ�صķ�ʽ������ֵ��<"peach","����">����map�У���pairֱ���������ֵ�� 
	m.insert(pair<string, string>("peach", "����"));

	// ����ֵ��<"peach","����">����map�У���make_pair�����������ֵ�� 
	m.insert(make_pair("banan", "�㽶"));  

	// ����operator[]��map�в���Ԫ��   
	m["apple"] = "ƻ��";

	// key������ʱ���쳣    m.at("waterme") = "ˮ����";  

	//iterator insert�е�position ֻ�ǲο�λ��
	m.insert(m.find("banan"), make_pair("waterme", "ˮ����"));    

	cout << m.size() << endl;    //4

	// �õ�����ȥ����map�е�Ԫ�أ����Եõ�һ������key���������    
	for (const auto& e : m)       
		cout << e.first << "��" << e.second << endl;    
	cout << endl;      //ƻ�����㽶�����ӣ�ˮ����

	// map�еļ�ֵ��keyһ����Ψһ�ģ����key���ڽ�����ʧ��    
	auto ret = m.insert(make_pair("peach", "��ɫ"));    
	if (ret.second)        
		cout << "<peach, ��ɫ>����map��, �ղ���" << endl;    
	else        
		cout << "keyΪpeach��Ԫ���Ѿ�����  " << ret.first->first << "��" << ret.first->second << endl;

	// ɾ��keyΪ"apple"��Ԫ��    
	m.erase("apple");    

	//count ���key��map�еĸ�����ֻ����1��0
	if (m.count("apple"))
		cout << "apple����" << endl;
	else
		cout << "apple��ɾ��" << endl;
	cout << "ʣ�µ�ˮ���� ->" << endl;
	for (auto& e : m)        
	cout << e.first << "��" << e.second << endl;
}


	//����multimap
void TestMultimap1() 
{
	multimap<string, string> m;
	m.insert(make_pair("����", "������"));
	m.insert(make_pair("�ֳ�", "����ͷ"));
	m.insert(make_pair("³��", "������"));
	//���Բ���key��ͬ��ֵ
	m.insert(make_pair("����", "��ţ")); 
	cout << m.size() << endl;    //4

	for (auto& e : m)    
		cout << "<" << e.first << "��" << e.second << endl;

	// keyΪ���ӵ�Ԫ���ж��ٸ�    
	cout << m.count("����") << endl;        //2 
}
void TestMultimap2() 
{
	multimap<int, int> m; 
	for (int i = 0; i < 10; ++i)    
		m.insert(pair<int, int>(i, i));

	for (auto& e : m)    
		cout << e.first << "��" << e.second << endl; 
	cout << endl;

	// ����m�д��ڵ���5�ĵ�һ��Ԫ�� 
	auto it = m.lower_bound(5); 
	cout << it->first << "��" << it->second << endl;

	// ����m�д���5�ĵ�һ��Ԫ�� 
	it = m.upper_bound(5); 
	cout << it->first << "��" << it->second << endl; 
} 

	int main()
	{
		//test_map();
		//TestMap();
		//TestMap2();
		//TestMultimap1();
		TestMultimap2();
		system("pause");
		return 0;
	}