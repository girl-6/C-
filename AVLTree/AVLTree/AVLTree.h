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

		AVLTreeNode<K, V>* _left;   //�ýڵ������
		AVLTreeNode<K, V>* _right;   //�ýڵ���Һ���
		AVLTreeNode<K, V>* _parent;   //�ýڵ��˫��
		pair<K, V> _kv;          //�ýڵ��е�ֵ
		int _bf;          //�ýڵ��ƽ������
	};

	template <class K,class V>
	class AVLTree
	{
		typedef AVLTreeNode<K, V> Node;
	public:	
		AVLTree()    //���캯��
			:_root(nullptr)
		{}

		void Destory(Node* root)    //�ݹ�����
		{
			if (root == nullptr)  return;
			Destory(root->_left);
			Destory(root->_right);
			delete root;
		} 
		~AVLTree()       //��������
		{
			Destroy(_root);
		}

		bool Insert(const pair<K, V>&kv)  //�����������������ٸ���ƽ������
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
				if (kv.first > cur->_kv.first)  //���ڲ����ұ�
					cur = cur->_right;
				else if (kv.first < cur->_kv.first)  //���ڲ����ұ�
					cur = cur->_left;
				else                    //�������ظ�����
					return false;
			}
			//�ҵ��˲����λ�ã�������
			cur = new Node(kv);
			if (kv.first < parent->_kv.first)
				parent->_left = cur;
			else
				parent->_right = cur;
			//����ɹ��󣬸���ƽ������:�������bf -1�������Ҳ� bf +1
			//���º�Ҫ����Ƿ�ƽ�⣬��ƽ��ʱҪ����ת������ƽ��
			while (parent)
			{
				if (parent->_left == cur)
					parent->_bf--;
				else
					parent->_bf++;
				if (parent->_bf == 0)  break;     //bf==0 ����ɹ�
				else if (parent->_bf == 1 || parent->_bf == -1)  //|bf|==1  ��������
				{
					cur = parent;
					parent = cur->_parent;
				}
				else if       //|bf|==2  ����ת����       
				{
					//��ת

				}
				else
					assert(false);
			}
			return true;
		}

		//����
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
		//�ҵ���
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

		//����˫��
		void RotateLR(Node* parent)
		{
			Node* subL = parent->_left;
			Node* subLR = subL->_right;

			int bf = subLR->_bf;
			RotateL(subL);//������
			RotateR(parent);//���ҵ���

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

		//����˫��
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



