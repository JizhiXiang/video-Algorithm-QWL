#include<iostream>
using namespace std;

//PPT P6 01背包问题
//指定限制重量，求获得最大价值.
//贪心法：X  ppt上有反例

//参考资料：《彻底理解0-1背包问题》
//https://blog.csdn.net/chanmufeng/article/details/82955730

// 01背包的递归解法
int ks_recursion(int w[], int v[], int index, int capacity){
    //ks_recursion() 表示将前index个物品放进容量为capacity的背包里，得到的最大的价值。index为数组下标。
    
    //基准条件：如果索引无效或者容量不足，直接返回当前价值0
    if(index < 0 || capacity <= 0)
        return 0;

    //不放第index个物品所得价值
    int res = ks_recursion(w, v, index-1, capacity);
    //放第index个物品所得价值（前提是：第index个物品可以放得下）
    if(w[index] <= capacity){ //放了，则一定有第index物品的价值v[index]，同时也损失了背包的容量w[index]
        res = max(res, ks_recursion(w, v, index-1, capacity-w[index]) + v[index]); //选择价值大者
    }
    return res;
}



int memo[4][6] = {0}; //第一维为index，第二维为capacity  可能有更好的办法

int ks_recursion2(int w[], int v[], int index, int capacity){
    //在上面的基础上，加上 记忆化搜索 
    if(index<0 || capacity<=0)
        return 0;
    
    //如果此子问题已经求解过，则直接返回上次求解的结果
    if(memo[index][capacity] != 0)
        return memo[index][capacity];

    int res = ks_recursion2(w, v, index-1, capacity); //不放第index个物品
    if(w[index] <= capacity){
        res = max(res, ks_recursion2(w, v, index-1, capacity-w[index])+v[index]);
    }

    //添加子问题的解，便于下次直接使用
    memo[index][capacity] = res;

    return res;
}

int main(){

    int n = 4; //4件物品
    int w[n] = {3, 4, 5, 2}; //每件物品重量
    int v[n] = {7, 9, 9, 2}; //每件物品价值
    int capacity = 6; //限制重量(容量)为6
    int max_value = ks_recursion(w, v, n-1, capacity);
    cout << max_value << endl;

    int max_value2 = ks_recursion2(w, v, n-1, capacity);
    cout << max_value2 << endl;

}