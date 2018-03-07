#include<cstring>
#include<cstdio>

class CMyString {
public:
	CMyString(char * pData = nullptr);
	CMyString(const CMyString& str);
	~CMyString(void);
	CMyString& operator = (const CMyString& str);
	void Print();
private:
	char* m_pData;
};

//经典的解法，适用于一般程序员
CMyString&  CMyString::operator=(const CMyString & str)//返回引用，否则进行连续赋值如a=b=c时产生临时对象，降低效率。亲测不加引用也能通过
{
	if(this == &str)       //若传入参数和实例是同一实例时，当释放实例内存后，传入参数的内存也会被释放，找不到需要赋值的内容了，所以直接返回*this
		return *this;

	delete[] m_pData;      //在赋值之前若没有释放已有内存，程序将出现内存泄漏（只申请空间，不释放空间）
	m_pData = nullptr;     //释放内存后将指针归零，不可悬空

	/*在上述代码中，若考虑***异常安全性***，即内存不足情况下无法申请内存，却已经释放了m_pData的情况。
	一个函数如果说是“异常安全”的，必须同时满足以下两个条件：1.不泄漏任何资源；2.不允许破坏数据。此处异常为破坏数据
	1.防止泄露资源，不直接对互斥锁mutex操作，而是用到管理锁的对象MuteLock ml,在构造实例时，自动上锁，析构时自动解锁，即使资源异常，也总会有析构解锁的时候。
	2.防止数据破坏：一个经典的策略叫“copy and swap"。原则很简单：即先对原对象做出一个副本（copy），在副本上做必要的修改。
	如果出现任何异常，原对象依然能保证不变。如果修改成功，则通过不抛出任何异常的swap函数将副本和原对象进行交换（swap）。
	详情参考：http://blog.csdn.net/bonchoix/article/details/8046727
	本题问题解决方法：
	解决方法1：先用new分配新内容，再用delete释放已有的内容
	解决方法2：与上面的类似，创建一个临时实例，再交换临时实例和原来的实例，代码如下：
	CMyString& CMyString::operator = (const CMyString& str)
	{
		if(this!=str){
			CMyString strTemp(str);
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;//此处strTemp.m_pData指向的内存，就是m_pData之前的内存，运行到if外面自动析构，释放掉相应内存
			m_pData = pTemp;
		}
	}
	*/

	m_pData = new char[strlen(str.m_pData)+1];//strlen只计算字符个数，不保存'\0'，+1为了给'\0'留位置
	strcpy(m_pData, str.m_pData);

	return *this;                               
}


CMyString::CMyString(char * pData)
{
	if (pData == nullptr) {//判断参数是否为空
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}
//绝大多数情况下，这三个成员总是要么同时存在，要么都不用定义，因为编译器默认定义了，即C++中所谓的 ”Rule of 3" 规则。
CMyString::CMyString(const CMyString & str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString(void)
{
	delete[] m_pData;
}
// ====================测试代码====================
void CMyString::Print()
{
	printf("%s", m_pData);
}

void Test1()
{
	printf("Test1 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2;
	str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");
}

// 赋值给自己
void Test2()
{
	printf("Test2 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	str1 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str1.Print();
	printf(".\n");
}

// 连续赋值
void Test3()
{
	printf("Test3 begins:\n");

	char* text = "Hello world";

	CMyString str1(text);
	CMyString str2, str3;
	str3 = str2 = str1;

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str2.Print();
	printf(".\n");

	printf("The expected result is: %s.\n", text);

	printf("The actual result is: ");
	str3.Print();
	printf(".\n");
}
int main(int argc, char* argv[])
{
	Test1();
	Test2();
	Test3();

	return 0;
}