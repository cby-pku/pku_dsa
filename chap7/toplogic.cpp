/*
描述
给出一个图的结构，输出其拓扑排序序列，要求在同等条件下，编号小的顶点在前

输入
若干行整数，第一行有2个数，分别为顶点数v和弧数a，接下来有a行，每一行有2个数，分别是该条弧所关联的两个顶点编号
输出
若干个空格隔开的顶点构成的序列(用小写字母)
*/

//拓扑排序！这也是我一直想练的！又是一个牢记！
#include<algorithm>
#include<iostream>
#include<unordered_map>
using namespace std;
#define MAXN 100010
int n,m;
int head[MAXN],to[MAXN],nxt[MAXN],inDegree[MAXN],idx;
unordered_map<int,bool> printed;

//图的加边函数
inline void addEdge(int u, int v){
    nxt[++idx]=head[u];
    head[u]=idx;
    to[idx]=v;
    inDegree[v]++;
}
int main(){
    cin>>n>>m;
    for(int i=1;i<=m;++i){
        int u,v;cin>>u>>v;
        addEdge(u,v);
    }
    int cnt=0;
    while(cnt<n){
        for(int i=1;i<=n;++i){
            if(inDegree[i]==0&&!printed[i]){
                if(cnt++)cout<<" ";//这是个什么空格输出方法
                cout<<"v"<<i;
                printed[i]=true;
                for(int e=head[i];e;e=nxt[e]){
                    inDegree[to[e]]--;
                }
                break;
            }
        }
    }
}