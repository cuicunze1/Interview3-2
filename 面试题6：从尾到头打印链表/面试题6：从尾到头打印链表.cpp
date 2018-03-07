#include<cstdio>
#include<stack>
#include"list.h"

//ʹ��ջ����������
void PrintListReversingly_Iteratively(ListNode*pHead) {
	std::stack<ListNode*> Stack;
	ListNode* pNode = pHead;
	//����Ԫ��ѹջ
	while (pNode != nullptr) {
		Stack.push(pNode);
		pNode = pNode->next;
	}
	//��ջ����ӡ
	while (!Stack.empty()) {
		pNode = Stack.top();
		printf("%d\t", pNode->value);
		Stack.pop();
	}
}

//ʹ�õݹ�
void PrintListReversingly_Recursively(ListNode* pHead) {
	ListNode* pNode = pHead;
	if (pNode != nullptr) {
		if (pNode->next != nullptr)
			PrintListReversingly_Recursively(pNode->next);
		printf("%d\t", pNode->value);
	}
}

// ====================���Դ���====================
void Test(ListNode* pHead)
{
	PrintList(pHead);
	PrintListReversingly_Iteratively(pHead);
	printf("\n");
	PrintListReversingly_Recursively(pHead);
}

// 1->2->3->4->5
void Test1()
{
	printf("\nTest1 begins.\n");

	ListNode* pNode1 = CreateListNode(1);
	ListNode* pNode2 = CreateListNode(2);
	ListNode* pNode3 = CreateListNode(3);
	ListNode* pNode4 = CreateListNode(4);
	ListNode* pNode5 = CreateListNode(5);

	ConnectListNodes(pNode1, pNode2);
	ConnectListNodes(pNode2, pNode3);
	ConnectListNodes(pNode3, pNode4);
	ConnectListNodes(pNode4, pNode5);

	Test(pNode1);

	DestroyList(pNode1);
}

// ֻ��һ����������: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// ������
void Test3()
{
	printf("\nTest3 begins.\n");

	Test(nullptr);
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}