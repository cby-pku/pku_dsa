/*
总时间限制: 500ms 内存限制: 65536kB
描述
对于一个长度为N的整数序列A，满足i < j 且 Ai > Aj.的数对(i,j)称为整数序列A的一个逆序
请求出整数序列A的所有逆序对个数

输入
输入包含多组测试数据，每组测试数据有两行
第一行为整数N(1 <= N <= 20000)，当输入0时结束
第二行为N个整数，表示长为N的整数序列
输出
每组数据对应一行，输出逆序对的个数
*/
/*
求逆序对数，其实就是把看需要比较多少次
*/
/*
#include<iostream>
#include<stdio.h>
#include<iostream>

#include<vector>
using namespace std;

int main(){
    int n;
    while(cin>>n)
{

    if(n==0)return 0;
    if(n==1)
    {
        cout<<0<<endl;
        return 0;
    }
    vector<int> s(n);
    for(int i=0;i<n;++i)
    {
        cin>>s[i];
    }
    int ans=0;
    for(int i=1;i<n;i++){
        for(int j=i-1;j>=0;j--){
            if (s[j]>s[i]){
                ans++;
            }
        }
    }
    cout<<ans<<endl;}
}
*/
/* 还是得用归并排序可以最快*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
using namespace std;
int a[20001],ans=0,tmp[20001];

void merge(int l, int r){
	if(l >= r)return ;
	int mid=l + ((r - l)>>1);
	merge(l,mid);
	merge(mid + 1 ,r );/*加号要比位运算优先级更高！*/
	int pl = l, pr = mid + 1, p = l;
	/* 归并排序的内部过程 */
	while(pl <= mid && pr <= r){
		if(a[pl]<=a[pr]){
			tmp[p++] = a[pl++];
		}
		else{
			tmp[p++] = a[pr++];
			ans += mid - pl + 1;
            /* 因为假设中间这些都是已经排好序的，那么从小到大这一串都是不对*/
		}
	}
	while(pl <= mid){
        tmp[p++] = a[pl++];
    }
    while(pr <= r){
        tmp[p++] = a[pr++];
    }
    for(int i=l;i<=r;i++){
        a[i]=tmp[i];
    }
}
int main()
{
  int n;
  while((cin>>n) && (n!=0)){
  	ans=0;
  	for(int i=0;i<n;++i){
  		cin>>a[i];
	  }
  	merge(0,n-1);
  	cout<<ans<<endl;
  }  
}