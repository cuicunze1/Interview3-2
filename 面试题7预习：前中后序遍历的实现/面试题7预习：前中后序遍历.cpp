#include<cstdio>
#include<string>  
#include<iostream>
#include<stack>  
using namespace std;

const int MAX_N = 100;
typedef struct BiTNode {
	char data;
	int lvisited, rvisited;
	BiTNode* lchild;
	BiTNode* rchild;
};
//��������ݹ�
void PreOrder(BiTNode* T) {
	if (T != nullptr) {
		cout << T->data << endl;
		//�ȴ�ӡ���ٴ�ӡ��
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//��������ǵݹ�
/*
����˼·�����ڵ���ջ��ջ��Ԫ�ش�ӡ����ջ�󣬽����Һ�����ջ���ٽ�������ջ����֤�Һ�����Զ���£�ջ����Ԫ����ֹ
*/
void SqlPreOrder(BiTNode* T) {
	if (T == nullptr)
		return;
	stack <BiTNode*> m_stack;
	m_stack.push(T);
	while (!m_stack.empty()) {
		BiTNode* p = m_stack.top();
		cout << T->data << endl;
		m_stack.pop();
		if (p->rchild)
			m_stack.push(p->rchild);
		if (p->lchild)
			m_stack.push(p->lchild);
	}
}

//��������ݹ�
void InOrder(BiTNode* T) {
	if (T != nullptr) {
		InOrder(T->lchild);
		cout << T->data << endl;
		InOrder(T->rchild);
	}
}
//��������ǵݹ�
/*
����˼·��pָ����ڵ㣬��һ·�ߵ����½ǣ������ڵ�������������ջ��ֱ��û����һ�����ӣ�����ǵ�һ�����Ԫ�ء������������ջ��Ԫ��pָ�����Һ��ӡ�pΪ����ջ��û�нڵ�ʱ����������
*/
void SqlInOrder(BiTNode* T) {
	if (T == nullptr)
		return;
	std::stack <BiTNode*> m_stack;
	BiTNode* p = T;
	while (p != nullptr || !m_stack.empty()) {
		while (p != nullptr) {
			m_stack.push(p);
			p = p->lchild;
		}
		if (!m_stack.empty()) {
			p = m_stack.top();
			cout << p->data << endl;
			m_stack.pop();
			p = p->rchild;
		}
	}
}

//��������ݹ�
void PostOrder(BiTNode* T) {
	if (T != nullptr) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << endl;
	}
}

//��������ǵݹ�
void SqlPostOrder(BiTNode* T) {
	if (T == nullptr)
		return;
	BiTNode* pre = nullptr;
	BiTNode* p = T;
	std::stack<BiTNode*> m_stack;
	while (p != nullptr || !m_stack.empty()) {
		while (p != nullptr) {
			m_stack.push(p);
			p = p->lchild;
		}
		p = m_stack.top();//��p=nullʱ���л���ջ��Ԫ�أ�����������һ�ڵ�
		if (p->rchild == nullptr || p->rchild == pre) {// ���ý���������Ϊ�ջ��������ѱ�����
			cout << p->data << endl;
			pre = p;
			m_stack.pop();
			p = nullptr;
		}
		else
			p = p->rchild;
	}
}