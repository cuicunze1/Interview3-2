#include<cstdio>

bool Dumplication(int numbers[], int length, int* dumplication) {
	//�ж����������Ƿ�Ϊ��,�����Ƿ�С�ڵ���0
	if (numbers == nullptr || length <= 0)
		return false;
	//�ж������������Ƿ�λ��0~k-1
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}
	//��ʼ�����ظ�����
	for (int i; i < length; ++i) {
		while (i != numbers[i]) {
			if (numbers[i] == numbers[numbers[i]]) {
				*dumplication = numbers[i];
				return true;
			}
			//����������
			int TempNum;
			TempNum = numbers[i];
			numbers[i] = numbers[TempNum];
			numbers[TempNum] = TempNum;
		}
	}
	return false;
}