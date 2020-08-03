#include <iostream>
#include <algorithm>
using namespace std;

//代码来源于https://github.com/zhang35/Algorithm-Design-And-Analysis/blob/master/%E7%AC%AC2%E7%AB%A0%20%E5%88%86%E6%B2%BB%E7%AD%96%E7%95%A5%20/%E5%90%8C%E6%97%B6%E6%89%BE%E6%9C%80%E5%A4%A7%E6%9C%80%E5%B0%8F%E5%80%BC.cpp

void P(int a[],int n); //打印数组
void FindMaxMin(int *S, int n, int* p_min, int* p_max);

int main()
{
    int n = 10;
    int S[]= {1,3,5,7,9,2,4,6,8,10};
    P(S, n);
    int minValue = 0;
    int maxValue = 0;
    FindMaxMin(S, n, &minValue, &maxValue);
    cout << "Min is: " << minValue  << endl;
    cout << "Max is: " << maxValue  << endl;
    return 0;
}
void P(int a[],int n)
{
    for(int i=0; i<n; i++){
        cout<<a[i]<<" ";
    }
    cout<<endl;
}
//两两比大小，较小者再和当前最小值比，较大者再和当前最大值比 
//若n为奇数，轮空一个，剩下每2个元素比3次，一共比3n/2次
//若n为偶数，开始只比1次，剩下每2个元素比3次，一共3n/2-2次
//所以总的来说至多3n/2次
void FindMaxMin(int *S, int n, int* p_min, int* p_max){
    int minValue;
    int maxValue;
    if (n<=0){
        return;
    }
    if (n==1){
        *p_min = S[0];
        *p_max = S[0];
        return;
    }
    if (n%2!=0){ //奇数个时，初值设为最后一个元素
        minValue = S[n-1];
        maxValue = S[n-1];
        n--;
    }
    else { 
        if (S[n-1]>S[n-2]){
            minValue = S[n-2];
            maxValue = S[n-1];
        }
        else{
            minValue = S[n-1];
            maxValue = S[n-2];
        }
        n -= 2;
    }

    for (int i=0; i<n; i+=2){
        if (S[i]>S[i+1]){
            minValue = min(S[i+1], minValue);
            maxValue = max(S[i], maxValue);
        }
        else{
            minValue = min(S[i], minValue);
            maxValue = max(S[i+1], maxValue);
        }
    }
    *p_min = minValue;
    *p_max = maxValue;
}