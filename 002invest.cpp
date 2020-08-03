#include<string.h>
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

#define MAX_N 4 //最大投资项目数目
#define MAX_M 5 //最大投资钱数(万元)

//投资问题 PPT 002 P9
//代码参考 https://blog.csdn.net/qq_37337268/article/details/79826646
//动态规划

void getBestStrategy(int **mark);  //声明函数，获取投资策略

// 打印计算结果(调试)
void printAns(int **dp, int **mark){
    int i,j;
    for(i = 1; i <= MAX_N; i++){
        for(j = 0; j <= MAX_M; j++){
            printf("(%d,%d)\t", dp[i][j], mark[i][j]);
        }
        printf("\n");
    }
}

//投资获取最大收益
int getMaxValue(int f[MAX_N+1][MAX_M+1]){
    //参考 二维数组作为函数参数传递 https://blog.csdn.net/weixin_41666244/article/details/80615661

    //dp[i][j]的意义：从1~i号项目中选择，投资j万元，所得到的最大收益
    int **dp = new int* [MAX_N+1];
    //标记函数，mark[i][j]的意义：从1~i号项目中选择，投资j万元，获得最大收益时，在第i号项目中投资了多少钱
    int **mark = new int* [MAX_N+1]; 

    for(int i=0;i<=MAX_N;i++){
        dp[i] = new int[MAX_M+1];
        //参考 C++二维动态数组memset()函数初始化 https://blog.csdn.net/longhopefor/article/details/20994919
        memset(dp[i], 0, (MAX_M+1)*sizeof(int));

        mark[i] = new int[MAX_M+1];
        memset(mark[i], 0, (MAX_M+1)*sizeof(int));
    }

    //初始化第1行（第1个项目）
    for(int j=0;j<=MAX_M;j++){
        dp[1][j] = f[1][j]; //因为只有1个项目，所以有多少钱j就投多少，对应收益为f[1][j]
        mark[1][j] = j;
    }

    int tmp;
    for(int i=2;i<=MAX_N;i++){
        for(int j=0;j<=MAX_M;j++){
            for(int k=0;k<=j;k++){
                tmp = f[i][k]+dp[i-1][j-k];
                if(tmp > dp[i][j]){
                    dp[i][j] = tmp; //更新当前最优解
                    mark[i][j] = k; //更新标记函数
                }
            }
        }
    }

    printAns(dp, mark);
    getBestStrategy(mark);

    int res = dp[MAX_N][MAX_M];

    //释放动态数组
    for(int i=0;i<=MAX_N;i++){
        delete[] dp[i];
        delete[] mark[i];
    }
        
    delete[] dp;
    delete[] mark;

    return res;
}

//根据标记函数，获取具体的投资策略
void getBestStrategy(int **mark){
    //标记函数，mark[i][j]的意义：从1~i号项目中选择，投资j万元，获得最大收益时，在第i号项目中投资了多少钱

    //策略向量，项目逆序存储投资金额（即第4个项目投了多少，第3个项目投了多少，等等）
    vector<int> strategy; // vector参考 https://www.runoob.com/w3cnote/cpp-vector-container-analysis.html
    int spend = 0; //已经花了多少钱
    for(int i=MAX_N;i>=1;i--){
        strategy.push_back(mark[i][MAX_M-spend]);
        spend += mark[i][MAX_M-spend];
    }

    reverse(strategy.begin(), strategy.end()); //逆序排列
    cout << "strategy: " ;
    for(int i=0;i<strategy.size();i++){
        cout << strategy[i] << " ";
    }
    cout << endl;
}

int main(){

    //参考 C++二维数组初始化的形式 https://blog.csdn.net/ys1305/article/details/100071389
    //f[i][j]的意义：第i（从1开始）个项目投资j万元的收益
    int f[MAX_N+1][MAX_M+1] = { {0,0,0,0,0,0},
                                {0,11,12,13,14,15},
                                {0,0,5,10,15,20},
                                {0,2,10,30,32,40},
                                {0,20,21,22,23,24}}; 

    int max_value = getMaxValue(f);
    cout << "max_value: " << max_value << endl;
}
