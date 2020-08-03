#include <iostream>
using namespace std;

//代码参考https://github.com/zhang35/Algorithm-Design-And-Analysis/blob/master/%E7%AC%AC2%E7%AB%A0%20%E5%88%86%E6%B2%BB%E7%AD%96%E7%95%A5%20/%E6%89%BE%E7%AC%ACk%E5%B0%8F%E6%95%B0%E5%8F%8A%E4%B8%AD%E4%BD%8D%E6%95%B0%E2%80%94O(n)%E5%A4%8D%E6%9D%82%E5%BA%A6.cpp
//找第k小，简化版

void P(int a[],int n); //打印数组
int SelectK(int *S, int l, int r, int k);//找第k小数

int main()
{
    int n = 10;
    int S[]= {1,3,5,7,9,2,4,6,8,10};
    P(S, 10);
    int k;
    // cout << "input k:";
    // cin >> k;
    k = 6;
    cout << "the " << k << "th min number is: " << SelectK(S, 0, n-1, k) << endl;
    return 0;
}
void P(int a[],int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
int Partition(int *S, int l, int r){
    int i = l;
    int j = r;
    int x = S[l];
    while (i<j){
        while (i<j && S[j]>=x){
            j--;
        }
        if (i<j){
            S[i++] = S[j];
        }
        while (i<j && S[i]<=x){
            i++;
        }
        if (i<j){
            S[j--] = S[i];
        }
    }
    S[i] = x;
    return i;
}

//2.4.2 找第k小数,等价于找到一个位置为k的元素，前面的都比它小，后面的都比它大
//采用类似于快速排序的划分方法，但根据情况每次只处理其中一边，通过计算（《算法导论》p109）其平均复杂度为O(n)
int SelectK(int *S, int l, int r, int k){
    int pivot = Partition(S, l, r);
	int rank = pivot - l + 1;
	if (rank == k) {
		return S[pivot];
	}
	else if (rank > k) {
		return SelectK(S, l, pivot-1, k);
	}
	return SelectK(S, pivot+1, r, k-rank);

}
