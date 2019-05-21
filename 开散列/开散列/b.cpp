#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#pragma once

//��ɢ�н����ϣ��ͻ����ϣͰ��������
#include <iostream>
#include <vector>
using namespace std;

template<class V>
struct HashNode     //�����㣬�����Լ���ֵ����һ��ֵ��ָ��
{
	//���ڹ�ϣͰҪ��װ��unordered_map/set�����������ܴ洢pair<K,V>Ҳ���ܴ�value
	V _valuefiled;
	HashNode<V>* _next;    //ͬһ��ϣͰ��ָ����һ���ڵ��ָ��

	HashNode(const V& v)
		:_valuefiled(v)
		, _next(nullptr)
	{}
};

//ͨ���º���ʵ�ֶ�unorderedϵ��������key�ıȽ�
template<class K, class V, class KeyOfValue>
class HashTable     //�����ϣ��
{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KeyOfValue> HashTable;
public:
	HashTable()
		:_size(0)
	{}

	bool insert(const V& v)
	{
		CheckCapacity();       //��������
		KeyOfValue kov;
		const K& key = kov(v);         //ͨ���º�����ȡ�ؼ���
		size_t index = key % _table.size();     //ͨ����ϣ������������Ͱ

		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_valuefiled) == key)  //�Ѿ����ڴ�����Ԫ��
				return false;
			cur = cur->_next;
		}
		//�������ҹ�ϣͰ��Ҫ�������ͻ����������,������ͷ�����Ч��
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;

		++_size;
		return true;
	}

	void CheckCapacity()
	{
		//����������==1ʱ����
		if (_table.size() == _size)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//���ﲻ��֮ǰ��ɢ��һ������һ���µĹ�ϣ��
			//�ٵ���Insert��ԭ���Ǿɱ�Ľڵ����ֱ���õ��µ�vector�����н��в���
			vector<Node*> newtable;
			newtable.resize(newsize);

			//�����ɱ����µ�vector�������ҵ���Ӧλ�ã����ɱ�ڵ����
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[index];
				//���ڵ�Ӿɱ��в�����������¼���ڵ����±��е�λ�ý��в���
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = KeyOfValue()(cur->_valuefiled) % newsize;

					//ͷ�����±���
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = next;
				}
				//��ԭ���ı��ÿ�
				_table[i] = nullptr;
			}
			//�����¾��������Դ������������±��Զ��������������ͷžɱ���Դ
			_table.swap(newtable);
		}
	}

	Node* Find(const K& key)
	{
		size_t index = key % _table.size();
		Node* cur = _table[index];
		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
				return cur;

			cur = cur->_next;
		}
		return nullptr;
	}

	bool Erase(const K& key)
	{
		size_t index = key % _table.size();
		Node* cur = _table[index];
		Node* prev = nullptr;   //��ɾԪ�ص�ǰһ���ڵ�

		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
			{
				if (prev == nullptr)    //���ǵ�һ���ڵ����޸�_table[index] ��ֵ
					_table[index] = cur->_next;
				else      //����ǰһ���ڵ��next�޸�Ϊcur��next
					prev->_next = cur->_next;
				delete cur;     //ɾ���ڵ�
				--_size;
				return true;
			}
		}
		return false;    //��������ֱ�ӷ���
	}

private:
	vector<Node*> _table;//vector�е�sizeΪ��ϣ��Ĵ�С
	size_t _size;//��ϣ���д洢����ЧԪ�صĸ���
};

