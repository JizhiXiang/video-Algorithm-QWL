#include<iostream>
using namespace std;

void insertSort(int a[], int n){
    if(n<=1)
        return ;
    int tmp; // 用来存储待插入的元素
    for(int i=1;i<n;i++){
        // 从前往后遍历
        tmp = a[i];
        int j;
        for(j=i-1;j>=0;j--){
            // 需要将tmp和a[i-1~0]进行比较，直到找到比tmp小的位置为止
            if(a[j] > tmp){
                // a[j]将元素右移一位
                a[j+1] = a[j];
            }else{
                // 找到合适位置
                break;
            }
        }
        // 将tmp填充在合适的位置
        a[j+1] = tmp;

        // debug
        for(int k=0;k<n;k++){
            cout << a[k] << " ";
        }
        cout << endl;
    }
    cout << endl;
}

// 插入排序法
int main(){
    
    int a[] = {5, 7, 1, 3, 6, 2, 4};
    int n = sizeof(a)/sizeof(int);
    insertSort(a, n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
}
