/*
描述
给出一个字符串，现在可以在字符串的两边加上任意的字符，希望将该串变成一个循环串。求最小的需要添加的字符的数量。

一个字符串 A 是循环串，当且仅当存在一个长度大于等于1的字符串S，A可以由大于等于 2 个 S 重复拼接形成。例如，A=abcdabcd时，A可以拆成两个 S=abcd；A=qweqweqwe 时，A可以拆分成三个 S=qwe

输入
输入包括一行，一个字符串 A
保证输入的字符串仅包含小写字符，且串的长度不超过 100,000
输出
输出一个整数，表示需要添加的最少字符数量
*/
/*感觉这个循环串的添加就是再求kmp算法里的特征数组！*/
/* 这个还是要自己想一想*/
#include<iostream>
#include<stdio.h>
using namespace std;
int nxt[100002];
int main()
{
    string a;
	cin>>a;
    int len=a.length();
    nxt[0]=-1;
    int i=0,j= -1;
    /*这个KMP算法写的不对好像*/
    while(i<len){/*因为要判断最后一位*/
    	if(j==-1 || a[i]==a[j]){
    		nxt[++i]=++j;
		}
		else{
			j=nxt[j];
		}
    }
    int loop=len-nxt[len];
    //printf("loop:%d\n",loop);
    //printf("nxt[len]:%d\n",nxt[len]);
    //printf("nxt[len-1]:%d\n",nxt[len-1]);
    /*这应该就是循环子串的特征*/
    if (loop!=len && len%loop==0)/* 这种情况没太想明白*/
    {
        /* code */
        cout<<0<<endl;
    }
    /*相当于补齐到一个循环节的长度就可以了*/
    else{
    cout<<loop-nxt[len]%loop<<endl;/* 是因为nxt[len]可能被loop还长，这种情况下，只需要用取余的那部分做循环节，把剩下的补成loop即可*/
}
}

/* 要写好注释，助教会按照这个注释给分的*/
