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
		BSTree()   //构造函数
			: _root(nullptr)
		{}

		~BSTree()   //析构函数
		{
			Destroy(_root);
		}
		void Destroy(Node* root)    //需要递归后序遍历销毁
		{
			if (root == nullptr)  return;
			Destroy(root->_left);
			Destroy(root->_right);
			delete root;
		}

		BSTree(const BSTNode<K> &tree)   //拷贝构造
		{
			_root = Copy(tree._root);
		}
		BSTree<K> &operator =(const BSTree<K> &tree)    //赋值重载
		{
			if (this != &tree)
			{
				Destroy(_root);
				_root = Copy(tree._root);
			}
			return *this;
		}
		//BSTree<K> &operator=(const BSTree<K> tree) //将形参写成局部变量
		//{
		//	swap(_root, tree->_root);
		//	return *this;
		//}
		Node* Copy(Node* root)   //拷贝一棵树
		{
			if (root == nullptr)  return root;
			Node* newroot = new Node(root->_data);
			newroot->_left = Copy(root->_left);
			newroot->_right = Copy(root->_right);
			return newroot;
		}

		bool Insert(const K & val)    //插入
		{
			if (_root == nullptr)     //树为空时直接插入
			{
				_root = new Node(val);
				return true;
			}
			Node* cur = _root;    //树不空时，先确定位置再插入
			Node* parent = nullptr;
			while (cur)     //确定位置
			{
				parent = cur;
				if (val > cur->_data)   //val大于当前节点的值就向右找
					cur = cur->_right;
				else  if (val < cur->_data)    //val 小于当前节点的值就向左找
					cur = cur->_left;
				else         //val 等于当前节点的值，不允许插入
					return false;
			}
			cur = new Node(val);    //插入元素并与树连接
			if (val>(parent->_data))
				parent->_right = cur;
			else
				parent->_left = cur;
			return true;
		}

		Node* Find(const K& val)     //查找，其中：右树的值 > 根节点的值 > 左树的值
		{
			Node* cur = _root;
			while (cur)
			{
				if (val == cur->_data)
					return cur;       //找到返回当前结点
				else if (val > cur->_data)
					cur = cur->_right;
				else
					cur = cur->_left;
			}
			return nullptr;      //找不到返回空值
		}

		bool Erase(const K&val)     //删除
		{
			if (_root == nullptr)   return false;    //树为空，无法删除
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
			if (nullptr == cur)  return false;     //找不到，无法删除
			/* 找到以后要删除时由三种情况
			   1. 要删除的结点是叶子节点或只有左孩子，则将被删除结点的双亲节点指向被删除节点的左孩子
			   2. 要删除的结点只有右孩子，则将被删除结点的双亲节点指向被删除节点的这个孩子
			   3. 要删除的结点既有左孩子也有右孩子，则在被删除结点的左子树中找最右结点（或者在右子树中最左结点）与要删除的结点交换值，再删除替代结点。*/
			Node* del = cur;
			if (cur->_right == nullptr)   //1. 是叶子或只有左孩子
			{
				if (parent == nullptr)  _root = _root->_left;  //要删节点是根节点
				if (parent->_left == cur)
					parent->_left = cur->_left;
				else
					parent->_right = cur->_left;
			}
			else if (cur->_left == nullptr)      //2. 只有右孩子
			{
				if (parent == nullptr)  _root = _root->_right;  //要删节点是根节点
				if (parent->_left == cur)
					parent->_left = cur->_right;
				else
					parent->_right = cur->_right;
			}
			else                      //既有左孩子又有右孩子
			{
				Node* replace = cur->_right;     //用右树最左进行替代
				Node* pre = cur;         //替代节点的双亲节点，关键！！
				while (replace->_left)      //找到右树最左结点
				{
					pre = replace;
					replace = replace->_left;
				}
				cur->_data = replace->_data;
				if (pre->_left==replace)       //替代节点的双亲节点与它的下个结点连接
				pre->_left = replace->_right;   
				else pre->_right = replace->_right;
				del = replace;
			}
			delete del;
			return true;
		}

		void Print()    //按中序输出这颗有序树
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
		btree.Insert(1);    //插入
		btree.Insert(3);
		btree.Insert(5);
		btree.Insert(2);
		btree.Insert(4);
		btree.Insert(6);
		btree.Print();
		//BSTree<int> b2(btree);    //拷贝构造
		//b2.Print();
		//BSTree<int> b3;     
		//b3.Insert(3);
		//b3.Insert(4);
		//b3.Insert(1);
		//b3.Print();
		//b3 = btree;        //赋值重载
		//b3.Print();
		

		BSTNode<int>* p = btree.Find(5);  //查找5并输出结果
		if (p == nullptr)  cout<<"找不到!!"<<endl;
		else cout<<"找到了! "<<p->_data<<endl;
		btree.Erase(5);
		btree.Print();

	}
}

