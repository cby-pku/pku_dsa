/*
LISP 是最早的高级编程语言之一。 列表是 LISP 中的基本数据结构，可以轻松地用于表示其他重要的数据结构，例如树。

二叉树可以表示为具有以下形式的 LISP S-表达式。

空树（empty tree）可表示为："()"

一棵树（tree）可表示为："empty tree ｜ (integer tree tree)"，其中integer为一个整数，表示根结点的属性。

例如，上图的树由表达式 (5 (4 (11 (7 () ()) (2 () ()) ) ()) (8 (13 () ()) (4 () (1 () ()) ) ) ) 表示。

请注意，在此形式下，树的所有叶子都具有 (integer () () ) 形式。

给定一棵结点属性为整数的二叉树，请你编写一个程序来确定是否存在一条从根到叶子的路径，路径上的结点的属性之和为指定整数。 例如，在上面显示的树中，正好有四个从根到叶的路径。 路径上结点的属性之和为 27、22、 26 和 18。

注意：由于空树没有根到叶的路径，因此任何关于是否存在总和为空树中指定整数的路径的查询都必须否定。

输入
输入由一系列测试用例组成。
每个测试用例都包含一个整数，后跟一个或多个空格，然后是一个格式为如上所述的 S 表达式的二叉树。
所有的二叉树 S-表达式都是合法的，但表达式可能分布在多行中并且可能包含多余的空格。
一个输入文中会有一个或多个测试用例，输入在文件尾终止。
*/

/*
关键问题：还有就是，考试的时候遇到自己不会的东西不要放弃，大胆去做
以及打好基础，熟悉每一个遍历算法
啊啊啊 还是基础最重要啊！每天都要额外刷题才可以的！
1. 如何实现对树的遍历
2. 如何从这么一个序列里恢复树：也不用恢复树，就顺次读取就可以了
3. 如何查询: 利用递归来查询
4. 如何处理那些空格 while(~scanf(&target))(EOF结尾)
加一个额外处理空格和换行的函数

我觉得关键问题是在于，这些对于字符的操作
但是我很疑惑 它的左括号去哪里
一个自己需要培养的能力: debug的能力，学会用输入输出,而不是对比的能力
这已经成为你的习惯了，不好！debug和想法的实现是紧密相连的
*/
#include<iostream>
using namespace std;

char get_b_c(){
    char c = getchar();
    while(c ==' '||c=='\t'||c=='\n')
    {
        c = getchar();
    }
    return c;
}
int get_i(){
    char c = getchar();
    int op;
    if(c == '-')
        op = -1;
    else{
        op = 1; ungetc(c,stdin);
    }
    int ans = 0;
    c = getchar();
    while(c >= '0' && c <= '9'){
        ans =  10*ans + c - '0';
        c = getchar();
    }
    ungetc(c,stdin);
    return ans * op;
}
int target;
bool has_path = false;
bool empty(int sum){
    get_b_c();//先消除一波前面读取有的空格等杂物
    char c = get_b_c();
    if(c == ')')
        return true;
    else 
        ungetc(c,stdin);
    int cur=get_i();
    bool left_empty = empty(sum+cur);/* 这是为了判断到达叶节点的*/
    bool right_empty = empty(sum+cur);
    if(left_empty && right_empty && sum + cur == target)/*! 竟然是一个分号导致的！*/
        has_path = true;
    get_b_c();
    return false;
}
int main(){
    while(~scanf("%d",&target))
    {
        has_path=false;
        empty(0);
        puts(has_path?"yes":"no");
    }
}