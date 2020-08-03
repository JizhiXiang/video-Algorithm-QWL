#include<iostream>
using namespace std;

// 将数组a中已经排好序的l1~r1 和 已经排好序的l2~r2 合并起来
void merge(int a[], int l1, int r1, int l2, int r2){
    int len1 = r1-l1+1, len2 = r2-l2+1; // 两段的长度
    int i = l1, j = l2, k = 0;
    int *merge_a = new int[len1+len2];
    while(i<=r1 && j<=r2){
        if(a[i]<=a[j]){
            // 将较小的取出来放在merge_a中
            merge_a[k++] = a[i++];
        }else{
            merge_a[k++] = a[j++];
        }
    }
    while(j<=r2){
        // l1~r1这段走完了，只需将l2~r2这段后面的全部放在merge_a后面即可
        merge_a[k++] = a[j++];
    }
    while(i<=r1){
        // 同理，但两个while条件只会满足一个
        merge_a[k++] = a[i++];
    }

    // debug 可删
    for(int m=0;m<len1+len2;m++){
        cout << merge_a[m] << " ";
    }
    cout<<endl;

    k = 0;
    while(k<len1+len2){
        // 将merge_a的值赋值给a，因为最后是看数组a的合并情况
        a[l1+k] = merge_a[k++];
    }
    delete[] merge_a;
}

void mergeSort(int a[], int l, int r){
    if(l<r){
        int mid = (l+r)>>1; //找到中间位置
        mergeSort(a, l, mid); //mid和mid+1中间要连起来，不能断裂
        mergeSort(a, mid+1, r);
        merge(a, l, mid, mid+1, r);
    }
}

int main(){
    int a[] = {5, 8, 1, 3, 6, 2, 4, 7};
    int n = sizeof(a)/sizeof(int);
    mergeSort(a, 0, n-1);
    cout << "\nafter sort:" << endl;
    for(int i=0;i<n;i++){
        cout << a[i] << " ";
    }

}