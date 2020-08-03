#include <iostream>
#include <algorithm>
#include <list>
using namespace std;

//PPT中的锦标赛算法
//另外一种简单的，但时间复杂度更高的算法：https://github.com/zhang35/Algorithm-Design-And-Analysis/blob/master/%E7%AC%AC2%E7%AB%A0%20%E5%88%86%E6%B2%BB%E7%AD%96%E7%95%A5%20/%E6%89%BE%E7%AC%AC%E4%BA%8C%E5%A4%A7%E6%95%B0.cpp

void P(list<int> loser_list[], int S[], int n){
    //打印
    for(int i=0;i<n;i++){
        cout << S[i] << ": ";
        for (list<int>::iterator it=loser_list[i].begin(); it!=loser_list[i].end(); it++){
            cout << S[*it] << "->";
        }
        cout << endl;
    }
}

int FindSecond(int S[], int Idx[], int n){
    if(n<2)
        return 0;
    list<int> loser_list[n];  //每个位置都有一个list，用来代替链表
    int k;  //参与淘汰的元素数
    int m;
    k = n;
    while(k>=2){
        if(k%2==1){
            m = k/2+1;  //下一轮，数组中元素的个数
        }else{
            m = k/2;
        }
        int next_turn[m] = {0};
        int j=0;
        for(int i=0;i/2<k/2;i=i+2){  // i/2<k/2，总共有k/2组（考虑到奇数情况），一组里面有两个元素
            int index_a = Idx[i];  //Idx是每一轮参与淘汰的数组中的index,S存储的是数
            int index_b = Idx[i+1];
            if(S[index_a] > S[index_b]){  //S[index_a]要大
                loser_list[index_a].push_back(index_b);  //将失败者index_b加在index_a后面
                next_turn[j++] = index_a;  //将index_a存储在下一轮中
            }else{
                loser_list[index_b].push_back(index_a);
                next_turn[j++] = index_b;
            }
        }
        if(k%2==1){  //如果k为奇数
            next_turn[j] = Idx[k-1];  //将最后一个index（轮空）存储到next_turn
        }
        k = m;
        for(int i=0;i<m;i++){
            Idx[i] = next_turn[i];  //将下一轮index赋值给Idx
        }
    }
    P(loser_list, S, n);
    int max_index = Idx[0];  //因为只剩一个元素了，它就是最大元素的idx
    int max_value = S[max_index];
    list<int>::iterator it = loser_list[max_index].begin();
    int second_value = S[*it];  //*it存储的是下标
    for(;it!=loser_list[max_index].end();it++){
        second_value = max(second_value, S[*it]);
    }
    cout << "max value:" << max_value << endl;
    cout << "second_value:" << second_value << endl;
}

int main()
{
    int n;
    int S[]= {5,3,6,7,2,1,4,8};
    n = sizeof(S)/sizeof(int);
    int Idx[n] = {0};
    for(int i=0;i<n;i++)
        Idx[i] = i;

    FindSecond(S, Idx, n);
    return 0;
}

int main2()
{
    int n;
    int S[]= {5,3,6,7,2,1,4,8,6};
    n = sizeof(S)/sizeof(int);
    int Idx[n] = {0};
    for(int i=0;i<n;i++)
        Idx[i] = i;

    FindSecond(S, Idx, n);
    return 0;
}