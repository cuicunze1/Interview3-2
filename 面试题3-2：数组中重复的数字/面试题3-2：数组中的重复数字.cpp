#include<cstdio>
#include<iostream>
bool DupCount(int start, int middle, int length, int numbers[]);
int duplicate(int numbers[], int length) {
	//���ж����������Ƿ�Ϊ�գ������Ƿ�С�ڵ���0
	if (numbers == nullptr || length <= 1)
		return -1;
	//�ж��Ƿ���Ԫ�ز����Ϲ���
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<1 || numbers[i]>length)
			return -1;
	}
	//�����Ϲ���
	int start = 1;
	int end = length - 1;
	while (start <=end) {
		int middle = ((end - start) >> 1)+start;//�м�ֵmiddle����ȡ��
		bool ret = DupCount(start, middle , length, numbers);
		if (start == end) {
			if (ret == false)
				return -1;
			return start;
		}

		if (ret == true)
			end = middle;
		else {
			//��ֹû���ظ�������һ���
			/*if ((end - start) == 1) {
				int count = 0;
				for (int j = 0; j < length; ++j) {
					if (end == numbers[j])
						count++;
				}
				if (count <= 1)
					return -1;
			}*/
			start = middle + 1;
		}
	}
	return start;
}

bool DupCount(int start,  int middle,int length, int numbers[]) {
	int count = 0;
	int midlen = middle - start + 1;
	for (int i = 0; i < length; ++i) {
		if (numbers[i] >= start && numbers[i] <= middle)
			count++;
	}
	return count > midlen ? true : false;
}

// ====================���Դ���====================
void test(const char* testName, int* numbers, int length, int* duplications, int dupLength)
{
	int result = duplicate(numbers, length);
	for (int i = 0; i < dupLength; ++i)
	{
		if (result == duplications[i])
		{
			std::cout << testName << " passed." << std::endl;
			return;
		}
	}
	std::cout << testName << " FAILED." << std::endl;
	std::cout << "����ظ�����Ϊ" << result << std::endl;
}

// ����ظ�������
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ���ظ�������
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������С������
void test3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�����������������������
void test4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ������ֻ����������
void test5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// �ظ�������λ�����鵱��
void test6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ����ظ�������
void test7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// һ�������ظ�����
void test8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// û���ظ�������
void test9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// ��Ч������
void test10()
{
	int* numbers = nullptr;
	int duplications[] = { -1 };
	test("test10", numbers, 0, duplications, sizeof(duplications) / sizeof(int));
}

void main()
{
	test1();
	test2();
	test3();
	test4();
	test5();
	test6();
	test7();
	test8();
	test9();
	test10();
}