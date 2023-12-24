/*
二叉搜索树在动态查表中有特别的用处，一个无序序列可以通过构造一棵二叉搜索树变成一个有序序列，

构造树的过程即为对无序序列进行排序的过程。每次插入的新的结点都是二叉搜索树上新的叶子结点，在进行

插入操作时，不必移动其它结点，只需改动某个结点的指针，由空变为非空即可。

     这里，我们想探究二叉树的建立和层次输出。
*/
//重点练习题！

//多动脑子学一学！

#include<iostream>
#include<queue>
using namespace std;

//二叉树的节点定义
struct TreeNode{
    int value;
    TreeNode*left;
    TreeNode*right;
    //基本的值、左右指针
    TreeNode(int val):value(val),left(nullptr),right(nullptr){}
};

//插入节点到二叉树
//最后返回的是根节点，所以是返回一个TreeNode
TreeNode*insert(TreeNode*root, int val){
    if(root==nullptr)//如果根节点为空，直接用新值创建一个
        return new TreeNode(val);
    //插入的过程其实就是递归搜到最后根节点为空的过程
    if (val<root->value){
        root->left=insert(root->left,val);//返回根节点，也是构造的一部分！
    }
    else if(val>root->value){
        root->right=insert(root->right,val);
    }
    return root;
}
// 构建BST就是不断创建修改指针的过程！
//层次遍历输出二叉树
void levelOrderTraversal(TreeNode *root){
    if(root==nullptr)return;
    //用队列进行遍历
    queue<TreeNode*>q;
    //存储指针的队列
    q.push(root);
    while(!q.empty()){
        //取出第一个
        TreeNode*current=q.front();
        q.pop();
        cout<<current->value<<" ";
        //递归遍历
        if(current->left!=nullptr)q.push(current->left);
        if(current->right!=nullptr)q.push(current->right);
    }
}
int main(){
    int num;
    TreeNode*root=nullptr;
    while(cin>>num){
        root=insert(root,num);
    }
    levelOrderTraversal(root);
    return 0;
}