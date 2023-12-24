/*
定义一个数组，初始化为空。在数组上执行两种操作：

1、增添1个元素，把1个新的元素放入数组。

2、输出并删除数组中最小的数。

使用堆结构实现上述功能的高效算法。

输入
第一行输入一个整数t，代表测试数据的组数。
对于每组测试数据，第一行输入一个整数n，代表操作的次数。
每次操作首先输入一个整数type。
当type=1，增添操作，接着输入一个整数u，代表要插入的元素。
当type=2，输出删除操作，输出并删除数组中最小的元素。
1<=n<=100000。
输出
每次删除操作输出被删除的数字。
*/

#include<iostream>
#include<queue>
using namespace std;
int main(){
    int t;
    cin>>t; //输入组数
    while(t--){
        int n;
        cin>>n;
        priority_queue<int,vector<int>,greater<int>>minHeap;//最小堆
        for (int i=0;i<n;++i){
            int type;
            cin>>type;
            if(type==1){//执行插入操作
                int u;
                cin>>u;
                minHeap.push(u);
            }
            else if(type==2){
                if(!minHeap.empty()){
                    int minValue=minHeap.top();
                    minHeap.pop();
                    cout<<minValue<<endl;
                }
            }
        }
    }
    return 0;
}