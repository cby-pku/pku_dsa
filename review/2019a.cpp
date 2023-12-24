/*
Huffman Encoding Tree
描述


构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：

                                     Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)

Wi:每个节点的权值。

Li:根节点到第i个外部叶子节点的距离。

编程计算最小外部路径长度总和。

输入
第一行输入一个整数t，代表测试数据的组数。
对于每组测试数据，第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。
2<=N<=100
输出
输出最小外部路径长度总和。
*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;//外部节点的个数
        //用向量存储权重
        vector<int>weights(n);
        for(int i=0;i<n;++i){
            cin>>weights[i];
        }
        /*huffman tree的基本准则是，不断选取最小的两个，然后读取，插入到新的里面，直到最后没有*/
        /*这里我们用最小堆实现*/
        priority_queue<int,vector<int>,greater<int>>minHeap(weights.begin(),weights.end());
        long long totalCost=0;
        while(minHeap.size()>1){ /*注意这里是大于1，不可能归0的！*/
            int min1=minHeap.top();
            minHeap.pop();
            int min2=minHeap.top();
            minHeap.pop();
            int sum=min1+min2;
            totalCost+=sum;
            minHeap.push(sum);
        }
        cout<<totalCost<<endl;

    }
}