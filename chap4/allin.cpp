/*
你设计了一个新的加密技术，可以用一种聪明的方式在一个字符串的字符间插入随机的字符串从而对信息进行编码。由于专利问题，我们将不会详细讨论如何在原有信息中产生和插入字符串。不过，为了验证你的方法，有必要写一个程序来验证原来的信息是否全在最后的字符串之中。

给定两个字符串s和t，你需要判断s是否是t的“子列”。也就是说，如果你去掉t中的某些字符，剩下字符将连接而成为s。



输入
输入包括多个测试样例。每一个都是由空格分隔的由字母数字ASCII字符组成的两个特定的字符串s和t。s和t的长度不超过100000。
输出
对于每个测试样例，如果s是t的“子列”，则输出”Yes”，否则输出”No”
样例输入
sequence subsequence
person compression
VERDI vivaVittorioEmanueleReDiItalia
caseDoesMatter CaseDoesMatter
样例输出
Yes
No
Yes
No

*/
#include<cstdio>
#include<cstring>
using namespace std;
char s[100002],t[100002];
bool judge(char * s, char * t){
	while(*s != '\0' && *t != '\0'){
		while(*t != *s){
			t++;
			if(*t == '\0') return false;
		}
		s++,t++;
	}
	return *s == '\0';
}
int main(){
	while(scanf("%s%s",s,t) != EOF){
		if(strlen(s) > strlen(t)) puts("No");
		else if(judge(s,t)) puts("Yes");
		else puts("No");
	}
	return 0;
}