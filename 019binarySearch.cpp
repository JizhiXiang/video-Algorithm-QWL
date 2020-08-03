#include <iostream>
using namespace std;
//参考https://github.com/zhang35/Algorithm-Design-And-Analysis/blob/master/%E7%AC%AC2%E7%AB%A0%20%E5%88%86%E6%B2%BB%E7%AD%96%E7%95%A5%20/%E4%BA%8C%E5%88%86%E6%9F%A5%E6%89%BE.cpp

int BinarySearch(int T[], int x, int n){
    int l=0, r=n-1;
    while(l<=r){
        int mid = (l+r)>>1;
        if(x<T[mid]){
            r = mid-1;
        }else if(x>T[mid]){
            l = mid+1;
        }else{
            return mid;
        }
    }
    return -1;
}

int main()
{
    int T[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 12};
    int n = sizeof(T)/sizeof(int);
    int x = 4;
    cout << "position: " << BinarySearch(T, x, n) << endl;
    return 0;
}