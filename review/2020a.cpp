/*
描述
给定n个数，要求把其中重复的去掉，只保留第一次出现的数。

输入
本题有多组数据。
第⼀⾏一个整数T，表示数据组数。 对于每组数据:
第一⾏一个整数n；
第二⾏n个数，表示给定的数。
输出
对于每组数据，输出⼀行，为去重后剩下的数，两个数之间⽤⼀个空格隔开。
注意按数字在输⼊入中出现 的先后顺序输出。
样例输入
2
11
1 2 18 3 3 19 2 3 6 5 4
6
1 2 3 4 5 6
样例输出
1 2 18 3 19 6 5 4
1 2 3 4 5 6
提示
对于50%的数据，n ≤ 5 × 105;
对于100%的数据，n ≤ 106;
由于输入数据较大，建议使用scanf读入
*/
#include<iostream>
#include<stdio.h>
#include<unordered_set>
#include<vector>

int main(){
    int T;std::cin>>T;
    while(T--){
        int n;
        std::cin>>n;
        std::unordered_set<int>seen;
        std::vector<int>result;
        for(int i=1;i<=n;++i){
            int num;
            std::cin>>num;
            if(seen.find(num)==seen.end()){
                seen.insert(num);
                result.push_back(num);
            }
        }
        for(int i:result){
            //在不知道向量大小的时候可以这么输出
            std::cout<<i<<" ";
        }
        std::cout<<std::endl;
    }
}