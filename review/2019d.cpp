/*
2019D 现代艺术
（我是挺现代艺术的）
描述
在对二维艺术作品感到厌烦之后，伟大的艺术牛Picowso决定从事创作一项更为小众的艺术形式，一维画。

尽管目前她的画作可以用一个由颜色组成的长度为N(1~100000)的数组表示，但她的创作风格依然保持不变：从一张空白的矩形画布上，不断地画上一些矩形，在一维的情况下，这些矩形就只是一个区间。她用N种颜色，颜色编号为1~N进行创作，每种颜色只使用一次，之后使用的颜色可以完全的覆盖之前在相同位置上的颜色。

令Picowso感到十分沮丧的是，她的竞争对手Moonet似乎弄明白了如何复制她的这些一维画作，Moonet会画一些不相交的间隔，等待这些颜色晾干，然后再画另外的一些间隔，直到画完。Moonet每次每种颜色最多只能画一个间隔，但是他可以一次画不同颜色不相交的多个间隔，只要这些间隔没有重叠部分。之后Moonet再进行下一轮绘制。请计算Moonet为了复制一幅画需要画几个回合。


输入
第一行是一个整数N，之后N行包含了N个整数，范围0到N表示纸带每个格点的颜色，0表示没有涂色。
输出
输出一行，需要复制这幅画作的最少回合数，如果这幅画不可能是Picowso的画作输出-1（比如说这幅画不可能是通过一次在一条上画一层的方法进行创作的）
*/
/*关键点是A同学每种颜色只使用一次，这一次它可以画一个区间，且它可以进行颜色的覆盖；而B同学不会画相交的间隔，但是它每一轮可以用很多颜色，只要这些间隔不重叠，关键在于能否重叠*/
#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;
#define N 100010
//首先定义一个结尾的数组，记录end_pos
int end_pos[N];int canvas[N];
int Visit[N]={0};
int n;
stack<int>review;
int main(){
    cin >> n;
    for(int i=1;i<=n;++i){
        cin>>canvas[i];
        end_pos[canvas[i]]=i;
    }
    int result=0;
    Visit[0]=1;
    review.push(0);
    end_pos[0]=n+1;
    int flag=1;
    for(int i=1;i<=n&&flag;++i){
        if(review.top()!=canvas[i]){
            if(Visit[canvas[i]])
                flag=0;//这是对应着非法画作，被访问过，又拿出来了
            review.push(canvas[i]);
        }
        Visit[canvas[i]]=1;
        result=max(result,(int)review.size());
        if(i==end_pos[canvas[i]])
            review.pop();
    }
    int ans=flag?result-1:-1;
    cout<<ans<<endl;
/*比如以1 2 1 2 1为例， 1 入栈 标记访问 未end ; 2 入栈 标记访问 未end ; 1 访问过 flag=0 非结尾 循环终止*/
/*以0 1 4 5 1 3 3为例, 0入栈，无差; 1 入栈 标记访问 未end ; 4 入栈 标记访问 result=3 end 栈顶为1 ; 5 入栈 标记访问 result=3 end 栈顶为1 ; 1 出栈 栈顶为0; 3的操作不可能超过1; 木桶原理是对于一次涂抹的1和3而言 要不1覆盖层数多 要么3多，取最大即可*/
}