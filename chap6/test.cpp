#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;

const int maxn=10100;
struct node
{
    int child[100]={0};
    bool end;
    node():end(false){}
}trie[maxn];

void clear(int x){
    trie[x].end=false;
    for(int i=0;i<100;++i){
        if(trie[x].child[i]){
            clear(trie[x].child[i]);
            trie[x].child[i]=0;
        }
    }
}

int main(){
    int t,n;
    char ph[15];
    scanf("%d",&t);
    while(t--){
        scanf("%d",&n);
        int cnt=0;
        clear(0);
        bool coherent=true;
        while(n--){
            scanf("%s",ph);
            if(!coherent)continue;
            int l=(int)strlen(ph);
            int tmp=0;
            for(int i=0;i<l;++i){
                int v=ph[i]-'0';
                if(!trie[tmp].child[v]){
                    trie[tmp].child[v]=++cnt;
                }
                else if(i==l-1){
                    coherent=false;
                }
                tmp=trie[tmp].child[v];
                if(trie[tmp].end){coherent=false;}
            }
            trie[tmp].end=true;
        }
        if(coherent){printf("YES\n");}
        else{printf("NO\n");}
    }
    return 0;
}