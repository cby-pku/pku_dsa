/*
描述
Consider equations having the following form:
考虑具有以下形式的方程：
a1x13+ a2x23+ a3x33+ a4x43+ a5x53=0
A1x1 + A2X2 + A3X3 + A4x4 3 3 3 3 + A5x5 3 =0
The coefficients are given integers from the interval [-50,50].
系数是区间 [-50,50] 的整数。
It is consider a solution a system (x1, x2, x3, x4, x5) that verifies the equation, xi∈[-50,50], xi != 0, any i∈{1,2,3,4,5}.
将一个解视为一个系统（x1，x2，x3，x4，x5），它验证方程习∈[-50,50]，习 ！= 0，任意i∈{1,2,3,4,5}。

Determine how many solutions satisfy the given equation.
确定有多少个解满足给定的方程。
输入
The only line of input contains the 5 coefficients a1, a2, a3, a4, a5, separated by blanks.
唯一的输入行包含 5 个系数 a1、a2、a3、a4、a5，用空格分隔。
输出
The output will contain on the first line the number of the solutions for the given equation.
输出将在第一行包含给定方程的解数。
*/

/*
什么二分法求解方程，但是这个应该是有通解叭？
*/
#include <iostream>
#include <unordered_map>
using namespace std;
/*这个索引技术好牛！*/
int info[5], cube[101] = {0};
unordered_map<int, int> cnt;
int main()
{
    for (int i = 0; i < 5; i++)
        cin >> info[i];
    for (int i = -50; i <= 50; i++)
        cube[i + 50] = i * i * i;
    for (int i = -50; i <= 50; i++)
        if (i)
            for (int j = -50; j <= 50; j++)
                if (j)
                    cnt[-info[3] * cube[i + 50] - info[4] * cube[j + 50]]++;
    int ans = 0;
    for (int i = -50; i <= 50; i++)
        if (i)
            for (int j = -50; j <= 50; j++)
                if (j)
                    for (int k = -50; k <= 50; k++)
                        if (k)
                            ans += cnt[info[0] * cube[i + 50] + info[1] * cube[j + 50] + info[2] * cube[k + 50]];
    cout << ans << endl;
}