#include<iostream>
#include<algorithm>
using namespace std;

// 冒泡排序法
void bubbleSort(int a[], int n){
    int count = 0; // 计数外循环次数
    for(int i=n-1;i>=0;i--){
        // 控制结尾的位置
        count += 1;
        for(int j=0;j<i;j++){
            // 从头往后进行比较，并交换
            if(a[j]>a[j+1]){
                // 如果逆序
                swap(a[j], a[j+1]);
            }
        }
    }
    cout << "count:" << count << endl;
}

// 简单改进的冒泡排序法。对于最好的情况，即数组本来就是有序的，再按照上述代码进行遍历，会浪费很多时间。
// 故在此加入一个标志，如果本轮遍历未发生数据交换，就证明数组已然有序，直接结束循环。
// 参考 https://blog.csdn.net/weixin_38427766/article/details/84779303
void improvedBubbleSort(int a[], int n){
    int flag; // 标志位
    int count = 0; // 计数外循环次数
    for(int i=n-1;i>=0;i--){
        flag = 0;
        count += 1;
        for(int j=0;j<i;j++){
            if(a[j]>a[j+1]){
                // 如果发生逆序，则flag置为1
                flag = 1;
                swap(a[j], a[j+1]);
            }
        }
        if(flag==0){
            // 如果flag为0，则说明没有发生逆序了，则可以停止了
            break;
        }
    }
    cout << "count:" << count << endl;
}

int main(){
    int a[] = {5, 8, 1, 3, 6, 2, 4, 7};
    int n = sizeof(a)/sizeof(int);
    bubbleSort(a, n);
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }
    cout << endl;
    cout << endl;

    int a2[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n2 = sizeof(a2)/sizeof(int);
    improvedBubbleSort(a2, n2);
    for(int i=0;i<n2;i++){
        cout << a2[i] << " ";
    }
    cout << endl;
    bubbleSort(a2, n2);  // 即使已经排好序了，但还是会从头将两层循环跑完
    for(int i=0;i<n2;i++){
        cout << a2[i] << " ";
    }
}