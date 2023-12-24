/*
描述
动物王国中有三类动物A,B,C，这三类动物的食物链构成了有趣的环形。A吃B， B吃C，C吃A。
现有N个动物，以1－N编号。每个动物都是A,B,C中的一种，但是我们并不知道它到底是哪一种。
有人用两种说法对这N个动物所构成的食物链关系进行描述：
第一种说法是"1 X Y"，表示X和Y是同类。
第二种说法是"2 X Y"，表示X吃Y。
此人对N个动物，用上述两种说法，一句接一句地说出K句话，这K句话有的是真的，有的是假的。当一句话满足下列三条之一时，这句话就是假话，否则就是真话。
1） 当前的话与前面的某些真的话冲突，就是假话；
2） 当前的话中X或Y比N大，就是假话；
3） 当前的话表示X吃X，就是假话。
你的任务是根据给定的N（1 <= N <= 50,000）和K句话（0 <= K <= 100,000），输出假话的总数。
输入
第一行是两个整数N和K，以一个空格分隔。
以下K行每行是三个正整数 D，X，Y，两数之间用一个空格隔开，其中D表示说法的种类。
若D=1，则表示X和Y是同类。
若D=2，则表示X吃Y。
输出
只有一个整数，表示假话的数目。
*/
/* 我盲猜这应该是个并查集的问题
关键问题有：1. 如果op=1 就把X 和 Y合并
2. 如果 op=2 就查询一下 X 和 Y的父类
好现在关键问题是，如何在并查集中定义多个关系
这也是之前的题目采取的一些思路
ans : 定义虚拟天敌的概念: 如果x是y的天敌，那么x 与 y+n是同类，并由此推出循环嵌套的天敌关系！
相当于每次合并都是合并了两个圈
*/
#include<iostream>
#include<vector>
using namespace std;
#define N 50000
int f[3*N+1];
/*! 最简单的设计思路，关键是怎么来读取*/
int find(int x){
    return (x == f[x] ? x : f[x] = find ( f[x] ));
} 

void merge(int x, int y)
{
    f [ find(x) ] = find(y);
}

int main()
{
    for(int i=1;i<=N*3;i++){
        f[i]=i;
    }
    int n,k;
    cin>>n>>k;
    int ans=0;
    while(k--){
        int op,x,y;
        cin >> op >> x >> y;
        if( x > n || y > n){
            ans++;continue;
        }
        if(op==1){
            if(find(x)==find(y+n) || find(x)==find(y+2*n))
            {
                ans++;continue;
            }
            /* 不是天敌的时候*/
            merge(x,y);merge(x+n,y+n);merge(x+2*n,y+2*n);
        }
        else{
            if(x==y || find(x)==find(y) || find(x)==find(y+2*n)){
                ans++;continue;
            }
            merge(x,y+n);merge(x+n,y+2*n);merge(x+2*n,y);
        }
    }
    cout<<ans<<endl;
}