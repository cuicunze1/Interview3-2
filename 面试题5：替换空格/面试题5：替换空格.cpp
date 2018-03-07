#include<cstdio>
#include<cstring>
/*
����������
1.�ַ���Ϊ��
2.�ո����ײ�
3.�ո���β��
4.�������ո�
5.û�пո�
6.�ַ����ռ䲻��
*/
void ReplaceBlank(char string[], int length) {
	//�ж������Ƿ�Ϸ�
	if (string == nullptr || length <= 0)
		return;
	//����ԭʼ���ȺͿո���Ŀ
	int originalLength = 0;
	int blankNum = 0;
	while (string[originalLength] != '\0') {
		if (string[originalLength] == ' ')
			blankNum++;
		originalLength++;
	}
	//��ʼ�ƶ�
	int newLength = originalLength + 2 * blankNum;
	if (newLength > length)//�ռ䲻��ֱ�ӷ���
		return;
	int oldPtr = originalLength;
	int newPtr = newLength;
	//while (oldPtr >= 0 && newPtr > oldPtr) {//���ƶ�����ʱ����ָ���ص�
	while (blankNum) {//���ո����꣬�������
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

// ====================���Դ���====================
void Test(char* testName, char str[], int length, char expected[])
{
	if (testName != nullptr)
		printf("%s begins: ", testName);

	ReplaceBlank(str, length);

	if (expected == nullptr && str == nullptr)
		printf("passed.\n");
	else if (expected == nullptr && str != nullptr)
		printf("failed.\n ���stringΪ��%s\n",str);
	else if (strcmp(str, expected) == 0)
		printf("passed.\n");
	else
		printf("failed.\n���stringΪ��%s\n", str);
}

// �ո��ھ����м�
void Test1()
{
	const int length = 100;

	char str[length] = "hello world";
	Test("Test1", str, length, "hello%20world");
}

// �ո��ھ��ӿ�ͷ
void Test2()
{
	const int length = 100;

	char str[length] = " helloworld";
	Test("Test2", str, length, "%20helloworld");
}

// �ո��ھ���ĩβ
void Test3()
{
	const int length = 100;

	char str[length] = "helloworld ";
	Test("Test3", str, length, "helloworld%20");
}

// �����������ո�
void Test4()
{
	const int length = 100;

	char str[length] = "hello  world";
	Test("Test4", str, length, "hello%20%20world");
}

// ����nullptr
void Test5()
{
	Test("Test5", nullptr, 0, nullptr);
}

// ��������Ϊ�յ��ַ���
void Test6()
{
	const int length = 100;

	char str[length] = "";
	Test("Test6", str, length, "");
}

//��������Ϊһ���ո���ַ���
void Test7()
{
	const int length = 100;

	char str[length] = " ";
	Test("Test7", str, length, "%20");
}

// ������ַ���û�пո�
void Test8()
{
	const int length = 100;

	char str[length] = "helloworld";
	Test("Test8", str, length, "helloworld");
}

// ������ַ���ȫ�ǿո�
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