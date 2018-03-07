#include<cstdio>
/*
����������
1.����Ϊ��
2.����2����������1�м�
3.����2ȫ��������1����
4.����2ȫ��������1ǰ��
5.����1������ͬ
6.����2������ͬ
7.����1�����ظ�����
8.����2�����ظ�����
9.���߾����ظ�����
*/
void SortMerge(int num1[], int num2[],int length) {
	if (num1 == nullptr || num2 == nullptr||length<=0)
		return;
	int length1=0, length2=0;
	for (; num1[length1] != '\0'; length1++);
	for (; num2[length2] != '\0'; length2++);
	//�����ܳ���
	int fullLength = length1 + length2;
	//���ռ䲻��
	if (fullLength > length)
		return;
	//��ʼ�ƶ�
	int num1Ptr = length1-1;
	int num2Ptr = length2-1;
	int fullPtr = fullLength-1;
	num1[fullPtr] = '\0';
	while (fullPtr>=0) {
		if (num1Ptr <0)//��num1ԭ������ȡ��
			num1[fullPtr--] = num2[num2Ptr--];
		else if (num2Ptr <0)//��num2������ȡ��
			num1[fullPtr--] = num1[num1Ptr--];
		else {
			if (num2[num2Ptr] >= num1[num1Ptr])
				num1[fullPtr--] = num2[num2Ptr--];
			else
				num1[fullPtr--] = num1[num1Ptr--];
		}
	}
}
void Test(char*testName, int num1[], int num2[], int length, int expected[]) {
	if (testName != nullptr)
		printf("%s begins: ", testName);
	SortMerge(num1, num2, length);
	if (expected == nullptr && num1 == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && num1 != nullptr)
		printf("failed.\n");
	else {
		printf("expected:");
		for (int i = 0; expected[i] != '\0'; i++)
			printf("%d ", expected[i]);
		putchar('\n');
		printf("yours:");
		for (int i = 0; num1[i] != '\0'; i++)
			printf("%d ", num1[i]);
		putchar('\n');
	}
}
//����2����������1�м�
void Test1() {
	const int length = 100;

	int num1[length] = {1,3,5,7,9};
	int num2[length] = {2,4,6,8,10};
	int expected[length] = {1,2,3,4,5,6,7,8,9,10};
	Test("Test1", num1, num2, length, expected);
}
//����2��������1�ĺ���
void Test2() {
	const int length = 100;

	int num1[length] = { 1,2,3,4,5 };
	int num2[length] = { 6,7,8,9,10 };
	int expected[length] = { 1,2,3,4,5,6,7,8,9,10 };
	Test("Test2", num1, num2, length, expected);
}
//����2��������1��ǰ��
void Test3() {
	const int length = 100;

	int num1[length] = { 6,7,8,9,10 };
	int num2[length] = { 1,2,3,4 };
	int expected[length] = { 1,2,3,4,6,7,8,9,10 };
	Test("Test3", num1, num2, length, expected);
}
//����1����ȫ����ͬ
void Test4() {
	const int length = 100;

	int num1[length] = { 6,6,6,6,6 };
	int num2[length] = { 1,2,3,4 };
	int expected[length] = { 1,2,3,4,6,6,6,6,6 };
	Test("Test4", num1, num2, length, expected);
}
//����2����ȫ����ͬ
void Test5() {
	const int length = 100;

	int num1[length] = { 1,2,3,4,5 };
	int num2[length] = { 6,6,6,6,6 };
	int expected[length] = { 1,2,3,4,5,6,6,6,6,6 };
	Test("Test5", num1, num2, length, expected);
}
//���������ͬ
void Test6() {
	const int length = 100;

	int num1[length] = { 1,1,1,1,1 };
	int num2[length] = { 6,6,6,6,6 };
	int expected[length] = { 1,1,1,1,1,6,6,6,6,6 };
	Test("Test6", num1, num2, length, expected);
}
int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	return 0;
}