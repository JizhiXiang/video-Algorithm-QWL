#include <iostream>
using namespace std;

//代码来源于https://github.com/tangsongbbb/AlgorithmsLearning/blob/master/%E4%BD%9C%E4%B8%9A6/6.1.c

void insertSort(int R[], int low, int high) {  //插入排序
	int i, j, tmp;
	for (i = low + 1; i <= high; ++i) {
		tmp = R[i];  //假设i指向第二个元素
		j = i - 1;  //j指向第一个元素
		while (j >= low && R[j] > tmp) {  //假设第一个元素>第二个元素
			R[j + 1] = R[j];  //第一个元素右移一位，此时第二个位置上为较大的数
			--j;  //j指向下一个（前一个）
		}
		R[j + 1] = tmp;  //把最后一次-1加回来，把第二个元素放在第一个位置上。
	}
}

int FindMid(int R[], int low, int high) {  //找差不多值为中间的元素，和PPT中m*类似
	if (low == high) {
		return R[low];
	}
	int i, k;
	for (i = low; i + 4 <= high; i += 5) {
		insertSort(R, i, i + 4);  //用插入排序法（从小到大），排好R数组从i到i+4的数
		k = i - low;  
		swap(R[low + k / 5], R[i + 2]);  //R[low + k / 5]：第一组的数据，R[i + 2]：第i组的中位数
	}
	int n = high - i + 1;  //最后面轮空的
	if (n > 0) {
		insertSort(R, i, high);
		k = i - low;
		swap(R[low + k / 5], R[i + n / 2]);
	}
	k = k / 5;
	if (k == 0) {  //k<=4 不足一组时，返回第一个数
		return R[low];
	}
	return FindMid(R, low, low + k);  //下一轮的寻找
}

int FindId(int R[], int low, int high, int median) {
	for (int i = low; i <= high; ++i) {
		if (median == R[i]) {
			return i;
		}
	}
	return -1;
}

int Partion(int R[], int low, int high, int index) {  //以R[index]为枢纽值，做一次划分操作，左边比它小，右边比它大
	if (low <= high) {
		swap(R[index], R[low]);
		int tmp = R[low];
		int i = low, j = high;
		while (i != j) {
			while (j > i&& R[j] >= tmp) {
				--j;
			}
			R[i] = R[j];
			while (i < j && R[i] <= tmp) {
				++i;
			}
			R[j] = R[i];
		}
		R[i] = tmp;
		return i;
	}
	return -1;
}

int Select(int R[], int low, int high, int K) {
	int median = FindMid(R, low, high);
	int index = FindId(R, low, high, median);
	int newIndex = Partion(R, low, high, index);
	int rank = newIndex - low + 1;
	if (rank == K) {
		return newIndex;
	}
	else if (rank > K) {
		return Select(R, low, newIndex - 1, K);
	}
	return Select(R, newIndex + 1, high, K - rank);
}
int main() {
	int i, n, k;  //, d[100];
	// cout << "Please input the amount:";
	// cin >> n;
	// cout << "Please input the numbers:" << endl;
	// for (i = 0; i < n; i++) {
	// 	cin >> d[i];
	// }
	// cout << "Please input k:";
	// cin >> k;
    int d[] = {8,2,3,5,7, 6,11,14,1,9, 13,10,4,12,15};
    n = sizeof(d)/sizeof(int);
    k = 6;
	int index;
	index = Select(d, 0, n - 1, k);
	cout << "the number is: " << d[index] << endl;
}