/*
描述
     老师给小学生门布置了一些作业，让它们按照一个模版写一些字符串交上来，

同学们把作业交上来了，问题来了，这么多的作业老师批改不过来，现在请你帮老师

写一个程序，帮助老师确定各个字符串是否合格。

    首先老师有一个匹配模版，比如是“aa[123]bb”这一个字符串，同学们交的各种

作业字符串如aa1bb、aa2bb、aa3bb都算是正确匹配看，而aacbb就是错误的字符串。

（即待查字符串对应于模版方括号内的部分，应该为方括号内字符串的一个子字符）。

    我们需要做的就是按照模版，找出正确的字符串和所在的行。

输入
输入的第一行为一个整数n，表示有多少个学生的作业，即有多少行需要检查的字符串。（1<=n<=50)
中间为n行字符串，代表着n个学生们写的作业。每个字符串长度小于50。
最后一行为1行字符串，代表着老师给的匹配模板。
输出
输出合格的字符串的行号和该字符串。（中间以空格隔开）
样例输入
4
Aab
a2B
ab
ABB
a[a2b]b
样例输出
1 Aab
2 a2B
4 ABB


*/
#include <iostream>
#include <vector>
#include <string>
#include <regex>

int main() {
    int n;
    std::cin >> n;
    std::cin.ignore(); 

    std::vector<std::string> studentHomework(n);
    for (int i = 0; i < n; ++i) {
        std::getline(std::cin, studentHomework[i]);
    }

    std::string templateString;
    std::getline(std::cin, templateString);

    std::regex templateRegex(templateString);

    for (int i = 0; i < n; ++i) {
        if (std::regex_match(studentHomework[i], templateRegex)) {
            std::cout << i + 1 << " " << studentHomework[i] << std::endl;
        }
    }

    return 0;
}
