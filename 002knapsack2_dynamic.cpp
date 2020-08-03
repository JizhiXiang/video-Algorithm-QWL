#include<iostream>
using namespace std;

//动态规划法 求解01背包
//参考 https://blog.csdn.net/chanmufeng/article/details/82955730
int ks_dynamic(int w[], int v[], int size, int capacity){
    //size为物品的个数

    //C++用new创建二维数组的方法
    //dp[i][j]意义：从0~i件物品中选择，容量限制为j，求得的最大价值
    int **dp = new int *[size]; //参考方法二 https://blog.csdn.net/samuelcoulee/article/details/8674388
    for(int i=0;i<size;i++)
        dp[i] = new int[capacity+1]; //因为容量从0到capacity

    //初始化第0行
    //仅考虑容量为capacity的背包放第0个物品的情况
    for(int j=0;j<=capacity;j++){
        dp[0][j] = w[0]<=j ? v[0]:0;  //能放的下则放第0个物品，价值为v[0]，否则为0
    }
    //填充其他行和列
    for(int i=1;i<size;i++){
        for(int j=0;j<=capacity;j++){
            dp[i][j] = dp[i-1][j]; //不放第i个物品
            if(w[i]<=j){
                dp[i][j] = max(dp[i][j], dp[i-1][j-w[i]]+v[i]); //放第i件物品，和不放进行比较，选择大者
            }
        }
    }

    int res = dp[size-1][capacity];

    //释放数组
    //先释放第二维
    for(int i=0;i<size;i++)
        delete[] dp[i];
    //再释放第一维
    delete[] dp;

    return res;
}

//一维数组的动态规划法 求解01背包
int ks_dynamic2(int w[], int v[], int size, int capacity){
    
    int *dp = new int[capacity+1]; //new一个数组 https://blog.csdn.net/u010292561/article/details/77877266
    
    //初始化
    //仅考虑容量为capacity的背包放第0个物品的情况
    for(int j=0;j<=capacity;j++)
        dp[j] = w[0]<=j ? v[0] : 0;

    for(int i=1;i<size;i++){
        for(int j=capacity;j>=w[i];j--){
            dp[j] = max(dp[j], dp[j-w[i]]+v[i]);
        }
    }

    int res = dp[capacity];
    delete[] dp;

    return res;
}

int main(){
    
    int n = 4;
    int w[n] = {3, 4, 5, 2}; //weight
    int v[n] = {7, 9, 9, 2}; //value
    int capacity = 6;
    int max_value = ks_dynamic(w, v, n, capacity);
    cout << max_value << endl;

    int max_value2 = ks_dynamic2(w, v, n, capacity);
    cout << max_value2 << endl;

}