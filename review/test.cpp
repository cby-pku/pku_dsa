#include<iostream>
#include<stack>
#include<vector>
#include<queue>
#include<cstring>
using namespace std;

int n,m,k;
bool no_path=false;
#define pii pair<int, int>
vector<pii>edge[1001];

bool possible_price(int x){
    /*
SPFA算法迭代：

循环队列q，每次取出队头的基站作为当前松弛的起点。
对于当前基站的所有邻接基站，尝试松弛路径长度。如果通过当前基站到达邻接基站的路径上电缆费用超过x，那么在路径长度上加1，否则路径长度不变。
如果通过当前基站松弛得到的路径长度比之前记录的路径长度更小，更新路径长度，并将邻接基站加入队列。
如果队列为空，说明没有可以继续松弛的基站，退出循环。
判断是否存在路径：

如果1号基站到N号基站的路径长度仍然是无穷大，说明不存在从1到N的路径，将no_path标记为true。
返回1号基站到N号基站的路径长度是否不超过K*/
    queue<int>q;
    q.push(1);
    bool in_queue[1001]={false};
    in_queue[1]=true;/*基站需要不断尝试*/
    int dis[1001];
    memset(dis,0x3f,sizeof(dis));
    dis[1]=0;
    while(!q.empty()){
        int cur=q.front();q.pop();
        in_queue[cur]=false;/*但是中间站点可以随意遍历*/
        for(auto e:edge[cur]){
            if(dis[e.second]>dis[cur]+(e.first>x)){
                /*大于权值，果断纳入，直接松弛掉*/
                dis[e.second]=dis[cur]+(e.first>x);
                /*而且可以直接松弛两类*/
                if(!in_queue[e.second]){
                    /*没有遍历过，那就加入*/
                    in_queue[e.second]=true;
                    q.push(e.second);
                }
            }
        }
    }
    if(dis[n]==0x3f3f3f3f)
        no_path=true;
    return dis[n]<=k;
}


int main(){
    cin>>n>>m>>k;
    int l=-1,r=-1,mid=0;
    for(int i=0;i<m;++i){
        int a,b,w;
        cin>>a>>b>>w;
        edge[a].push_back({w,b});
        edge[b].push_back({w,a});
        r=max(r,w+1);
    }
    while(l+1!=r){
        mid=l+(r-l)/2;
        if(possible_price(mid))
        {
            r=mid;
        }
        else{
            l=mid;
        }
    }
    cout<<(no_path?-1:r)<<endl;
}