#include<iostream>
#include<algorithm>
using namespace std;

// 代码作者：机智翔学长（B站，CSDN同名）
// 赠送内容，堆排序，从小到大排序，故大顶堆获取数据后放在末尾

// 从下标l往下调整到r
void adjustHeap(int a[], int l, int r){
    if(l>=r){
        return ;
    }
    int i = l;
    int j = 2*i+1;
    while(j<=r){
        if(j+1<=r && a[j+1]>a[j]){
            // i节点下的两个子节点j和j+1(如果存在),选择大的那个和i节点比较
            j = j+1;
        }
        if(a[j]>a[i]){
            // 如果子节点j大于父节点i，则交换
            swap(a[i], a[j]);
        }else{
            break;
        }
        i = j;
        j = 2*i+1;
    }
}

// debug
void debugOut(int a[], int l, int r){
    cout << "\ndebug out:" << endl;
    for(int i=l;i<=r;i++){
        cout << a[i] << " ";
    }
    cout << endl;
}

// 堆排序，数组a[]，下标为l~r (实际上l为0)
void heapSort(int a[], int l, int r){

    // 先构建一个大顶堆
    for(int i=(r-1)/2;i>=l;i--){
        // i从最后一个父节点开始，往上
        adjustHeap(a, i, r); // 将数组a[]从i到r进行调整
    }

    // 再取出堆顶元素放在数组后边，重新调整堆
    for(int j=r;j>=l;j--){
        swap(a[l], a[j]);
        debugOut(a, l, r); // debug 可删
        adjustHeap(a, l, j-1);
    }
}

int main(){
    int a[] = {4, 6, 8, 5, 9};
    int len = sizeof(a)/sizeof(int);
    heapSort(a, 0, len-1);
    cout << "\n\nafter sort:" << endl;
    for(int i=0;i<len;i++){
        cout << a[i] << " ";
    }
}