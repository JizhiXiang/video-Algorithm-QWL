/**
 * Filename：最邻近点对
 * 代码来源于https://github.com/king-wk/AlgorithmDesign/blob/master/Exercise3_C%2B%2B.cpp
 * Description： 采用分治算法
 *               分解：对所有的点按照x坐标、y坐标从小到大排序，
 *                     根据下标分解，使点集分为两个集合
 *                     递归寻找两个集合的最近点对，取它们最小值d
 *               合并：以中间点的x坐标mid划分一个[mid-d,mid+d]的区域，获取区域中所有的点
 *                     遍历这些点，看是否存在距离小于d的点对
 */
#include <iostream>
#include <cmath>
#include <algorithm>
#include <iomanip>
using namespace std;
/* 一个点对的最大距离 */
const double INF = 1e20;
/* 点数 */
const int N = 30001;
/* 点 */
struct Point {
	double	x;
	double	y;
}
point[N];
/* 实际输入的点数 */
int n;
/* 用于记录位于区域[mid-d,mid+d]的点 */
int tmpt[N];
/**
 * 按照x坐标、y坐标的顺序比较两个点的大小
 */
bool cmpxy(const Point &a, const Point &b) {
	if ( a.x != b.x ) {  //如果两个点x不相同，则按照x比较大小。否则按照y比较
		return(a.x < b.x);
	}
	return(a.y < b.y);
}
/**
 * 按照y坐标比较两个点的大小
 */
bool cmpy(const int &a, const int &b) {
	return(point[a].y < point[b].y);
}
/**
 * 返回两个double值中的最小值
 */
double min(double a, double b) {
	return(a < b ? a : b);
}
/**
 * 输出两个位置的点的距离的平方
 */
double dis(int i, int j) {
	double	dis_x = point[i].x - point[j].x;
	double	dis_y = point[i].y - point[j].y;
	return(dis_x * dis_x + dis_y * dis_y);
}
/**
 * 返回集合中的最小距离点对的距离
 * left：集合的左边界点位置，right：集合的右边界位置
 * 使用分治算法
 */
double Closest_Pair(int left, int right) {  //left和right表示左右边界为第几个点/id号（并不是x坐标）
	/* 最小距离d */
	double d = INF;
	/* 如果只有一个点，直接返回最小距离d */
	if (left == right) {
		return(d);
	}
	/* 如果只有两个点，直接返回两个点的距离 */
	if (left + 1 == right) {
		return(dis(left, right));
	}
	/* 集合中间点的位置mid，根据mid将集合分成两部分 */
	int mid = (left + right) / 2;
	/* 返回左边集合的最小距离点对的距离 */
	double d1 = Closest_Pair(left, mid);
	/* 返回右边集合的最小距离点对的距离 */
	double d2 = Closest_Pair(mid + 1, right);
	/* 取两个最小距离的最小值 */
	d = min(d1, d2);
	int i, j, k = 0;
	/* 获取区域[mid-d,mid+d]的所有点 */
	for (i = left; i <= right; i++) {
		if (fabs(point[mid].x - point[i].x) <= d) {  //fabs()是对浮点数取绝对值
			tmpt[k++] = i;
		}
	}
	/* 将区域中的点按照y坐标排序 */
	sort(tmpt, tmpt + k, cmpy);
	/* 遍历这个区域中的点，找到最小距离 */
	for (i = 0; i < k; i++) {
		/*
		 * 如果i点与j点的y坐标的距离大于d，那么i点与j点之后的点y坐标距离一定也大于d
		 * 两个点的y坐标距离大于d，那么两个点的距离一定大于d，可以提前结束遍历
		 */
		for (j = i + 1; j < k && point[tmpt[j]].y - point[tmpt[i]].y < d; j++) {
			double d3 = dis(tmpt[i], tmpt[j]);  //tmpt[i]指的是i对应的那个点的id号
			if ( d > d3 ) {
				/*
				 * 如果有两个点对之间的距离小于d
				 * 那么得到新的最小距离
				 */
				d = d3;
			}
		}
	}
	return(d);
}
int main() {
	// cin >> n;
    int n = 8;
    double a[8][2] = {{1,1},{2,2},{4,4},{8,8},{2,2.8},{5,6},{7,9},{11,11}};
	for (int i = 0; i < n; i++) {
		// cin >> point[i].x >> point[i].y;
        point[i].x = a[i][0];
        point[i].y = a[i][1];
	}
	/* 根据点集的x坐标、y坐标将点集排序 */
	sort(point, point + n, cmpxy);
	/* 输出最邻近点对距离的平方，并小数点后两位 */
	cout << fixed << setprecision(2) << Closest_Pair(0, n - 1);
	return(0);
}