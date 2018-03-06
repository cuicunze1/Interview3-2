#include<cstdio>
#include<iostream>
bool DupCount(int start, int middle, int length, int numbers[]);
int duplicate(int numbers[], int length) {
	//先判断输入数组是否为空，长度是否小于等于0
	if (numbers == nullptr || length <= 1)
		return -1;
	//判断是否有元素不符合规则
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<1 || numbers[i]>length)
			return -1;
	}
	//若符合规则
	int start = 1;
	int end = length - 1;
	while (start <=end) {
		int middle = ((end - start) >> 1)+start;//中间值middle向上取整
		bool ret = DupCount(start, middle , length, numbers);
		if (start == end) {
			if (ret == false)
				return -1;
			return start;
		}

		if (ret == true)
			end = middle;
		else {
			//防止没有重复数字这一情况
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

// ====================测试代码====================
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
	std::cout << "你的重复数字为" << result << std::endl;
}

// 多个重复的数字
void test1()
{
	int numbers[] = { 2, 3, 5, 4, 3, 2, 6, 7 };
	int duplications[] = { 2, 3 };
	test("test1", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个重复的数字
void test2()
{
	int numbers[] = { 3, 2, 1, 4, 4, 5, 6, 7 };
	int duplications[] = { 4 };
	test("test2", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最小的数字
void test3()
{
	int numbers[] = { 1, 2, 3, 4, 5, 6, 7, 1, 8 };
	int duplications[] = { 1 };
	test("test3", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字是数组中最大的数字
void test4()
{
	int numbers[] = { 1, 7, 3, 4, 5, 6, 8, 2, 8 };
	int duplications[] = { 8 };
	test("test4", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 数组中只有两个数字
void test5()
{
	int numbers[] = { 1, 1 };
	int duplications[] = { 1 };
	test("test5", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 重复的数字位于数组当中
void test6()
{
	int numbers[] = { 3, 2, 1, 3, 4, 5, 6, 7 };
	int duplications[] = { 3 };
	test("test6", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 多个重复的数字
void test7()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 6 };
	int duplications[] = { 2, 6 };
	test("test7", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 一个数字重复三次
void test8()
{
	int numbers[] = { 1, 2, 2, 6, 4, 5, 2 };
	int duplications[] = { 2 };
	test("test8", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 没有重复的数字
void test9()
{
	int numbers[] = { 1, 2, 6, 4, 5, 3 };
	int duplications[] = { -1 };
	test("test9", numbers, sizeof(numbers) / sizeof(int), duplications, sizeof(duplications) / sizeof(int));
}

// 无效的输入
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