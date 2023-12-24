/*
描述


构造一个具有n个外部节点的扩充二叉树，每个外部节点Ki有一个Wi对应，作为该外部节点的权。使得这个扩充二叉树的叶节点带权外部路径长度总和最小：

                                     Min( W1 * L1 + W2 * L2 + W3 * L3 + … + Wn * Ln)

Wi:每个节点的权值。

Li:根节点到第i个外部叶子节点的距离。

编程计算最小外部路径长度总和。

输入
第一行输入一个整数t，代表测试数据的组数。
对于每组测试数据，第一行输入一个整数n，外部节点的个数。第二行输入n个整数，代表各个外部节点的权值。
2<=N<=100
输出
输出最小外部路径长度总和。
*/

//借助此题练习霍夫曼编码树的基本操作
#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<int>weights(n);//用向量来存储权重
        for(int i=0;i<n;++i){
            cin>>weights[i];
        }
        sort(weights.begin(),weights.end());
        long long totalCost=0;
        //记录总的最小权重和
        while(weights.size()>1){
            int min1=weights[0];
            weights.erase(weights.begin());
            int min2=weights[0];
            weights.erase(weights.begin());
            int sum=min1+min2;
            totalCost+=sum;//实际上合并的时候就是权重值哇！越往下构建的树的时候被计算的越多！
            //这个huffman树的构建方法还是要掌握的
            weights.push_back(sum);
            sort(weights.begin(),weights.end());
    
        }
        cout<<totalCost<<endl;
    }
}
/*
//最小堆版本
#include <iostream>
#include <vector>
#include <queue>
using namespace std;

int main() {
    int t;
    cin >> t;

    while (t--) {
        int n;
        cin >> n;

        vector<int> weights(n);
        for (int i = 0; i < n; ++i) {
            cin >> weights[i];
        }

        // 使用最小堆
        //关键是这行代码非常重要！
        priority_queue<int, vector<int>, greater<int>> minHeap(weights.begin(), weights.end());

        long long totalCost = 0;

        // 构建哈夫曼树
        while (minHeap.size() > 1) {
            int min1 = minHeap.top();
            minHeap.pop();
            int min2 = minHeap.top();
            minHeap.pop();

            int sum = min1 + min2;
            totalCost += sum;

            // 将新的节点（合并后的节点）放回堆
            minHeap.push(sum);
        }

        cout << totalCost << endl;
    }

    return 0;
}

*/