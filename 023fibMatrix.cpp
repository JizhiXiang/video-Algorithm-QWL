#include<iostream>
#include<string.h>
using namespace std;

int** matrix(int **a,int **b){
    int **c = new int* [2];  //创建c矩阵，存储a*b的结果
    for(int i=0;i<2;i++){
        c[i] = new int[2];
    }
    for(int i=0;i<2;i++){  //计算矩阵c
        for(int j=0;j<2;j++){
            c[i][j] = a[i][0]*b[0][j] + a[i][1]*b[1][j];
        }
    }
    return c;
}

int** power(int **a, int n){ //矩阵a的n次幂 n>=1
    if(n==1)
        return a;
    if(n%2==0){  //n为偶数
        int** tmp = power(a,n/2);  //一半的结果
        return matrix(tmp,tmp);
    }else{
        int** tmp = power(a,(n-1)/2);
        int** tmp2 = matrix(tmp,tmp);
        return matrix(tmp2, a);  //要多乘以一个a
    }
}

int fib(int n){
    if(n==0)
        return 0;
    else if(n==1)
        return 1;
    int res;
    int** base = new int* [2];
    for(int i=0;i<2;i++){
        base[i] = new int[2];
        memset(base[i], 0, 2*sizeof(int));
    }
    base[0][0] = 1;
    base[0][1] = 1;
    base[1][0] = 1;
    int** out = power(base, n);
    res = out[0][1];

    for(int i=0;i<2;i++)
        delete[] base[i];
    delete[] base;

    return res;
}

int main(){
    for(int i=0;i<=10;i++){
        int res = fib(i);
        cout << res << " ";
    }
}

//C++中将二维数组(静态的和动态的)作为函数的参数传递 https://www.cnblogs.com/usa007lhy/p/3286186.html
//用vector来求解fib矩阵可以看 https://blog.csdn.net/Poe2017/article/details/82500439
//其他参考 https://blog.csdn.net/xygy8860/article/details/47087687