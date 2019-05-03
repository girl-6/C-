#define _CRT_SECURE_NO_WARNINGS 1

#pragma once

#include <stdlib.h>
#include <iostream>
#include <assert.h>
using namespace std;

namespace LY
{
	template <class K, class V>
	struct AVLTreeNode
	{
		AVLTreeNode(const pair<K,V>&kv)
		:_left(nullptr)
		, _right(nullptr)
		, _parent(nullptr)
		, _kv(kv)
		, _bf(0)
		{}

		AVLTreeNode<K, V>* _left;   //该节点的左孩子
		AVLTreeNode<K, V>* _right;   //该节点的右孩子
		AVLTreeNode<K, V>* _parent;   //该节点的双亲
		pair<K, V> _kv;          //该节点中的值
		int _bf;          //该节点的平衡因子
	};

	template <class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:	
		AVLTree()    //构造函数
			:_root(nullptr)
		{}

		void Destory(Node* root)    //递归销毁
		{
			if (root == nullptr)  return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		} 
		~AVLTree()       //析构函数
		{
			Destroy(_root);
		}

		bool Insert(const pair<K, V>&kv)  //按二叉搜索树插入再更新平衡因子
		{
			if (_root == nullptr)
			{
				_root = new Node(kv);
				return true;
			}
			Node* cur = _root;
			Node* parent = nullptr;
			while (cur)
			{
				parent = cur;
				if (kv.first > cur->_kv.first)  //大于插入右边
					cur = cur->_right;
				else if (kv.first < cur->_kv.first)  //大于插入右边
					cur = cur->_left;
				else                    //不允许重复插入
					return false;
			}
			//找到了插入的位置，插入结点
			cur = new Node(kv);
			if (kv.first < parent->_kv.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			//插入成功后，更新平衡因子:插入左侧bf -1，插入右侧 bf +1
			//更新后要检测是否平衡，不平衡时要做旋转调整至平衡
			while (parent)
			{
				if (parent->_left == cur)
					parent->_bf--;
				else
					parent->_bf++;
				if (parent->_bf == 0)  break;     //bf==0 插入成功
				else if (parent->_bf == 1 || parent->_bf == -1)  //|bf|==1  继续更新
				{
					cur = parent;
					parent = cur->_parent;
				}
				else if       //|bf|==2  做旋转调整       
				{
					//旋转

				}
				else
					assert(false);
			}
			return true;
		}

		//左单旋
		void RotateL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;
			Node* pp = parent->_parent;
			parent->_right = subRL;
			if (subRL)
				subRL->_parent = parent;
			subR->_left = parent;
			parent->_parent = subR;
			if (parent == _root)
			{
				_root = subR;
				subR->_parent = nullptr;
			}
			else
			{
				if (pparent->_left == parent)
				{
					pparent->_left = subR;
					subR->_parent = pparent;
				}
				else
				{
					pparent->_right = subR;
					subR->_parent = pparent;
				}
			}
			parent->_bf = subR->_bf = 0;
		}
		//右单旋
		void RotateR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;
			parent->_left = subLR;
			if (subLR)
				subLR->_parent = parent;
			subL->_right = parent;
			Node* pp = parent->_parent;
			parent->_parent = subL;
			if (parent == _root)
			{
				_root = subL;
				subL->_parent = nullptr;
			}
			else
			{
				if (pp->_left == parent)
				{
					pp->_left = subL;
					subL->_parent = pp;
				}
				else
				{
					pp->_right = subL;
					subL->_parent = pp;
				}
			}
			subL->_bf = parent->_bf = 0;
		}

		//左右双旋
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int bf = subLR->_bf;
			RotateL(subL);//先左单旋
			RotateR(parent);//再右单旋

			if (bf == 0)
			{
				parent->_bf = subL->_bf = subLR->_bf = 0;
			}
			else if (bf == 1)
			{
				parent->_bf = 0;
				subL->_bf = -1;
				subLR->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 1;
				subL->_bf = 0;
				subLR->_bf = 0;
			}
			else
				assert(false);
		}

		//右左双旋
		void RotateRL(Node* parent)
		{
			Node* subR = parent->_right;
			Node* subRL = subR->_left;

			int bf = subRL->_bf;
			RotateR(subR);
			RotateL(parent);

			if (bf == 0)
				parent->_bf = subR->_bf = subRL->_bf = 0;
			else if (bf == 1)
			{
				parent->_bf = -1;
				subR->_bf = 0;
				subRL->_bf = 0;
			}
			else if (bf == -1)
			{
				parent->_bf = 0;
				subR->_bf = 1;
				subRL->_bf = 0;
			}
			else
				assert(false);
		}

	private:
		Node* _root;
	};
}



