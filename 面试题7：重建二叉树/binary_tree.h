#pragma once
#include <stdio.h>  

struct BinaryTreeNode {
	int value;
	BinaryTreeNode* pLeft;
	BinaryTreeNode* pRight;
};


BinaryTreeNode* CreateBinaryTreeNode(int value) {
	BinaryTreeNode* pNode = new BinaryTreeNode();
	pNode->value = value;
	pNode->pLeft = NULL;
	pNode->pRight = NULL;

	return pNode;
}

void ConnectTreeNodes(BinaryTreeNode* pParent, BinaryTreeNode* pLeft, BinaryTreeNode* pRight) {
	if (pParent != NULL) {
		pParent->pLeft = pLeft;
		pParent->pRight = pRight;
	}
}

void PrintTreeNode(BinaryTreeNode* pNode) {
	if (pNode != NULL) {
		printf("value of this node is: %d\n ", pNode->value);
		if (pNode->pLeft != NULL)
			printf("value of its left child is: %d \n", pNode->pLeft->value);
		else
			printf("left child is null. \n");

		if (pNode->pRight != NULL)
			printf("value of its right child is: %d \n", pNode->pRight->value);
		else
			printf("right child is null. \n");
	}
	else {
		printf("this node is null. \n");
	}
	printf("\n");
}

void PrintTree(BinaryTreeNode* pRoot) {
	PrintTreeNode(pRoot);
	if (pRoot != NULL) {
		if (pRoot->pLeft != NULL)
			PrintTree(pRoot->pLeft);

		if (pRoot->pRight != NULL)
			PrintTree(pRoot->pRight);
	}
}

void DestroyTree(BinaryTreeNode* pRoot) {
	if (pRoot != NULL) {
		BinaryTreeNode* pLeft = pRoot->pLeft;
		BinaryTreeNode* pRight = pRoot->pRight;

		delete pRoot;
		pRoot = NULL;

		DestroyTree(pLeft);
		DestroyTree(pRight);
	}
}