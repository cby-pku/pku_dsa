/*
Template Review
通过作业题，自主回顾一下基础的算法和遍历方式
*/

/*1. 深度优先周游二叉树*/
// 前序非递归算法
/*
1.遇到一个节点就访问它，并把非空的右子节点压栈，然后深度遍历其左子树（走之前右孩子先入栈）
2. 左子树遍历完毕，弹出节点并访问之，继续遍历 （左子树先入栈）
3. 开始的时候推入一个空指针作为监视哨，作为遍历结束的标志（遇到监视哨就结束）
靠脑子去思考这里面的思路是什么
*/
/*
template<class T> void BinaryTree<T>::PreOrderWithru
(BinaryTreeNode<T>*root){
	using std::stack;
	stack<BinaryTreeNode<T>*>aStack;
	BinaryTreeNode<T>* pointer=root;
	aStack.push(NULL);
	while(pointer){
		Visit(pointer);
		if(pointer->rightchild()!=NULL){
			aStack.push(pointer->rightchild());
		}
		if(pointer->leftchild()!=NULL)
		{
			pointer=pointer->leftchild();
		}
		else{
			pointer=aStack.pop();
		}
	}
}
*/
/*广度优先搜索算法：实现从左到右的同层遍历，只需要用队列来实现，每次遇到一个点，如果左、右有非空结点就入队*/
/*
void BinaryTreeNode<T>::LevelOrder(BinaryTreeNode<T>*root)
{
	using std::queue;
	queue<BinaryTreeNode<T>*>aQueue;
	BinaryTreeNode<T>*pointer=root;
	if(pointer)aQueue.push(pointer);
	while(!aQueue.empty()){
		pointer=aQueue.pop();
		Visit(pointer->value());
		if(pointer->leftchild()){
			aQueue.push(pointer->leftchild());
		}
		if(poiner->rightchild()){
			aQueue.push(pointer->rightchild());
		}
	}
}*/
/* 这里有一道例题*/
/*嗷是拓扑排序，等会记得做一下！*/
/*自己想出来的是印象最深的，也是最不用担心的！*/

/*二叉搜索树的遍历过程*/
//搜索：如果根节点值为K，搜索结束；如果k小于节点，左搜；反之右搜，一直持续到K被找到或者到达树叶
/*二叉搜索树的建立过程：如果相等就直接返回！*/

/*建立二叉搜索树并实现层次遍历*/
/*
#include<iostream>
#include<queue>
using namespace std;
struct TreeNode{
	int value;
	TreeNode* left;
	TreeNode*right;
	TreeNode(int val):value(val),left(nullptr),right(nullptr){}
};
TreeNode* insert(TreeNode*root,int value){
	if(root==nullptr){
		root=new TreeNode(value);
		return root;
	}
	if(value<root->value)
	{
		root->left=insert(root->left,value);
	}
	else if(value>root->value){
		root->right = insert(root->right,value);
	}
	return root;//因为最后要返回插入树的结果，所以肯定是要返回root方便下一个插入哇
}
void levelOrderTree(TreeNode*root){
	if(root==nullptr)return;
	queue<TreeNode*>q;
	q.push(root);
	// 你想，对于每个新节点，它都是子树的根节点，所以肯定是先push进去便于后续的便利的
	while(!q.empty()){
		TreeNode*current=q.front();
		q.pop();
		cout<<current->value<<" ";
		if(current->left!=nullptr)q.push(current->left);
		if(current->right!=nullptr)q.push(current->right);
	}
}

int main(){
	TreeNode*root=nullptr;
	int tmp;
	while(cin>>tmp){
		root=insert(root,tmp);
	}
	levelOrderTree(root);
}
*/

/*优先队列和堆的使用！作业题里还有不少可以去刷刷！*/
/*建立Huffman Tree的过程：
拿走两个字母标记为huffman树，然后把它们的权值相加*/

/*huffman tree的构造由最小堆实现*/
/*就相当于直接用所有的*/
/*
#include<iostream>
#include<queue>
#include<vector>
//最小堆，就是用优先队列实现的
using namespace std;
int main(){
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<int>weights(n);
		for(int i=0;i<n;++i){
			cin>>weights[i];
		}
		long long totalCost=0;
		priority_queue<int,vector<int>,greater<int>>minHeap(weights.begin(),weights.end());
		while(minHeap.size()>1)
		{
			int ans1=minHeap.top();
			minHeap.pop();
			int ans2=minHeap.top();
			minHeap.pop();
			int sum=ans1+ans2;
			totalCost+=sum;
			minHeap.push(sum);
			//记得最后推回去*
		}
		cout<<totalCost<<endl;
	}
}
*/

/*树的最后讲到了并查集，我们用两道例题来看一下并查集的使用，一道是发现它抓住它，一道是天敌问题*/
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int MAXN= 100000;
int f[200010];
int find(int x){
	return(x==f[x]?x: f[x]=find(f[x]));
}
void merge(int x,int y){
	int fx=find(x);int fy=find(y);
	f[fx]=fy;
}
int main(){
	int t;
	cin>>t;
	while(t--){
		int n,m;
		cin>>n>>m;
		for(int i=0;i<2*n;++i){
			f[i]=i;//进行初始
		}
		for(int i=0;i<m;++i){
			int a,b;
			char c;
			cin>>c>>a>>b;
			if(c=='A'){
				//先不用犹豫不确定的情况，先找到能确定的情况
				if(find(a)==find(b)){
					cout<<"In the same gang."<<endl;
				}
				else if(find(a)==find(b+n) || find(a+n)==find(b)){
					cout<<"In different gangs."<<endl;
				}
				else{
					cout<<"Not sure yet."<<endl;
				}
			}
			else{
				merge(a,b+n);merge(b,a+n);
			}
		}
	}	
}
*/
/* 核心思想就是，建立虚拟的等价类*/

/* 那么食物链这道题也是一样的*/
/*
#include<iostream>
#include<stdio.h>
using namespace std;
int f[3*50000+10];
int find(int x){
	return (x==f[x]? x : f[x]=find(f[x]));
}
void merge(int x,int y){
	int fx=find(x);int fy=find(y);
	f[fx]=fy;
}
int main(){
	int N,M;
	cin>>N>>M;
	int ans=0;
	for(int i=0;i<N*3+1;i++){
		f[i]=i;//记得先初始化
	}
	for(int i=0;i<M;++i){
		int c,x,y;
		cin>>c>>x>>y;
		if(x>N || y>N)
		{ans++;continue;}
		if(c==1){
			//是否违背之前说的话
			if(find(x)==find(y+N) || find(x)==find(y+2*N)){
				ans++;continue;
			}
			merge(x,y);merge(x+N,y+N);merge(x+2*N,y+2*N);
		}
		else {
			if(x==y || find(x)==find(y) || find(x)==find(y+2*N)){
				ans++;continue;
			}
			merge(x,y+N);merge(x+N,y+2*N);merge(x+2*N,y);
		}
	}
cout<<ans<<endl;
}*/


// 中间的一个插曲是，如何判断是不是有电话号码的重复，（本质上是前缀和的问题，其实只需要sort排序然后查询一下相邻是否成立即可
/*注意string的找到是返回0的*/
/*
#include<string>
#include<vector>
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;


int main(){
	int T;
	cin>>T;
	while(T--){
		int n;
		int flag=0;
		cin>>n;
		vector<string> telephone(n);
		for(int i=0;i<n;++i){
			cin>>telephone[i];
		}
		sort(telephone.begin(),telephone.end());
		for(int i=1;i<telephone.size();++i){
			if(telephone[i].find(telephone[i-1])==0){
				cout<<"NO"<<endl;
				flag=1;
				break;
				//如果不提前退出，找到多次就会重复输出
			}
		}
		if(flag)continue;
		cout<<"YES"<<endl;
	}
}
*/
/* 进入图的环节，在图这里，我们要做的是建立好对图的认知，以及掌握最小生成树的Prim Krustal等基本算法*/
// 明确概念：无向图的最大连通子图
// 从例题入手，你要会建立基本的邻接表和邻接矩阵

/* DFS深搜图：先思考思路，激活自己的思考基因+debug意识！
首先访问当前节点，然后访问该顶点未访问过的某一邻接顶点V‘
从V’出发递归的按照深度优先搜索的顺序周游下去
直到到达一个所有的邻接点都被访问过的节点U，则回到已访问节点序列中【最后一个拥有】未访问节点的下一个邻接节点W，再从W出发按照DFS周游
最后当任何已被访问过的节点都没有未被访问你的相邻顶点时，周游结束



*/

// 考场上，最重要的一件事就是静下来，让自己思考

// 舰队那道题+图的两道练习题（学会善用智能指针）
/*
void DFS(Graph&G,int V){
	visit(G,V);
	G.mark[V]=visited;
	for(auto & i:G.edge()){
		if(G.mark[G.toVertices(e)]==unvisited)
			DFS(G,G.toVertices(e));
	}
}*/

// 拓扑排序 + 舰队问题

/*
描述
给出一个图的结构，输出其拓扑排序序列，要求在同等条件下，编号小的顶点在前

输入
若干行整数，第一行有2个数，分别为顶点数v和弧数a，接下来有a行，每一行有2个数，分别是该条弧所关联的两个顶点编号
输出
若干个空格隔开的顶点构成的序列(用小写字母)

*/
// 拓扑排序本质上是对于入度表的遍历
// 先找一个入度为0的，入队（用priority_queue 来寻找序号最小的点
// 每次先初始化存入度为0 的节点进入队列
// 每次删除一个入度为0的节点，而后对其指向的节点，入度-1
/*
#include<iostream>
#include<queue>
#include<vector>
using namespace std;
int main(){
	int n,m;
	cin>>n>>m;
	vector<vector<int>>e(n+1);// 存边，某个顶点指向另一个节点
	vector<int> indice(n+1,0);// 入度表
	priority_queue<int,vector<int>,greater<int>> q;
	for(int i=0;i<m;i++){
		int a; int b;
		cin>>a>>b;
		e[a].push_back(b);
		indice[b]++;

	}
	for(int i=1;i<=n;++i){ // 注意这是在遍历图节点啊！
		if(indice[i]==0){
			q.push(i);
		}
	}
	while(!q.empty()){
		int now=q.top();
		cout<<'v'<<now<<" ";
		q.pop();
		for(auto& i:e[now]){
			indice[i]--;
			if(indice[i]==0){
				q.push(i);
			}
		}
	}
}*/

/*
先看一下最小生成树Krustral,做一下兔子与星空
然后等会回过去做一下舰队 和兔子与樱花
*/
// 

/* MST 最小支撑树：对于带权的无向联通图，保证图的连通性、边权值和最小*/
/*
从任意的一个顶点开始，把这个顶点包含在MST里
在那些断点已经在MST 但是另一个端点不在MST的边种，找权重最小堆一条边，
把这条边以及对应的顶点包含在MST中

Kruskal 基于等价类的思路进行处理
*/
/*
两点学习：存储方式，边权和两个相连的边，遍历方式，看看是不是等价类

*/
#include<queue>
#include<iostream>
#include<stdio.h>
#include<vector>
using namespace std;

#define pip pair<int,pair<int,int>>
// 因为字母的ASCII最多就是128
int f[128];
int find(int x){
	return (x==f[x]?x:f[x]=find(f[x]));
}
void merge(int x,int y){
	int fx=find(x);int fy=find(y);
	f[fx]=fy;
}
int main(){
	int N;
	cin>>N;
	priority_queue<pip,vector<pip>,greater<pip>>q;
	/* 存图的节点用*/
	for(int i=0;i<128;i++){
		f[i]=i;/* 并查集一定记得初始化*/
	}
	for(int i=0;i<N-1;i++){
		char c ; int x;
		cin>>c>>x;
		for(int i=0;i<x;i++){
			char f;int t;
			cin>>f>>t;
			q.push({t,{c,f}});
		}
	}
	int ans=0;
	while(!q.empty()){
		int w=q.top().first;
		int s=q.top().second.first;
		int e=q.top().second.second;
		q.pop();
		if(find(s)!=find(e)){
			ans+=w;
			merge(s,e);
		}
	}
	cout<<ans<<endl;
}