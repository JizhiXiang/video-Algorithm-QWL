#include<iostream>
#include<algorithm>
using namespace std;

/*
代码作者：机智翔学长（B站，CSDN同名）
《算法设计与分析》（屈婉玲）视频地址：https://www.bilibili.com/video/av7134874

写在前面的话：
以前学习过该门课程，但没有认真实现相应的代码，仅仅以考试为目的。
现在想改过自新，重新学习，感谢互联网，感谢屈婉玲老师。

暂时的打算：
将该课程中所涉及到的算法，根据视频出现的顺序，实现一遍，录视频，传代码。
水平有限，若有不正确的地方，请指正。因为现在也有其他任务在身，不一定保证按时更新，但我尽量坚持下去，我们一起学习，希望能帮到你。
*/

bool cmp(int x, int y){
    //默认情况，也可以不写，从小到大排序。
    //若写成 return x>y; 则从大到小排序。
    return x<y; 
}

int getMinTime(int t[], int n){
    //t为数组，n为数组长度
    //例1，调度问题，总完成时间最短. PPT的P2
    //贪心算法

    //先从小到大排序
    sort(t, t+n, cmp);  //默认情况（顺序排列）cmp可以不写

    int sum_time = 0; //最终时间
    int tmp = 0; //用来存储从最开始到第i个任务完成所需时间。
    for(int i=0;i<n;i++){
        tmp += t[i];
        sum_time += tmp;
    }
    return sum_time;
}

int main(){

    int t[5] = {3, 8, 5, 10, 15}; //定义长度为5的数组t，并初始化. 任务对应所需的时间
    int n = sizeof(t)/sizeof(int); //数组长度
    
    int res = getMinTime(t, n);
    cout << res << endl;

}