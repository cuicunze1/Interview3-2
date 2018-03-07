#include<cstdio>

bool Dumplication(int numbers[], int length, int* dumplication) {
	//判断输入数组是否为空,长度是否小于等于0
	if (numbers == nullptr || length <= 0)
		return false;
	//判断数组内数字是否位于0~k-1
	for (int i = 0; i < length; ++i) {
		if (numbers[i]<0 || numbers[i]>length - 1)
			return false;
	}
	//开始查找重复数字
	for (int i; i < length; ++i) {
		while (i != numbers[i]) {
			if (numbers[i] == numbers[numbers[i]]) {
				*dumplication = numbers[i];
				return true;
			}
			//交换两个数
			int TempNum;
			TempNum = numbers[i];
			numbers[i] = numbers[TempNum];
			numbers[TempNum] = TempNum;
		}
	}
	return false;
}