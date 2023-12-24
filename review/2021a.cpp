/*
给定字符串S，S中包含4种括号 <>, {}, [], ()，每种括号又可分为左括号和右括号。

对于字符串S，我们定义了替换操作：使用以上四种括号中的一种左括号替换另一种左括号(或者一种右括号替换另一种右括号)。但是，我们不能用左括号替换右括号。

例如：可以使用 "<" 替换 "{" ，但是不能用 "<" 替换 ")" 或 ">"。

接下来我们定义regular bracket sequence(RBS): 首先，空字符串是RBS。

如果 s1，s2 是RBS，则 s2， {s1}s2，[s1]s2，(s1)s2 也是RBS。

例如：字符串 "[[(){}]<>]" 是RBS，但是字符串 "[)()" 和字符串 "][()()" 不是RBS。

请对于给定的字符串S，判断至少需要多少次替换，可以将S变为RBS。

输入
输入1行，为字符串S，仅包含上述4种括号且S不为空串。
S的⻓度不超过106。
输出
如果可以通过替换操作使得S变为RBS，则输出变为RBS所需要的最少替换次数。
如果不能通过替换操作使得S变为RBS，则输出"Impossible"。
*/
/*RBS应该是指可以配对的叭，但是有一些是不能变化成的*/
/*可以用栈来维护左右括号的匹配关系*/
/*而且必须有嵌套关系*/
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;
int main(){
    char RBS[128];/*用于判断左右，左边压栈，右侧用于判定*/
    stack<char> s;
    char pair[128];/*用于右括号和左括号匹配*/
    pair[')']='(',pair['>']='<';
    pair['}']='{',pair[']']='[';
    RBS['(']=RBS['{']=RBS['<']=RBS['[']='l';
    RBS[')']=RBS['}']=RBS['>']=RBS[']']='r';
    int cnt=0,x;//用字符的ASCII码属性
    while((x=getchar())!='\n'){
        if(RBS[x]=='l'){
            s.push(x);
        }
        else{
            if(s.empty()){
                cout<<"Impossible\n";
                return 0;
            }
            cnt+=pair[x]!=s.top();
            s.pop();
        }
    }
    if(!s.empty())
    {
        cout<<"Impossible\n";return 0;
    }
    cout<<cnt<<endl;

}