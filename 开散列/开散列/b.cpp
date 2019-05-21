#define _CRT_SECURE_NO_WARNINGS 1
#include <stdlib.h>
#pragma once

//开散列解决哈希冲突，哈希桶、拉链法
#include <iostream>
#include <vector>
using namespace std;

template<class V>
struct HashNode     //定义结点，包括自己的值及下一个值的指针
{
	//由于哈希桶要封装成unordered_map/set，因此这里可能存储pair<K,V>也可能存value
	V _valuefiled;
	HashNode<V>* _next;    //同一哈希桶中指向下一个节点的指针

	HashNode(const V& v)
		:_valuefiled(v)
		, _next(nullptr)
	{}
};

//通过仿函数实现对unordered系列容器中key的比较
template<class K, class V, class KeyOfValue>
class HashTable     //定义哈希表
{
	typedef HashNode<V> Node;
	typedef HashTable<K, V, KeyOfValue> HashTable;
public:
	HashTable()
		:_size(0)
	{}

	bool insert(const V& v)
	{
		CheckCapacity();       //考虑增容
		KeyOfValue kov;
		const K& key = kov(v);         //通过仿函数获取关键字
		size_t index = key % _table.size();     //通过哈希函数计算所属桶

		Node* cur = _table[index];
		while (cur)
		{
			if (kov(cur->_valuefiled) == key)  //已经存在待插入元素
				return false;
			cur = cur->_next;
		}
		//不存在且哈希桶不要求产生冲突的序列有序,可以用头插提高效率
		Node* newnode = new Node(v);
		newnode->_next = _table[index];
		_table[index] = newnode;

		++_size;
		return true;
	}

	void CheckCapacity()
	{
		//当负载因子==1时扩容
		if (_table.size() == _size)
		{
			size_t newsize = _table.size() == 0 ? 10 : _table.size() * 2;
			//这里不像之前开散列一样创建一个新的哈希表
			//再调用Insert的原因是旧表的节点可以直接拿到新的vector数组中进行插入
			vector<Node*> newtable;
			newtable.resize(newsize);

			//遍历旧表，在新的vector数组中找到对应位置，将旧表节点插入
			for (size_t i = 0; i < _table.size(); ++i)
			{
				Node* cur = _table[index];
				//将节点从旧表中拆出来，再重新计算节点在新表中的位置进行插入
				while (cur)
				{
					Node* next = cur->_next;
					size_t index = KeyOfValue()(cur->_valuefiled) % newsize;

					//头插入新表中
					cur->_next = newtable[index];
					newtable[index] = cur;

					cur = next;
				}
				//将原来的表置空
				_table[i] = nullptr;
			}
			//交换新旧两标的资源，出作用域后新表自动调用析构函数释放旧表资源
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
		Node* prev = nullptr;   //待删元素的前一个节点

		while (cur)
		{
			if (KeyOfValue()(cur->_valuefiled) == key)
			{
				if (prev == nullptr)    //若是第一个节点则修改_table[index] 的值
					_table[index] = cur->_next;
				else      //否则将前一个节点的next修改为cur的next
					prev->_next = cur->_next;
				delete cur;     //删除节点
				--_size;
				return true;
			}
		}
		return false;    //不存在则直接返回
	}

private:
	vector<Node*> _table;//vector中的size为哈希表的大小
	size_t _size;//哈希表中存储的有效元素的个数
};

