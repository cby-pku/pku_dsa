/*
一个城市中有两个犯罪团伙A和B，你需要帮助警察判断任意两起案件是否是同一个犯罪团伙所为，警察所获得的信息是有限的。假设现在有N起案件（N<=100000），编号为1到N，每起案件由团伙A或团伙B所为。你将按时间顺序获得M条信息（M<=100000），这些信息分为两类：
1. D [a] [b]
其中[a]和[b]表示两起案件的编号，这条信息表明它们属于不同的团伙所为

2. A [a] [b]
其中[a]和[b]表示两起案件的编号，这条信息需要你回答[a]和[b]是否是同一个团伙所为
注意你获得信息的时间是有先后顺序的，在回答的时候只能根据已经接收到的信息做出判断。


输入
第一行是测试数据的数量T（1<=T<=20）。
每组测试数据的第一行包括两个数N和M，分别表示案件的数量和信息的数量，其后M行表示按时间顺序收到的M条信息。
输出
对于每条需要回答的信息，你需要输出一行答案。如果是同一个团伙所为，回答"In the same gang."，如果不是，回答"In different gangs."，如果不确定，回答”Not sure yet."。


*/
//这盲猜用并查集实现！



//特别地要处理不确定的情况！
#include<iostream>
#include<vector>
using namespace std;
class DisjointUnion{
private:
    vector<int>parent;
    vector<int>rank;
public:
//注意学习并查集的写法
    DisjointUnion(int n):parent(n+1),rank(n+1,1){
        for(int i=1;i<=n;++i){
            parent[i]=i;//开大一个空间纯粹是为了与标号对应起来
        }
    }
    int find(int x){
        if(parent[x]!=x){//因为初始化的时候都应该是一一对应的，是后续出现了打乱的情况
            parent[x]=find(parent[x]);
        }
        return parent[x];
    }
    void unionSets(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY]){
                parent[rootY]=rootX;
            }
            else if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
            }
            else{
                parent[rootY]=rootX;
                rank[rootX]++;//只有相等的时候才把同级相加，而后把父节点++ 以此示意树更大，妙！
            }
        }
    }

};
int main(){
    int T;
    cin>>T;
    while(T--){
        int N;int M;
        cin>>N>>M;
        DisjointUnion dsu(2*N);//这里也要同步开大两倍，小心数组越界！
        for(int i=0;i<M;++i){
            char type;
            int a,b;
            cin>>type>>a>>b;
            if(type=='D'){
                dsu.unionSets(a+N,b);
                dsu.unionSets(a,b+N);
            }
            else if(type=='A'){
                
                if(dsu.find(a)==dsu.find(b)){
                    //可以额外用一个merge来处理
                    cout<<"In the same gang."<<endl;
                }
                else if ((dsu.find(a+N)==dsu.find(b))||dsu.find(a)==dsu.find(b+N)){
                    cout<<"In different gangs."<<endl;
                }
                else{
                    cout<<"Not sure yet."<<endl;
                }
            }
        }
    }
}
/*
看这篇解释+画图+结合83 79行理解筛选条件！
https://blog.csdn.net/csyifanZhang/article/details/104490671?spm=1001.2101.3001.6661.1&utm_medium=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-104490671-blog-53426071.235%5Ev38%5Epc_relevant_anti_t3_base&depth_1-utm_source=distribute.pc_relevant_t0.none-task-blog-2%7Edefault%7ECTRLIST%7ERate-1-104490671-blog-53426071.235%5Ev38%5Epc_relevant_anti_t3_base&utm_relevant_index=1
*/