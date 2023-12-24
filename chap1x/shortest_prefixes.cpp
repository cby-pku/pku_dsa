/*
描述
A prefix of a string is a substring starting at the beginning of the given string. The prefixes of "carbon" are: "c", "ca", "car", "carb", "carbo", and "carbon". Note that the empty string is not considered a prefix in this problem, but every non-empty string is considered to be a prefix of itself. In everyday language, we tend to abbreviate words by prefixes. For example, "carbohydrate" is commonly abbreviated by "carb". In this problem, given a set of words, you will find for each word the shortest prefix that uniquely identifies the word it represents.
字符串的前缀是从给定字符串的开头开始的子字符串。“carbon”的前缀是：“c”、“ca”、“car”、“carb”、“carbo”和“carbon”。请注意，在此问题中，空字符串不被视为前缀，但每个非空字符串都被视为其自身的前缀。在日常用语中，我们倾向于用前缀来缩写单词。例如，“碳水化合物”通常缩写为“碳水化合物”。在此问题中，给定一组单词，您将为每个单词找到唯一标识它所代表的单词的最短前缀。

In the sample input below, "carbohydrate" can be abbreviated to "carboh", but it cannot be abbreviated to "carbo" (or anything shorter) because there are other words in the list that begin with "carbo".
在下面的示例输入中，“carbohydrate”可以缩写为“carboh”，但不能缩写为“carbo”（或更短的任何单词），因为列表中还有其他以“carbo”开头的单词。

An exact match will override a prefix match. For example, the prefix "car" matches the given word "car" exactly. Therefore, it is understood without ambiguity that "car" is an abbreviation for "car" , not for "carriage" or any of the other words in the list that begins with "car".
完全匹配将覆盖前缀匹配。例如，前缀“car”与给定的单词“car”完全匹配。因此，可以毫不含糊地理解“car”是“car”的缩写，而不是“carriage”或列表中以“car”开头的任何其他单词。
输入
The input contains at least two, but no more than 1000 lines. Each line contains one word consisting of 1 to 20 lower case letters.
输入至少包含两行，但不超过 1000 行。每行包含一个由 1 到 20 个小写字母组成的单词。
输出
The output contains the same number of lines as the input. Each line of the output contains the word from the corresponding line of the input, followed by one blank space, and the shortest prefix that uniquely (without ambiguity) identifies this word.
输出包含与输入相同的行数。输出的每一行都包含输入相应行中的单词，后跟一个空格，以及唯一（无歧义）标识该单词的最短前缀。
*/
/*
描述
A prefix of a string is a substring starting at the beginning of the given string. The prefixes of "carbon" are: "c", "ca", "car", "carb", "carbo", and "carbon". Note that the empty string is not considered a prefix in this problem, but every non-empty string is considered to be a prefix of itself. In everyday language, we tend to abbreviate words by prefixes. For example, "carbohydrate" is commonly abbreviated by "carb". In this problem, given a set of words, you will find for each word the shortest prefix that uniquely identifies the word it represents.
字符串的前缀是从给定字符串的开头开始的子字符串。“carbon”的前缀是：“c”、“ca”、“car”、“carb”、“carbo”和“carbon”。请注意，在此问题中，空字符串不被视为前缀，但每个非空字符串都被视为其自身的前缀。在日常用语中，我们倾向于用前缀来缩写单词。例如，“碳水化合物”通常缩写为“碳水化合物”。在此问题中，给定一组单词，您将为每个单词找到唯一标识它所代表的单词的最短前缀。

In the sample input below, "carbohydrate" can be abbreviated to "carboh", but it cannot be abbreviated to "carbo" (or anything shorter) because there are other words in the list that begin with "carbo".
在下面的示例输入中，“carbohydrate”可以缩写为“carboh”，但不能缩写为“carbo”（或更短的任何单词），因为列表中还有其他以“carbo”开头的单词。

An exact match will override a prefix match. For example, the prefix "car" matches the given word "car" exactly. Therefore, it is understood without ambiguity that "car" is an abbreviation for "car" , not for "carriage" or any of the other words in the list that begins with "car".
完全匹配将覆盖前缀匹配。例如，前缀“car”与给定的单词“car”完全匹配。因此，可以毫不含糊地理解“car”是“car”的缩写，而不是“carriage”或列表中以“car”开头的任何其他单词。
输入
The input contains at least two, but no more than 1000 lines. Each line contains one word consisting of 1 to 20 lower case letters.
输入至少包含两行，但不超过 1000 行。每行包含一个由 1 到 20 个小写字母组成的单词。
输出
The output contains the same number of lines as the input. Each line of the output contains the word from the corresponding line of the input, followed by one blank space, and the shortest prefix that uniquely (without ambiguity) identifies this word.
输出包含与输入相同的行数。输出的每一行都包含输入相应行中的单词，后跟一个空格，以及唯一（无歧义）标识该单词的最短前缀。
*/
/* Huffingman tree的实际应用，但我不太会huffingman ! 于是可以趁这个机会学一下！！*/

/*
《多叉树》->看来至少是一个27路的多叉树
创建的时候，初始化都为空
*/
#include<iostream>
#include<stdio.h>
#include<stack>
using namespace std;

typedef struct node{
    int count;
    struct  node*next[27];
    node(int _count=0){
        count=_count;
        for(int i=0;i<27;++i){
            next[i]=NULL;
        }
    }
}Trie;
/*对于一个插入操作，如果已经有了，那么就直接并入，如果没有，那么就创建一个新的节点*/

void insertNode(Trie* trie,string s, int len)
{
    Trie* t =trie;
    /*首先转化子串，而后判断子串是否可以插入到树中*/
    for(int i=0;i<len;++i){
        int tmp = s[i]-'a';
        if(t->next[tmp]==NULL){
            t->next[tmp]=new node(0);
        }
        t=t->next[tmp];/* 这个字符匹配上了，于是进一步转到下一次*/
        t->count++;/* 进行计数，方便统计，但是还是不太懂这里面的count是要干什么*/
    }
}

int findrs(Trie* trie , string s, int len){
    Trie* t =trie;
    int i=0;
    for(i=0 ; i<len ;++i){
        int tmp=s[i]-'a';
        if(t->next[tmp]==NULL){
            return -1;/* 到末尾了*/
        }
        if(t->next[tmp]->count==1){
            return i+1;/*如果计数为1，返回长度*/
        }
        t=t->next[tmp];/*转到下一个*/
    }
    return len;
}
/*字符信息存在边上*/