/*
描述
有N座通信基站，P条双向电缆，第i条电缆连接基站Ai和Bi。特别地，1号基站是通信公司的总站，N号基站位于一座农场中。现在，农场主希望对通信线路进行升级，其中升级第i条电缆需要花费Li。

电话公司正在举行优惠活动。农场主可以指定一条从1号基站到N号基站的路径，然后，农场主可以指定路径上不超过K条电缆，先由电话公司免费提供升级服务。农场主只需要支付在该路径上剩余的电缆中，升级价格最贵的那条电缆的花费即可。支付完成后，其余电缆也将由电话公司免费升级。求至少用多少钱能完成升级。

输入
第一行三个整数， N，P，K。
接下来P行，每行三个整数Ai，Bi，Li。
输出
若不存在从1到N的路径，输出-1。否则输出所需最小费用。
*/
/*不仅是要找联通图，而且要找N-1-K中最小的那个*/
#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
using namespace std;

//二分SPFA或Dijkstra
#define SPFA
// #define Dijkstra

#define pii pair<int, int>
int n, m, k;
bool no_path = false; //注意判断无路径-1
vector<pii> edge[1001];
// 找1->n的最短路径，大于x算长度为1，最短路径<=k时该价钱可以建起来线路
bool possible_price(int x)/*函数用于判断是否存在从1到N的路径，使得路径上至多包含K条电缆，并且升级费用不超过x*/
{

#ifdef SPFA
/*
SPFA算法迭代：

循环队列q，每次取出队头的基站作为当前松弛的起点。
对于当前基站的所有邻接基站，尝试松弛路径长度。如果通过当前基站到达邻接基站的路径上电缆费用超过x，那么在路径长度上加1，否则路径长度不变。指的是这部分让电信公司来付钱
如果通过当前基站松弛得到的路径长度比之前记录的路径长度更小，更新路径长度，并将邻接基站加入队列。
如果队列为空，说明没有可以继续松弛的基站，退出循环。
判断是否存在路径：

如果1号基站到N号基站的路径长度仍然是无穷大，说明不存在从1到N的路径，将no_path标记为true。
返回1号基站到N号基站的路径长度是否不超过K
*/
/*所以你要理解后开写，因为你真的抄都能抄错*/
    // SPFA
    queue<int> q;
    q.push(1);
    bool in_queue[1001] = {false};
    in_queue[1] = true;
    int dis[1001];
    memset(dis, 0x3f, sizeof(dis));
    dis[1] = 0;
    while (!q.empty())
    {
        int cur = q.front(); //下一个用来作为松弛起点的点
        q.pop();             //与Dijkstra和Prim等贪心算法不同，SPFA是一直松弛，不用判定是否非法（指已有最短路径）
        in_queue[cur] = false;
        for (auto e : edge[cur])
            if (dis[e.second] > dis[cur] + (e.first > x)) //可以被松弛
            {
                dis[e.second] = dis[cur] + (e.first > x);
                if (!in_queue[e.second]) //如果队列中没有松弛终点，那么把松弛终点放入队列
                    q.push(e.second), in_queue[e.second] = true;
            }
    }
    if (dis[n] == 0x3f3f3f3f)
        no_path = true;
    return dis[n] <= k;

#endif
}
int main()
{
    cin >> n >> m >> k;
    int l = -1, r = -1, mid = 0;
    for (int i = 0; i < m; i++)
    {
        int a, b, w;
        cin >> a >> b >> w;
        edge[a].push_back({w, b});/*无向图的存放*/
        edge[b].push_back({w, a});
        r = max(r, w + 1);
    }
    while (l + 1 != r)
    {
        mid = l + (r - l) / 2;
        if (possible_price(mid))
            r = mid;
        else
            l = mid;
    }
    cout << (no_path ? -1 : r) << endl;
}