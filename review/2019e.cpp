/*
描述
哞林匹克越野滑雪项目可以用一个M*N的数组表示(1<=m,n<=500)，数组元素的范围为0到1000000000，表示该点的海拔高度。

这个数组中的一些格子被指定为比赛的路径点。一头牛可以从一个格点滑到上下左右的四个相邻个点，如果这些点的高度差不超过D。滑雪路径的难度等级是使得所有的路径点都可以以这种方式连通的D的最小值。



输入
第一行：M和N
第二行到第M+1行: 每行包括N个数字，代表海拔高度。

M+2到2M+1行: 每行N个数字，0或1，表示这个点是不是路径点
输出
最小的D
样例输入
*/
/*
STD: 最小生成树，将格子看成权，将相邻的格子之间的难度系数看成边权，得到一个无向图。然后求出包含给出关键点的最小生成树，此处的最小的生成树不是对边求和，而是找出边的最大值。对每个联通块记录其中包含的关键点个数，当某个联通块包含的关键点个数等于最大值了，那么此时就可以退出程序了
Another: 从一个关键点出发，BFS求他到每个点最短(最小难度值)路径，再输出它们的最大值。
若有3个关键点A,B,C，其中A到B、C的路径难度值最小分别为x、y
而B->C的可由B->A再A->C，
该线路的最大难度值为max(x,y)
那么B到C的最小难度值一定不会超过x、y的最大值
*/
/* 首先因为可以是连续值，所以可以采用二分查找，因为又涉及到图遍历，所以干脆可以用BFS的方法*/
#include<iostream>
#include<queue>
#include<cstring>
using namespace std;
#define pii pair<int,int>

int n,m,info[502][502]={{0}};
bool checkpoint[502][502]={{0}};

int dx[]={1,0,-1,0};
int dy[]={0,1,0,-1};

pii start;//声明一个起始处
/*判断在给定难度下。是否所有的关键点都可以相连*/
bool connect(int d){
    queue<pii>q;
    q.push(start);
    bool visit[502][502]={{false}};
    visit[start.first][start.second]=true;

    //开始BFS的主程序
    while(!q.empty()){
        pii cur=q.front();
        q.pop();
        for(int i=0;i<4;++i){
            int xx=cur.first+dx[i];
            int yy=cur.second+dy[i];
            if(visit[xx][yy]||abs(info[xx][yy]-info[cur.first][cur.second])>d)
            continue;//如果访问过，或者距离差大于0，就直接跳过
            visit[xx][yy]=true;
            q.push({xx,yy});
        }
    }
    /*最后检查所有的关键点都被遍历了*/
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            if(checkpoint[i][j]&&!visit[i][j])
            return false;
        }
    }
    return true;
}
int main(){
    int l=-1;int r=0xc0c0c0c0,mid;
    memset(info,0xc0,sizeof(info));//先进行一波初始化
    cin>>n>>m;
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>info[i][j];
            r=max(r,info[i][j]+1);//更新二分搜索右边界
        }
    }
    for(int i=1;i<=n;++i){
        for(int j=1;j<=m;++j){
            cin>>checkpoint[i][j];
            if(checkpoint[i][j]) start=make_pair(i,j);
        }
    }
    /*二分搜索查最小d*/
    while(l+1!=r){
        mid=(r-l)/2+l;
        if(connect(mid)){
            r=mid;
        }
        else l=mid;
    }
    cout<<r<<endl;
    /*二分搜索和BFS的逻辑可以解耦合*/
}