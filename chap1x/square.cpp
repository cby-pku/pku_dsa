/*
1:正方形
查看提交统计提问
总时间限制: 3500ms 内存限制: 65536kB
描述
给定直角坐标系中的若干整点，请寻找可以由这些点组成的正方形，并统计它们的个数。
输入
包括多组数据，每组数据的第一行是整点的个数n(1<=n<=1000)，其后n行每行由两个整数组成，表示一个点的x、y坐标。输入保证一组数据中不会出现相同的点，且坐标的绝对值小于等于20000。输入以一组n=0的数据结尾。
输出
对于每组输入数据，输出一个数，表示这组数据中的点可以组成的正方形的数量。
*/
/*
关键问题在于：如何判断是正方形，以及如何实现交叉比较？
*/
/*你这正方形还是个斜正方形，那对于同一个高度的来说，不就相当于是一样的，但是它避免了会有重复的情况出现，排重试很关键的一点*/
#include<iostream>
#include<set>
using namespace std;
int main(){
    int N;
    while(cin>>N && N!=0){
        set<pair<int,int>> s;
        pair<int,int> tmp;
        for(int i=0;i<N;++i){
            cin>>tmp.first>>tmp.second;
            s.insert(tmp);
        }
        int ans=0;
        for(auto &i:s){
            for(auto &j:s){
                if(i<j){
                    int dx=j.first-i.first;
                    int dy=j.second-i.second;
                    pair<int,int>ii(i.first+dy,i.second-dx);
                    pair<int,int>jj(j.first+dy,j.second-dx);
                    if(s.find(ii)!=s.end() && s.find(jj)!=s.end()){
                        ans++;
                    }
                }
            }
        }
        cout<<ans/2<<endl;/*仅有i,j是交错对角线的时候会重复一次*/
    }
}