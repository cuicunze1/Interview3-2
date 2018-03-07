#include<cstdio>
#include<stack>
#include"list.h"

//使用栈容器适配器
void PrintListReversingly_Iteratively(ListNode*pHead) {
	std::stack<ListNode*> Stack;
	ListNode* pNode = pHead;
	//所有元素压栈
	while (pNode != nullptr) {
		Stack.push(pNode);
		pNode = pNode->next;
	}
	//出栈并打印
	while (!Stack.empty()) {
		pNode = Stack.top();
		printf("%d\t", pNode->value);
		Stack.pop();
	}
}

//使用递归
void PrintListReversingly_Recursively(ListNode* pHead) {
	ListNode* pNode = pHead;
	if (pNode != nullptr) {
		if (pNode->next != nullptr)
			PrintListReversingly_Recursively(pNode->next);
		printf("%d\t", pNode->value);
	}
}

// ====================测试代码====================
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

// 只有一个结点的链表: 1
void Test2()
{
	printf("\nTest2 begins.\n");

	ListNode* pNode1 = CreateListNode(1);

	Test(pNode1);

	DestroyList(pNode1);
}

// 空链表
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