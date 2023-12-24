/*
总时间限制: 10000ms 单个测试点时间限制: 1000ms 内存限制: 524288kB
描述
对于一棵树 T，你需要给它加一些边，使得它成为一张完全图 G
（完全图指的是每两个点之间有一条边的无向图），
使它的每条边边权都是整数，边权总和最小，且 G 的唯一最小生成树是 T。

对于 20% 的数据，N≤10。
对于 50% 的数据，N≤1000。
对于 100% 的数据，N≤100000, 1≤d[i]≤100000.

输入
第一行 N 表示树 T 的点数
接下来 N-1 行每行三个整数 s[i] t[i] d[i]，表示 T 中有一条连接 s[i] 和 t[i] 且权值为 d[i] 的无向边。
数据保证输入构成一棵树。
输出
输出仅一个数，表示最小的完全图 G 的边权和。
*/
/*只需要让添加的边，等于从两个点相互连接的最短路径就可以*/
/*是指这两个点的所有连通分量之间，除了和两个边自己的联系之外，
其他的所有连通分量都连一条边权为（cur.first+1）的边，保证自己是最小的
再复习一下对应的Kruskal算法
*/

#include<iostream>
#include<queue>
using namespace std;
#define int long long
#define pipii pair<int,pair<int,int>>
/* 可能会大于32位整数范围 */
int f[100010],cnt[100010];
int find(int x){
	return (x==f[x]? x : f[x]=find(f[x]));
}
void merge(int x, int y){
	/* 先找到father节点*/
	int fx=find(x);int fy=find(y);/*要存一个中间变量*/
	/*father point 结合*/
	f[fx]=fy;/*要保存好父节点，因为这个过程会改变，下面cnt的合并就不准了*/
	cnt[fy]+=cnt[fx];
}
signed main()
{
	int n;
	cin>> n;
	for(int i=1;i<=n;++i){
		/* Init */
		f[i]=i;
		cnt[i]=1;
	}
	priority_queue<pipii,vector<pipii>,greater<pipii>>q;
	/*注意优先队列的声明方式*/
	for(int i=1;i<n;++i){
		int a,b,w;
		cin>>a>>b>>w;
		q.push({w,{a,b}});
	}
	int ans=0;
	while(!q.empty()){
		pipii cur=q.top();
		q.pop();
		ans+= cur.first;/*首先加上本边权重*/
		int fx=find(cur.second.first),fy=find(cur.second.second);
		/* 为什么不会重复计算呢*/
		ans += (cnt[fx]*cnt[fy]-1)*(cur.first+1);
		merge(fx,fy);/*合并等价类*/
	}
	cout<<ans<<endl;
}
