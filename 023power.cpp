#include<iostream>
using namespace std;

//a的n次幂,n>=0
int power(int a,int n){
    if(n==1)
        return a;
    else if(n==0)
        return 1;
    if(n%2==0){
        int x = power(a,n/2);
        return x*x;
    }else{
        int x = power(a,(n-1)/2);
        return x*x*a;
    }
}

float func(int a,int n){
    if(n<0){
        return 1.0/power(a,-n);
    }else{
        return power(a,n);
    }
}

int main(){
    int a = 2;
    for(int n=-2;n<=2;n++){
        float res = func(a,n);
        cout << a << "^" << n <<"=\t" << res << endl;
    }
}