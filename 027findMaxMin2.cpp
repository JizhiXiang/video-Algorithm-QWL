#include<iostream>
#include<algorithm>
using namespace std;

//分治算法
//参考https://www.cnblogs.com/huashanqingzhu/p/3861016.html
//在数组a的区间[i,j]范围内寻找一个最大值和一个最小值并通过指针*max和*min返回
int findMaxMin(int *a,int i,int j,int *max,int *min){
    int mid;
    int lmax,lmin,rmax,rmin;
    if(i==j){
        *max = a[i];
        *min = a[i];
        return 0;
    }else if(i+1==j){
        *max = std::max(a[i],a[j]);
        *min = std::min(a[i],a[j]);
        return 0;
    }
    mid = i+(j-i)/2;
    findMaxMin(a,i,mid,&lmax,&lmin);
    findMaxMin(a,mid+1,j,&rmax,&rmin);
    *max = std::max(lmax,rmax);
    *min = std::min(lmin,rmin);
    return 0;
}

int main(){
    int S[]= {1,3,5,7,9,2,4,6,8,10};
    int n = sizeof(S)/sizeof(int);
    int max,min;
    findMaxMin(S,0,n-1,&max,&min);
    cout << "min:" << min << endl;
    cout << "max:" << max << endl;
}