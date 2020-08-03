#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

int partiton(int a[], int l, int r);

void quickSort(int a[], int l, int r){
    if(l<r){
        int mid = partiton(a, l, r);
        quickSort(a, l, mid-1);
        quickSort(a, mid+1, r);
    }
}


// 快排非递归
void quickSortNotRecursive(int a[], int l, int r){
    stack<int> s;
    s.push(r);
    s.push(l);
    while(!s.empty()){
        int l2 = s.top();
        s.pop();
        int r2 = s.top();
        s.pop();

        int mid = partiton(a, l2, r2);
        if(l2<mid-1){
            s.push(mid-1);
            s.push(l2);
        }
        if(mid+1<r){
            s.push(r);
            s.push(mid+1);
        }
    }
}

int partiton(int a[], int l, int r){
    int pivot = a[l]; // 获取最开始l位置的值，作为枢轴
    int first_l = l; // 记录原始l值
    while(l<r){
        while(l<r && a[r]>pivot){
            // 右边的严格大于，保证枢轴的右边均大于枢轴
            r--;
        }
        while(l<r && a[l]<=pivot){
            // 左边的小于等于，保证枢轴的左边小于等于枢轴。
            l++;
        }
        swap(a[l], a[r]);
    }
    // 最后跳出外层循环的情况: l==r, 且是r从右边过来和l靠拢的，只需将l位置元素和枢轴互换即可
    swap(a[l], a[first_l]);
    return l;
}

int main(){
    // 快排
    int a[] = {5, 8, 1, 3, 6, 2, 4, 7};
    int n = sizeof(a)/sizeof(int);
    quickSort(a, 0, n-1); 
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl << endl;

    // 测试partition函数
    int a2[] = {5, 8, 5, 3, 6, 2, 5, 7}; //考虑有可能和枢轴出现相等的值
    // 5 8(l) 5 3 6 2 5(r) 7  （过程演示）
    // 5 5 5 3 6(l) 2(r) 8 7
    // 5 5 5 3 2(l) 6(r) 8 7
    // 5 5 5 3 2(l,r) 6 8 7
    // 2 5 5 3 5 6 8 7
    int n2 = sizeof(a2)/sizeof(int);
    int x = partiton(a2, 0, n2-1); 
    for(int i=0;i<n2;i++){
        cout << a2[i] << " ";
    }
    cout << endl  << x << endl << endl ;


    // 非递归法快排
    int a3[] = {5, 8, 5, 3, 6, 2, 5, 7};
    int n3 = sizeof(a3)/sizeof(int);
    quickSortNotRecursive(a3, 0, n3-1);
    for(int i=0;i<n3;i++){
        cout << a3[i] << " ";
    }
}