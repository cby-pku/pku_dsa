/*
作为一名海军提督，Pachi将指挥一支舰队向既定海域出击！
Pachi已经得到了海域的地图，地图上标识了一些既定目标和它们之间的一些单向航线。如果我们把既定目标看作点、航线看作边，那么海域就是一张有向图。不幸的是，Pachi是一个会迷路的提督QAQ，所以他在包含环(圈)的海域中必须小心谨慎，而在无环的海域中则可以大展身手。
受限于战时的消息传递方式，海域的地图只能以若干整数构成的数据的形式给出。作为舰队的通讯员，在出击之前，请你告诉提督海域中是否包含环。

请你判断给定有向图中是否包含环
输入
每个测试点包含多组数据。
第一行是数据组数T。
每组数据的第一行两个整数N，M，表示顶点数、边数。
接下来M行每行2个不相等的整数x,y，表示从顶点x到y有一条单向边（所有顶点使用1~N的整数表示）。

1<=N<=100000，1<=M<=500000，1<=T<=5
注意：输入的有向图不一定是连通的。
输出
输出包含T行。
对于每组数据，输出Yes表示图有环，输出No表示无环。
*/
/*判圈算法的考察*/
/*使用深度优先搜索检测环的存在*/
#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;
class Graph{
private:
    bool dfs(int node,vector<bool>&visited,vector<bool>&recursionStack){
        visited[node]=true;
        recursionStack[node]=true;
        for(int neighbor:adjacencyList[node]){
            /*遍历邻接矩阵*/
            if(!visited[neighbor])
            {if(dfs(neighbor,visited,recursionStack))return true;}
            /*如果访问过（可能是到头了，但也可能是出圈了，所以需要一个额外记录*/
            else if(recursionStack[neighbor])return true;
        }
        recursionStack[node]=false;/*回溯*/
        /*只对recursionStack进行回溯*/
        return false;
    }
public:
    int vertices;//顶点
    vector<vector<int>>adjacencyList;//建立邻接表
    Graph(int v):vertices(v),adjacencyList(v+1){}//邻接表要多设1个大小
    void addEdge(int u,int v){
        adjacencyList[u].push_back(v);//进而实现建立从u到v的邻接表
    }
    bool containsCycle(){
        vector<bool> visited(vertices+1,false);//记录是否访问过，多开一个为了建立编号i之间的直接联系
        vector<bool>recursionStack(vertices+1,false);
        for(int i=1;i<=vertices;++i){
            /*对每个都要遍历遍*/
            if(!visited[i]&&dfs(i,visited,recursionStack))
            return true;
        }
        return false;
    }

};
/*一些思考，如果多个点指向同一个点也没问题，因为如果有一个点事构环的话，早在一开始遍历这多个点中的一个时就会遍历到这个环进而return false*/
/*想这些多组数据，尽量都建类，这样的话每一组测试数据只需要重新新建一个对象即可，无需重新main函数里显示init;Debug也方便*/
int main(){
    int T;
    cin>>T;
    while(T--){
        int N,M;
        cin>>N>>M;
        Graph graph(N);
        for(int i=0;i<M;++i){
            int x,y;
            cin>>x>>y;
            graph.addEdge(x,y);
        }
        if(graph.containsCycle()){
            cout<<"Yes"<<endl;
        }
        else{
            cout<<"No"<<endl;
        }
    }return 0;
}