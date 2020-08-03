#include<iostream>
using namespace std;

void hanoi(char A,char C,int n, char B){ //将n个盘子从A全部帮到C中，B为辅助
    if(n==1){
        cout << "move "<< n <<"st,from " << A << " to " << C <<endl;
    }else{
        hanoi(A, B, n-1, C);
        cout << "move "<< n <<"st,from " << A << " to " << C <<endl;
        hanoi(B, C, n-1, A);
    }
}

int main(){
    hanoi('A', 'C', 3, 'B');
}