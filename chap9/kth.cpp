/*
描述
You are working for Macrohard company in data structures department. After failing your previous task about key insertion you were asked to write a new data structure that would be able to return quickly k-th order statistics in the array segment.
您在 Macrohard 公司的数据结构部门工作。在上一个关于键插入的任务失败后，你被要求编写一个新的数据结构，该结构将能够快速返回数组段中的第 k 个顺序统计信息。
That is, given an array a[1...n] of different integer numbers, your program must answer a series of questions Q(i, j, k) in the form: "What would be the k-th number in a[i...j] segment, if this segment was sorted?"
也就是说，给定一个不同整数的数组 a[1...n]，您的程序必须以以下形式回答一系列问题 Q（i， j， k）： “a[i...j] 段，如果这个段被排序了？
For example, consider the array a = (1, 5, 2, 6, 3, 7, 4). Let the question be Q(2, 5, 3). The segment a[2...5] is (5, 2, 6, 3). If we sort this segment, we get (2, 3, 5, 6), the third number is 5, and therefore the answer to the question is 5.
例如，考虑数组 a = （1， 5， 2， 6， 3， 7， 4）。假设问题是 Q（2， 5， 3）。段 a[2...5] 为 （5， 2， 6， 3）。如果我们对这段进行排序，我们得到 （2， 3， 5， 6），第三个数字是 5，因此问题的答案是 5。
输入
The first line of the input file contains n --- the size of the array, and m --- the number of questions to answer (1 <= n <= 100 000, 1 <= m <= 5 000).
输入文件的第一行包含数组大小的 n ---，m ---要回答的问题数 （1 <= n <= 100 000， 1 <= m <= 5 000）。
The second line contains n different integer numbers not exceeding 109 by their absolute values --- the array for which the answers should be given.
第二行包含 n 个不同的整数，其绝对值不超过 10 9 ，---应给出答案的数组。
The following m lines contain question descriptions, each description consists of three numbers: i, j, and k (1 <= i <= j <= n, 1 <= k <= j - i + 1) and represents the question Q(i, j, k).
以下 m 行包含问题描述，每个描述由三个数字组成：i、j 和 k （1 <= i <= j <= n， 1 <= k <= j - i + 1） 并表示问题 Q（i， j， k）。
输出
For each question output the answer to it --- the k-th number in sorted a[i...j] segment.
对于每个问题输出，答案---排序的第 k 个数字 a[i...j] 段。
样例输入
7 3
1 5 2 6 3 7 4
2 5 3
4 4 1
1 7 3
样例输出
5
6
3
*/
/*
一个想法是，可以对每个数组的每个段抽出来现排序，但是要考虑到数组的损失问题，肯定是
传入数组的拷贝进行
从小区间里开始查，使得小区间里成立的是k个数，那么这个bound就是要输出的哪个值
之所以排序num，是为了方便二分查找实则建立起了第k个数新的定义关系
*/
// 因为数据太大，所以用二分+桶排序进行合并
#include<iostream>
#include<algorithm>
#include<stdio.h>
#include<vector>
using namespace std;

const int MAXN=1e5+5;
const int MAXM=5005;
int A[MAXN];
const int B=1000;
vector<int>bucker[MAXN/B];
int num[MAXN];

/* 这似乎不是在整体桶排序，而是对每个桶进行搜索，直到搜到k=c,如何体现在这个区间里？
用tl tr做两侧的bound限制搜索范围 */
/*每一道作业题都有可能会考，做好巩固！*/
int main(){
	int N,M;
	scanf("%d %d",&N,&M);
	for(int i=0;i<N;i++){
		scanf("%d",&A[i]);
		num[i]=A[i];
		bucker[i/B].push_back(A[i]);
	}
	for(int i=0;i<N/B;i++){
		sort(bucker[i].begin(),bucker[i].end());
	}
	sort(num,num+N);
	int l,r,c;
	for(int i=0;i<M;++i){
		scanf("%d %d %d",&l,&r,&c);
		l=l-1;
		r=r;
		int lb=-1;int ub=N-1;
		while(lb<ub-1){
			int mid=lb+(ub-lb)/2;
			int num_c=num[mid];
			int k=0;
			int tl=l;
			int tr=r;
			while(tl<tr&&tl%B!=0)
			{
				if(A[tl++]<=num_c)k++;
			}
			while(tl<tr && tr%B!=0){
				if(A[--tr]<=num_c)k++;
			}
			while(tl<tr){
				/* 跨桶了*/
				int j=tl/B;
				k+=upper_bound(bucker[j].begin(),bucker[j].end(),num_c)-bucker[j].begin();
				tl+=B;
			}
			if(k>=c)ub=mid;
			else lb=mid;
		}
		printf("%d\n",num[ub]);
	}
}
