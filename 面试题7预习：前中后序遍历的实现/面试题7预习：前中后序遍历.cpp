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
//先序遍历递归
void PreOrder(BiTNode* T) {
	if (T != nullptr) {
		cout << T->data << endl;
		//先打印左再打印右
		PreOrder(T->lchild);
		PreOrder(T->rchild);
	}
}
//先序遍历非递归
/*
基本思路：根节点入栈。栈顶元素打印并出栈后，将其右孩子入栈，再将左孩子入栈，保证右孩子永远在下，栈内无元素终止
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

//中序遍历递归
void InOrder(BiTNode* T) {
	if (T != nullptr) {
		InOrder(T->lchild);
		cout << T->data << endl;
		InOrder(T->rchild);
	}
}
//中序遍历非递归
/*
基本思路：p指向根节点，先一路走到左下角，将根节点与所有左孩子入栈，直到没有下一个左孩子，这个是第一个输出元素。输出并弹出后，栈顶元素p指向其右孩子。p为空且栈中没有节点时，遍历结束
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

//后序遍历递归
void PostOrder(BiTNode* T) {
	if (T != nullptr) {
		PostOrder(T->lchild);
		PostOrder(T->rchild);
		cout << T->data << endl;
	}
}

//后序遍历非递归
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
		p = m_stack.top();//当p=null时，切换到栈顶元素，即该子树上一节点
		if (p->rchild == nullptr || p->rchild == pre) {// 当该结点的右子树为空或右子树已被访问
			cout << p->data << endl;
			pre = p;
			m_stack.pop();
			p = nullptr;
		}
		else
			p = p->rchild;
	}
}