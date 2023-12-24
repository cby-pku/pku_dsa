/*
2020B:距离排序
查看提交统计提问
总时间限制: 1000ms 内存限制: 65536kB
描述
给出三维空间中的n个点（不超过10个）,求出n个点两两之间的距离,并按距离由大到小依次输出两个点的坐标及它们之间的距离。

输入
输入包括两行，第一行包含一个整数n表示点的个数，第二行包含每个点的坐标(坐标都是整数)。点的坐标的范围是0到100，输入数据中不存在坐标相同的点。
输出
对于大小为n的输入数据，输出n*(n-1)/2行格式如下的距离信息：
(x1,y1,z1)-(x2,y2,z2)=距离
其中距离保留到数点后面2位。
(用cout输出时保留到小数点后2位的方法:cout<
*/
//这个题太经典了用结构体，但是怎么写更好，需要学习
/*C++高级属性：stablesort的直接调用，高级遍历技巧*/
#include<iostream>
#include<vector>
#include<math.h>
#include<algorithm>
#include<stdio.h>
using namespace std;
struct Point{
    int x,y,z;
};
double CalculateDistance(const Point&x1,const Point&x2){
    int dx=x1.x-x2.x;
    int dy=x1.y-x2.y;
    int dz=x1.z-x2.z;
    return sqrt(dx*dx+dy*dy+dz*dz);
}
struct Info{/*专门开一个数组存储点之间的距离*/
    Point p1,p2;
    double distance;
};
bool compareDistance(const Info&point1,const Info&point2){
    return point1.distance>point2.distance;
}
int main(){
    int n;
    cin>>n;
    vector<Point>points(n);
    for(int i=0;i<n;++i){
        cin>>points[i].x>>points[i].y>>points[i].z;
    }
    vector<Info>Distances;
    for(int i=0;i<n-1;++i){
        for(int j=i+1;j<n;++j){/*最小一层是点，点和距离组成了 info*/
            double distance=CalculateDistance(points[i],points[j]);
            Distances.push_back({points[i],points[j],distance});
        }
    }
    stable_sort(Distances.begin(),Distances.end(),compareDistance);
    for(const Info& info:Distances){
        printf("(%d,%d,%d)-(%d,%d,%d)=%.2f\n", info.p1.x, info.p1.y, info.p1.z, info.p2.x, info.p2.y,info.p2.z, info.distance);
    }
}