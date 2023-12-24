/*
世界上有许多宗教，你感兴趣的是你学校里的同学信仰多少种宗教。
你的学校有n名学生（0 < n <= 50000），你不太可能询问每个人的宗教信仰，因为他们不太愿意透露。但是当你同时找到2名学生，他们却愿意告诉你他们是否信仰同一宗教，你可以通过很多这样的询问估算学校里的宗教数目的上限。你可以认为每名学生只会信仰最多一种宗教。


输入
输入包括多组数据。
每组数据的第一行包括n和m，0 <= m <= n(n-1)/2，其后m行每行包括两个数字i和j，表示学生i和学生j信仰同一宗教，学生被标号为1至n。输入以一行 n = m = 0 作为结束。
输出
对于每组数据，先输出它的编号（从1开始），接着输出学生信仰的不同宗教的数目上限。
*/
// 初始状态下，应该每个人都是有一种信仰，所以最后就是往下减
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
class Union{
private:
    vector<int>parent;
    vector<int>rank;
public:
    Union(int n):parent(n+1),rank(n+1,1){
        for(int i=1;i<=n;++i){
            parent[i]=i;
        }
    }
    int find(int x){
        if(parent[x]!=x){parent[x]=find(parent[x]);}
        return parent[x];
    }
    void unionsets(int x,int y){
        int rootX=find(x);
        int rootY=find(y);
        if(rootX!=rootY){
            if(rank[rootX]>rank[rootY])
            {parent[rootY]=rootX;}
            else if(rank[rootX]<rank[rootY]){
                parent[rootX]=rootY;
            }
            else{
                parent[rootY]=rootX;
                rank[rootX]++;
            }
        }
    }
};
int main(){
    int caseNum=1;
    while(1){
        int n,m;
        cin>>n>>m;
        if((n==0) && (m==0))
            break;
        Union uf(n);
        
        for(int i=0;i<m;++i){
            int x,y;
            cin>>x>>y;
            uf.unionsets(x,y);
        }
        /*这个如何输出非常巧妙*/
        vector<int>roots;
        for(int i=1;i<=n;++i){
            roots.push_back(uf.find(i));
        }
        sort(roots.begin(),roots.end());
        roots.erase(unique(roots.begin(),roots.end()),roots.end());
        cout<<"Case "<<caseNum<<": "<<roots.size()<<endl;
        caseNum++;
    }
    return 0;
}