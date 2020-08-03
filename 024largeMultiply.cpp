#include <iostream>
#include <string>
#include <math.h>
int count=0;
using namespace std;
void SameNumber();
void UnSameNumber();
int SIGN(long A);
long CalculateSame(long X, long Y, int n);
long CalculateUnSame(long X, long Y, int xn, int yn);


//代码来源于：https://www.cnblogs.com/little-kwy/archive/2017/09/30/7613642.html
//原理可看：分治法的经典问题——大整数相乘 https://blog.csdn.net/jeffleo/article/details/53446095
int main()
{
    SameNumber();
    UnSameNumber();
    return (0);
}
 
int SIGN(long A)
{
    return A > 0 ? 1 : -1;
}
 
void SameNumber()
{   
    cout<<"idea!"<<endl;  //理想状态用法！  
    cout<<"input 2 numbers:\nX=";  //请输入两个大整数：
    long X = 0;
    cin>>X;
    cout<<"Y=";
    long Y = 0;
    cin>>Y;
    cout<<"input length, n=";  //请输入两个大整数的长度： //要输入偶数，否则会出错。但不一定完全为n，也可以n-2，因为/2后差不多用来二分就行
    int n = 0;
    cin>>n;
 
    long sum = CalculateSame(X, Y, n);
 
    cout<<"normal X*Y="<<X<<"*"<<Y<<"="<<X * Y<<endl;  //普通乘法
    cout<<"divide X*Y="<<X<<"*"<<Y<<"="<<sum<<endl;  //分治乘法
}
 
long CalculateSame(long X, long Y, int n)
{
    int sign = SIGN(X) * SIGN(Y);
 
    X = abs(X);
    Y = abs(Y);
    if (X == 0 || Y == 0)
        return 0;
    else if (n == 1)
        return sign * X * Y;
    else
    {
        long A = (long)(X / pow(10, n / 2));
        long B = (X % (long)pow(10, n / 2));
        long C = (long)(Y / pow(10, n / 2));
        long D = (Y % (long)pow(10, n / 2));
 
        long AC = CalculateSame(A, C, n / 2);
        long BD = CalculateSame(B, D, n / 2);
        long ABCD = CalculateSame((A - B), (D - C), n / 2) + AC + BD;
         
        cout<<"A="<<A<<" B="<<B<<" C="<<C<<" D="<<D<<endl;
 
        return (long)(sign * (AC * pow(10, n) + ABCD * pow(10, n / 2) + BD));
    }
}
 
void UnSameNumber()
{
    cout<<"\nno idea!"<<endl;;  //非理想状态用法！
    cout<<"input 2 numbers:\nX=";  //请输入两个大整数：
    long X = 0;
    cin>>X;
    cout<<"Y=";
    long Y = 0;
    cin>>Y;
    cout<<"length of x, xn=";  //请输入两个大整数的长度：
    int xn = 0;
    cin>>xn;
    cout<<"length of y, yn=";  //请输入两个大整数的长度：
    int yn = 0;
    cin>>yn;
 
    long sum = CalculateUnSame(X, Y, xn,yn);
 
    cout<<"normal X*Y="<<X<<"*"<<Y<<"="<<X * Y<<endl;
    cout<<"divide X*Y="<<X<<"*"<<Y<<"="<<sum<<endl;
}
 
long CalculateUnSame(long X, long Y, int xn, int yn)
{
    if (X == 0 || Y == 0)
        return 0;
    else if ((xn == 1 && yn == 1) || xn == 1 || yn == 1)
        return X * Y;
    else
    {
        int xn0 = xn / 2, yn0 = yn / 2;
        int xn1 = xn - xn0, yn1 = yn - yn0;
 
        long A = (long)(X / pow(10, xn0));
        long B = (long)(X % (long)pow(10, xn0));
        long C = (long)(Y / pow(10, yn0));
        long D = (long)(Y % (long)pow(10, yn0));
 
        long AC = CalculateUnSame(A, C, xn1, yn1);
        long BD = CalculateUnSame(B, D, xn0, yn0);
        long ABCD = CalculateUnSame((long)(A * pow(10, xn0) - B), (long)(D - C * pow(10, yn0)), xn1, yn1);
 
        return (long)(2 * AC * pow(10, (xn0 + yn0)) + ABCD + 2 * BD);
    }
}