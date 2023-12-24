/*


在此问题中，您必须分析特定的排序算法。该算法通过交换两个相邻的序列元素来处理 n 个不同整数的序列，直到序列按升序排序。对于输入序列
9 1 0 5 4 ,

Ultra-QuickSort produces the output
Ultra-QuickSort 生成输出
0 1 4 5 9 .

Your task is to determine how many swap operations Ultra-QuickSort needs to perform in order to sort a given input sequence.
您的任务是确定Ultra-QuickSort需要执行多少次交换操作才能对给定的输入序列进行排序。
输入
The input contains several test cases. Every test case begins with a line that contains a single integer n < 500,000 -- the length of the input sequence. Each of the the following n lines contains a single integer 0 ≤ a[i] ≤ 999,999,999, the i-th input sequence element. Input is terminated by a sequence of length n = 0. This sequence must not be processed.
输入包含多个测试用例。每个测试用例都以一行开头，该行包含一个整数 n < 500,000 -- 输入序列的长度。以下 n 行中的每一行都包含一个整数 0 ≤ a[i] ≤ 999,999,999，第 i 个输入序列元素。输入由长度为 n = 0 的序列终止。不得处理此序列。
输出
For every input sequence, your program prints a single line containing an integer number op, the minimum number of swap operations necessary to sort the given input sequence.
对于每个输入序列，程序都会打印一行，其中包含整数运算，即对给定输入序列进行排序所需的最小交换操作数。
样例输入
5
9
1
0
5
4
3
1
2
3
0
样例输出
6
0
*/
/*这不是和归并排序是一样的道理？*/
/*这道题的数据量更大，注意要把int -> long long*/
#include<iostream>
#include<stdio.h>
#include<algorithm>
#define int long long
using namespace std;
int ans=0,a[500002],tmp[500002];
void merge(int l,int r){
    if(l>=r)return;
    int mid=l+((r-l)>>1);
    merge(l,mid);
    merge(mid+1,r);

    /*下面进行归并过程*/
    int pl=l,pr=mid+1,p=l;
    while(pl<=mid && pr<=r){
        if(a[pl]<=a[pr]){
            tmp[p++]=a[pl++];
        }
        else{
            tmp[p++]=a[pr++];
            ans+=mid-pl+1;
        }
    }
    while(pl<=mid){
        tmp[p++]=a[pl++];
    }
    while(pr<=r){
        tmp[p++]=a[pr++];
    }
    for(int i=l;i<=r;i++){
        a[i]=tmp[i];
    }
}
/*而且如果把int 重定义为long long main（）函数的返回值也要变*/
signed main(){
    int n;
    while(cin>>n && n!=0){
        ans=0;
        for(int i=0;i<n;i++){
            cin>>a[i];
        }
        merge(0,n-1);
        cout<<ans<<endl;
    }
    return 0;
}