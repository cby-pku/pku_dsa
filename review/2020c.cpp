/*
2020C:序列的中位数
查看提交统计提问
总时间限制: 1000ms 内存限制: 131072kB
描述
给出一个长度为N的非负整数序列A，对于所有1≤k≤(N+1)/2，输出A1, A1∼A3, …, A1∼A2k−1的中位数。即前1,3,5,...个数的中位数。中位数是指将一组数据从小到大排列后，位于中间的那个数。

输入
第1行为一个正整数N，表示了序列长度。第2行包含N个非负整数Ai(Ai ≤ 109)。
输出
共(N+1)/2行，分别为前1,3,5,...个数的中位数。
样例输入
7
1 3 5 7 9 11 6
样例输出
1
3
5
6
提示
对于20%的数据，N ≤ 100；
对于40%的数据，N ≤ 3000；
对于100%的数据，N ≤ 100000;
*/
#include<iostream>
#include<queue>
#include<algorithm>
#include<math.h>
using namespace std;
/*采用 优先队列维护栈的方式，感觉这个还是很厉害的*/
long long n,info[100001];
int main(){
    cin>>n;
    for(int i=1;i<=n;++i){
        cin>>info[i];
    }
    priority_queue<long long>l;
    priority_queue<long long,vector<long long>,greater<long long>>r
    long long mid=info[1];
    cout<<mid<<endl;
    for(long long i=2;i<=(n+1)/2;++i){
        long long a=info[2*i-2],b=info[2*i-1];
        if((mid-a)*(mid-b)<=0){
            /*在二者中间*/
            l.push(min(a,b));r.push(max(a,b));
        }
        else if(mid<a){/*两个都小*//*因为上面第一个if筛过了*/
            l.push(mid);r.push(a);r.push(b);mid=r.top();r.pop();
        }
        else{
            /*两个都大*/
            l.push(a);l.push(b);r.push(mid);mid=l.top();l.pop();
        }
        cout<<mid<<endl;
    }
}