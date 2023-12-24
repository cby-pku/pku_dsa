/*
描述
给你一些电话号码，请判断它们是否是一致的，即是否有某个电话是另一个电话的前缀。比如：

Emergency 911
Alice 97 625 999
Bob 91 12 54 26

在这个例子中，我们不可能拨通Bob的电话，因为Emergency的电话是它的前缀，当拨打Bob的电话时会先接通Emergency，所以这些电话号码不是一致的。

输入
第一行是一个整数t，1 ≤ t ≤ 40，表示测试数据的数目。
每个测试样例的第一行是一个整数n，1 ≤ n ≤ 10000，其后n行每行是一个不超过10位的电话号码。
输出
对于每个测试数据，如果是一致的输出“YES”，如果不是输出“NO”。


*/
#include<iostream>
#include<vector>
#include<algorithm>//这样才能用sort啊！
#include<string>
using namespace std;
bool isConsistent(vector<string>& phoneNumbers){
    sort(phoneNumbers.begin(),phoneNumbers.end());
    //其实每个只需要查前面的紧邻的就可以，因为是按字典序排，不可能跨行包含前缀（可以自己画图想一下）
    //检查前缀
    for(int i=0;i<phoneNumbers.size()-1;++i){
        if(phoneNumbers[i+1].find(phoneNumbers[i])==0){//找到了前缀
            return false;
        }
    }
    return true;//没有找到前缀
}
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string>phoneNumbers(n);
        for(int i=0;i<n;++i){
            cin>>phoneNumbers[i];
        }
        if(isConsistent(phoneNumbers))cout<<"YES"<<endl;
        else cout<<"NO"<<endl;
    }
}