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

//����Ľⷨ��������һ�����Ա
CMyString&  CMyString::operator=(const CMyString & str)//�������ã��������������ֵ��a=b=cʱ������ʱ���󣬽���Ч�ʡ��ײⲻ������Ҳ��ͨ��
{
	if(this == &str)       //�����������ʵ����ͬһʵ��ʱ�����ͷ�ʵ���ڴ�󣬴���������ڴ�Ҳ�ᱻ�ͷţ��Ҳ�����Ҫ��ֵ�������ˣ�����ֱ�ӷ���*this
		return *this;

	delete[] m_pData;      //�ڸ�ֵ֮ǰ��û���ͷ������ڴ棬���򽫳����ڴ�й©��ֻ����ռ䣬���ͷſռ䣩
	m_pData = nullptr;     //�ͷ��ڴ��ָ����㣬��������

	/*�����������У�������***�쳣��ȫ��***�����ڴ治��������޷������ڴ棬ȴ�Ѿ��ͷ���m_pData�������
	һ���������˵�ǡ��쳣��ȫ���ģ�����ͬʱ������������������1.��й©�κ���Դ��2.�������ƻ����ݡ��˴��쳣Ϊ�ƻ�����
	1.��ֹй¶��Դ����ֱ�ӶԻ�����mutex�����������õ��������Ķ���MuteLock ml,�ڹ���ʵ��ʱ���Զ�����������ʱ�Զ���������ʹ��Դ�쳣��Ҳ�ܻ�������������ʱ��
	2.��ֹ�����ƻ���һ������Ĳ��ԽС�copy and swap"��ԭ��ܼ򵥣����ȶ�ԭ��������һ��������copy�����ڸ���������Ҫ���޸ġ�
	��������κ��쳣��ԭ������Ȼ�ܱ�֤���䡣����޸ĳɹ�����ͨ�����׳��κ��쳣��swap������������ԭ������н�����swap����
	����ο���http://blog.csdn.net/bonchoix/article/details/8046727
	����������������
	�������1������new���������ݣ�����delete�ͷ����е�����
	�������2������������ƣ�����һ����ʱʵ�����ٽ�����ʱʵ����ԭ����ʵ�����������£�
	CMyString& CMyString::operator = (const CMyString& str)
	{
		if(this!=str){
			CMyString strTemp(str);
			char* pTemp = strTemp.m_pData;
			strTemp.m_pData = m_pData;//�˴�strTemp.m_pDataָ����ڴ棬����m_pData֮ǰ���ڴ棬���е�if�����Զ��������ͷŵ���Ӧ�ڴ�
			m_pData = pTemp;
		}
	}
	*/

	m_pData = new char[strlen(str.m_pData)+1];//strlenֻ�����ַ�������������'\0'��+1Ϊ�˸�'\0'��λ��
	strcpy(m_pData, str.m_pData);

	return *this;                               
}


CMyString::CMyString(char * pData)
{
	if (pData == nullptr) {//�жϲ����Ƿ�Ϊ��
		m_pData = new char[1];
		m_pData[0] = '\0';
	}
	else {
		m_pData = new char[strlen(pData) + 1];
		strcpy(m_pData, pData);
	}
}
//�����������£���������Ա����Ҫôͬʱ���ڣ�Ҫô�����ö��壬��Ϊ������Ĭ�϶����ˣ���C++����ν�� ��Rule of 3" ����
CMyString::CMyString(const CMyString & str)
{
	m_pData = new char[strlen(str.m_pData) + 1];
	strcpy(m_pData, str.m_pData);
}
CMyString::~CMyString(void)
{
	delete[] m_pData;
}
// ====================���Դ���====================
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

// ��ֵ���Լ�
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

// ������ֵ
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