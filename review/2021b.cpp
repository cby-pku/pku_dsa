/*
现在有一些英语单词需要做拼写检查，你的工具是一本词典。需要检查的单词，有的是词典中的单词，有的与词典中的单词相似，你的任务是发现这两种情况。单词A与单词B相似的情况有三种：
1、删除单词A的一个字母后得到单词B；
2、用任意一个字母替换单词A的一个字母后得到单词B；
3、在单词A的任意位置增加一个字母后得到单词B。
你的任务是发现词典中与给定单词相同或相似的单词。


输入
第一部分是词典中的单词，从第一行开始每行一个单词，以"#"结束。词典中的单词保证不重复，最多有10000个。
第二部分是需要查询的单词，每行一个，以"#"结束。最多有50个需要查询的单词。
词典中的单词和需要查询的单词均由小写字母组成，最多包含15个字符。
输出
按照输入的顺序，为每个需要检查的单词输出一行。如果需要检查的单词出现在词典中，输出“?x is correct"，?x代表需要检查的单词。如果需要检查的单词没有出现在词典中，则输出"?x: ?x1 ?x2 ...?xn"，其中?x代表需要检查的单词，?x1...?xn代表词典中与需要检查的单词相似的单词，这些单词中间以空格隔开。如果没有相似的单词，输出"?x:"即可。

*/

/*
核心问题1：如何存储字典 ： 用哈希表
核心问题2：检查的时候的时间复杂度最低的搜索算法 ：用哈希表
核心问题3：如何定义相似算法：分别用三个函数定义，关键是replace的算法如何定义
find_insert 先插入，再替换即可
find_delete 用string的erase函数实现s.erase(a,b),第a个字符开始的b个字符
find_replace 双重循环，内部依次替换tmp的第i个位即可
核心问题4：correct可以覆盖相似
*/

#include<stdio.h>
#include<iostream>
#include<unordered_map>
#include<algorithm>
#include<unordered_set>
#include<string>
#include<vector>
using namespace std;

unordered_map<string , int>lib;
unordered_set<string> similar;//用无序集合来存储，防止输出相同的答案
vector<string>ans; //最后的输出答案，是要根据字典里的出现顺序来排序的
bool cmp(const string a ,const string b)
{
    return lib[a]<lib[b];
}
void find_delete(string s){
    //string tmp=s;
    int len=s.length();
    for(int i=0;i<len;i++)
    {
        string tmp=s;//erase是不可恢复的
        tmp.erase(i,1);
        if(lib[tmp]){
            similar.insert(tmp);
        }
    }
}
void find_insert(string s){
    int len=s.length();
    for(int i=0;i<=len;i++){/* 还可以在最后一位添加，考虑要周全！*/
        string tmp=s;
        tmp.insert(tmp.begin()+i,'a');
        for(char j='a';j<='z';j++){
            tmp[i]=j;
            if(lib[tmp]){
                similar.insert(tmp);
            }
        }
    }
}
void find_replace(string s){
    int len=s.length();
    string tmp=s;
    for(int i=0;i<len;i++){
        for(char j='a';j<='z';j++){
        tmp[i]=j;
        if(lib[tmp]){
            similar.insert(tmp);
        }
        }
        tmp[i]=s[i];
    }
}
void search(string s)
{
    if(lib[s])
    {
        cout<<s<<" is correct"<<endl;
        return;/*！！以及记得return*/
    }
    similar.clear();ans.clear();/*! 高级容器的清除函数是clear不是empty!*/
    find_insert(s);
    find_replace(s);
    find_delete(s);
    /*但是集合是无法排序的，所以要用vector做过渡对vector排序*/
    for(auto &i:similar)
    {
        ans.push_back(i);
    }
    sort(ans.begin(),ans.end(),cmp);
    cout<<s<<":";
    for(auto &i:ans){
        cout<<" "<<i;
    }
    cout<<endl;


}

int main(){
    int cnt=0;/* 帮助建立键值对映射*/
    string s;
    while((cin>>s)&&(s!="#"))
    {
        lib[s]=++cnt;
    }
    while(cin>>s && s!="#")
    {
        search(s);
    }


}