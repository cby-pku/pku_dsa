/*
给定一个长度为n（n<=10^6）的数组。有一个大小为k的滑动窗口从数组的最左端移动到最右端。你可以看到窗口中的k个数字。窗口每次向右滑动一个数字的距离。
下面是一个例子：
数组是 [1 3 -1 -3 5 3 6 7]， k = 3。
你的任务是得到滑动窗口在每个位置时的最大值和最小值。


输入
输入包括两行。
第一行包括n和k，分别表示数组的长度和窗口的大小。
第二行包括n个数字。
输出
输出包括两行。
第一行包括窗口从左至右移动的每个位置的最小值。
第二行包括窗口从左至右移动的每个位置的最大值


样例输入
8 3
1 3 -1 -3 5 3 6 7
样例输出
-1 -3 -3 -3 3 3
3 3 5 5 6 7
*/


#include<cmath>
#include<queue>  
#include<cstdio> 
#include<cstring> 
#include<iostream> 
#include<algorithm>
using namespace std;
int a[1000001],n,wide,q[1000001],head,tail;
int main(){
	scanf("%d%d",&n,&wide);
	for(int i=1;i<=n;i++)
	 scanf("%d",&a[i]);
	head=1;tail=0;
	for(int i=1;i<=n;i++)
	{
	 while(tail>0&&head<=tail&&i-q[head]>=wide)//对于超出窗口范围的元素，出队 
	  head++;
	 while(tail>0&&head<=tail&&a[q[tail]]>a[i])//对于比新元素更大的元素，出队 
	  tail--;//通过这个操作能始终保持范围内最小的元素位于队首，且队列里的元素是单调递增的 
	 q[++tail]=i;//入队 
	 if(i>=wide) printf("%d ",a[q[head]]);//在元素已经足够多个时输出 
	}
	head=1;tail=0;
	memset(q,0,sizeof(q));
	printf("\n");
	for(int i=1;i<=n;i++)//同上寻找最小值的方法寻找最大值 
	{
	 while(tail>0&&head<=tail&&i-q[head]>=wide)
	  head++;
	 while(tail>0&&head<=tail&&a[q[tail]]<a[i])
	  tail--;
	 q[++tail]=i;
	 if(i>=wide) printf("%d ",a[q[head]]);
	}
	return 0;
}