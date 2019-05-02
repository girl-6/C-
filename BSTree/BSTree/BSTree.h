#define _CRT_SECURE_NO_WARNINGS 1
# pragma once
#include <stdlib.h>
#include <iostream>
using namespace std;

namespace LY
{
	template<class K>
	struct BSTNode
	{
		BSTNode(const K&data = K())
		:_left(nullptr)
		, _right(nullptr)
		, _data(data)
		{}
		BSTNode<K>* _left;
		BSTNode<K>* _right;
		K _data;
	};
	template<class K>
	class BSTree
	{
		typedef BSTNode<K> Node;
	public:
		BSTree()   //���캯��
			: _root(nullptr)
		{}

		~BSTree()   //��������
		{
			Destroy(_root);
		}
		void Destroy(Node* root)    //��Ҫ�ݹ�����������
		{
			if (root == nullptr)  return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

		BSTree(const BSTNode<K> &tree)   //��������
		{
			_root = Copy(tree._root);
		}
		BSTree<K> &operator =(const BSTree<K> &tree)    //��ֵ����
		{
			if (this != &tree)
			{
				Destroy(_root);
				_root = Copy(tree._root);
			}
			return *this;
		}
		//BSTree<K> &operator=(const BSTree<K> tree) //���β�д�ɾֲ�����
		//{
		//	swap(_root, tree->_root);
		//	return *this;
		//}
		Node* Copy(Node* root)   //����һ����
		{
			if (root == nullptr)  return root;
			Node* newroot = new Node(root->_data);
			newroot->_left = Copy(root->_left);
			newroot->_right = Copy(root->_right);
			return newroot;
		}

		bool Insert(const K & val)    //����
		{
			if (_root == nullptr)     //��Ϊ��ʱֱ�Ӳ���
			{
				_root = new Node(val);
				return true;
			}
			Node* cur = _root;    //������ʱ����ȷ��λ���ٲ���
			Node* parent = nullptr;
			while (cur)     //ȷ��λ��
			{
				parent = cur;
				if (val > cur->_data)   //val���ڵ�ǰ�ڵ��ֵ��������
					cur = cur->_right;
				else  if (val < cur->_data)    //val С�ڵ�ǰ�ڵ��ֵ��������
					cur = cur->_left;
				else         //val ���ڵ�ǰ�ڵ��ֵ�����������
					return false;
			}
			cur = new Node(val);    //����Ԫ�ز���������
			if (val>(parent->_data))
				parent->_right = cur;
			else
				parent->_left = cur;
			return true;
		}

		Node* Find(const K& val)     //���ң����У�������ֵ > ���ڵ��ֵ > ������ֵ
		{
			Node* cur = _root;
			while (cur)
			{
				if (val == cur->_data)
					return cur;       //�ҵ����ص�ǰ���
				else if (val > cur->_data)
					cur = cur->_right;
				else
					cur = cur->_left;
			}
			return nullptr;      //�Ҳ������ؿ�ֵ
		}

		bool Erase(const K&val)     //ɾ��
		{
			if (_root == nullptr)   return false;    //��Ϊ�գ��޷�ɾ��
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				if (val == cur->_data)
					break;
				else if (val < cur->_data)
				{
					parent = cur;
					cur = cur->_left;
				}
				else 
				{
					parent = cur;
					cur = cur->_right;
				}
			}
			if (nullptr == cur)  return false;     //�Ҳ������޷�ɾ��
			/* �ҵ��Ժ�Ҫɾ��ʱ���������
			   1. Ҫɾ���Ľ����Ҷ�ӽڵ��ֻ�����ӣ��򽫱�ɾ������˫�׽ڵ�ָ��ɾ���ڵ������
			   2. Ҫɾ���Ľ��ֻ���Һ��ӣ��򽫱�ɾ������˫�׽ڵ�ָ��ɾ���ڵ���������
			   3. Ҫɾ���Ľ���������Ҳ���Һ��ӣ����ڱ�ɾ�������������������ҽ�㣨�������������������㣩��Ҫɾ���Ľ�㽻��ֵ����ɾ�������㡣*/
			Node* del = cur;
			if (cur->_right == nullptr)   //1. ��Ҷ�ӻ�ֻ������
			{
				if (parent == nullptr)  _root = _root->_left;  //Ҫɾ�ڵ��Ǹ��ڵ�
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else if (cur->_left == nullptr)      //2. ֻ���Һ���
			{
				if (parent == nullptr)  _root = _root->_right;  //Ҫɾ�ڵ��Ǹ��ڵ�
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else                      //�������������Һ���
			{
				Node* replace = cur->_right;     //����������������
				Node* pre = cur;         //����ڵ��˫�׽ڵ㣬�ؼ�����
				while (replace->_left)      //�ҵ�����������
				{
					pre = replace;
					replace = replace->_left;
				}
				cur->_data = replace->_data;
				if (pre->_left==replace)       //����ڵ��˫�׽ڵ��������¸��������
				pre->_left = replace->_right;   
				else pre->_right = replace->_right;
				del = replace;
			}
			delete del;
			return true;
		}

		void Print()    //������������������
		{
			Inorder(_root);
			cout << endl;
		}
		void Inorder(Node* root)
		{
			if (root)
			{
				Inorder(root->_left);
				cout << root->_data << "  ";
				Inorder(root->_right);
			}
		}
	private:
		Node* _root;
	};

	void TestBST()
	{
		BSTree<int> btree;
		btree.Insert(1);    //����
		btree.Insert(3);
		btree.Insert(5);
		btree.Insert(2);
		btree.Insert(4);
		btree.Insert(6);
		btree.Print();
		//BSTree<int> b2(btree);    //��������
		//b2.Print();
		//BSTree<int> b3;     
		//b3.Insert(3);
		//b3.Insert(4);
		//b3.Insert(1);
		//b3.Print();
		//b3 = btree;        //��ֵ����
		//b3.Print();
		

		BSTNode<int>* p = btree.Find(5);  //����5��������
		if (p == nullptr)  cout<<"�Ҳ���!!"<<endl;
		else cout<<"�ҵ���! "<<p->_data<<endl;
		btree.Erase(5);
		btree.Print();

	}
}

