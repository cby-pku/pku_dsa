/*
描述
给定一个字符串S，寻找满足条件的子串数目，形式为ABA，A、B均为字符串，A的长度大于等于k，B的长度大于等于1.

输入
第一行为字符串S，第二行为整数k；
输出
一行一个整数，输出找到的满足条件的子串的数目
*/

/*疑似运用KMP算法，但是KMP算法学的不是很好，寄*/
/*!!复习的时候重点看这道题！*/
#include<iostream>
#include<string>
using namespace std;
string a;
int k,len,ans=0,nxt[15001];

/*大体思路就是main函数里面只负责把字符串拆解为子串，而后在f函数中写KMP算法的主部分，外面一层是算特征向量的，里面一层是实际用于匹配的*/
void f(int s){
    int i=s,j=s-1;
    /*i表示当前位置,j是当前前缀的尾部*/
    nxt[s]=s-1;
    while(i<len){
        /*外面的大循环是为了寻找特征向量*/
        if(j==s-1 || a[i]==a[j])
        {
            nxt[++i]=++j;
            int tmp=j;
            /*没有必要说，做完全部的特征向量再开始判断，其实可以直接从此开始判断，因为如果a[i]==a[j],那下一个肯定也是有资格符合提议的，否则下一个连资格都没有*/
            while(tmp!=s-1){
                if(tmp-s>=k&&2*(tmp-s)<i-s){
                    /*前面控制A，后面控制B，也就是说起码i+2了才能判断，这和上面的更新i很契合，恰恰i的更新代表着有前后相同的*/
                    ans++;
                    break;
                }else{
                    tmp=nxt[tmp];
                }
            }
        }
        else{
            j=nxt[j];//直接找下一个特征向量
        }
    }

}
int main(){
    cin>>a>>k;
    len=a.length();/*重复定义也会wrong answer！记得查询好！这是因为强定义取代main里的局部变量定义*/
    for(int i=0;i<len;++i){
        f(i);
    }cout<<ans<<endl;
    return 0;
}