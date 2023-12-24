/*
描述
英文字母（除Q和Z外）和电话号码存在着对应关系，如下所示：
A,B,C -> 2
D,E,F -> 3
G,H,I -> 4
J,K,L -> 5
M,N,O -> 6
P,R,S -> 7
T,U,V -> 8
W,X,Y -> 9
标准的电话号码格式是xxx-xxxx，其中x表示0-9中的一个数字。有时为了方便记忆电话号码，我们会将电话号码的数字转变为英文字母，如把263-7422记成America。有时，我们还加上“-”作为分隔符，如把449-6753记成Hi-World。当然，我们未必要将所有的数字都转变为字母，比如474-6635可以记成iPhone-5。
总之，一个方便记忆的电话号码由数字和除Q、Z外的英文字母组成，并且可以在任意位置插入任意多的“-”符号。
现在 ，我们有一个列表，记录着许多方便记忆的电话号码。不同的方便记忆的电话号码可能对应相同的标准号码，你的任务就是找出它们。


输入
第一行是一个正整数n（n <= 100000），表示列表中的电话号码数。
其后n行，每行是一个方便记忆的电话号码，它由数字和除Q、Z外的英文字母、“-”符号组成，其中数字和字母的总数一定为7，字符串总长度不超过200。
输出
输出包括若干行，每行包括一个标准电话号码（xxx-xxxx）以及它重复出现的次数k（k >= 2），中间用空格分隔。输出的标准电话号码需按照升序排序。

如果没有重复出现的标准电话号码，则输出一行“No duplicates.”。
*/
/*
1. 定义一个字典进行存储
2. 读取的时候把-过滤掉
3. 定义一个数组进行计数，不如用string来存储，可以用并查集来实现
4. 或者用map来实现建立联系，而后对于每个数组进行输入检查就可以
*/

#include<iostream>
#include<map>
#include<string>
#include<vector>
using namespace std;
int main(){
	/* 字典查询直接用数组建立起联系！*/
	int replacement[26]={2,2,2,3,3,3,4,4,4,5,5,5,6,6,6,7,7,7,7,8,8,8,9,9,9,9};
	string tmp;
	int n;
	cin>>n;
	map<string,int>a;
	while(n--){
		cin>>tmp;
		/*先消除‘-’号*/
		while(tmp.find('-')!=string::npos){/*这里换成tmp.end()是不是也可以？等会试一下*/
			tmp.erase(tmp.begin()+tmp.find('-'));
		}
		/* 对字符串的操作要熟悉，就像json一开始不熟，但是后来慢慢就熟悉起来了*/
		for(int i=0;i<tmp.length();++i){
			if(tmp[i]>='A'&&tmp[i]<='Z'){
				tmp[i]=replacement[tmp[i]-'A']+'0';
			}
		}
		tmp.insert(tmp.begin()+3,'-');
		a[tmp]++;
	}
	/*map 会默认是升序排列！yess 默认按照键的大小升序排序，而unordered_map 哈希表则不是*/
	bool out_put=false;
	for(auto i:a){
		if(i.second - 1){
			cout<<i.first<<" "<<i.second<<endl;
			out_put=true;
		}
	}
	if(!out_put){
		cout<<"No duplicates."<<endl;
	}
	
}