#include<cstdio>
#include<cstring>
/*
测试用例：
1.字符串为空
2.空格在首部
3.空格在尾部
4.有连续空格
5.没有空格
6.字符串空间不足
*/
void ReplaceBlank(char string[], int length) {
	//判断输入是否合法
	if (string == nullptr || length <= 0)
		return;
	//计算原始长度和空格数目
	int originalLength = 0;
	int blankNum = 0;
	while (string[originalLength] != '\0') {
		if (string[originalLength] == ' ')
			blankNum++;
		originalLength++;
	}
	//开始移动
	int newLength = originalLength + 2 * blankNum;
	if (newLength > length)//空间不足直接返回
		return;
	int oldPtr = originalLength;
	int newPtr = newLength;
	//while (oldPtr >= 0 && newPtr > oldPtr) {//当移动结束时，二指针重叠
	while (blankNum) {//当空格被填完，任务完成
		if (string[oldPtr] == ' ') {
			string[newPtr--] = '0';
			string[newPtr--] = '2';
			string[newPtr--] = '%';
			blankNum--;
		}
		else
			string[newPtr--] = string[oldPtr];
		oldPtr--;
	}
}

// ====================测试代码====================
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n 你的string为：%s\n",str);
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n你的string为：%s\n", str);
}

// 空格在句子中间
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// 空格在句子开头
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// 空格在句子末尾
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// 连续有两个空格
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// 传入nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// 传入内容为空的字符串
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//传入内容为一个空格的字符串
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// 传入的字符串没有空格
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// 传入的字符串全是空格
void Test9()
{
	const int length = 100;

	char str[length] = "   ";
	Test("Test9", str, length, "%20%20%20");
}

int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();
	Test4();
	Test5();
	Test6();
	Test7();
	Test8();
	Test9();

	return 0;
}