/*
假设这里有36张扑克牌，分别为A1~A9,B1~B9,C1~C9,D1~D9，其中A代表方片，B代表草花，C代表红桃，D代表黑桃，那么，设定如下的排序规则：

1.对于两张卡牌，X1Y1与X2Y2，X1与X2表示A～D，Y1与Y2表示1～9，如果X1与X2不同，那么依照D>C>B>A的方式进行排序

2.假如有X1与X2相同时，那么就比较Y1与Y2的大小。

例如，对于如下的四张牌，有如下的升序排序结果：

D3，C4，A4，C1

升序排序的结果为A4，C1，C4，D3

有人提出了如下的排序策略：

先建立9个队列，用于存放点数的大小，将卡牌依点数存放入各自的队列之中，然后再按队列1到队列9依次出队。

例如，对于上面的结果，依次进队后，结果如下：

队列1：C1；队列3：D3，队列4：C4，A4

将其依次出队后，结果为C1，D3，C4，A4

然后，再建立4个队列，用于存放花色。将卡牌依花色A～D存放入队列1～4中，然后再按队列1到队列4依次出队。

例如，对于上面刚刚出队的序列C1，D3，C4，A4，将其依次进队，结果如下：

队列1：A4；队列3：C1，C4；队列4：D3

将其依次出队后，结果为A4，C1，C4，D3，排序结束。


请根据上面的算法，编写一个用队列对扑克牌排序的程序，要求依照上面的排序规则，根据先花色后点数的方法进行排序。

输入
输入分为两行，第一行为一个整数n，表示一共有n张牌（1<=n<=100）
第二行用XY的形式表示每一张牌，其中X为A～D，Y为1～9
输出
输出三个部分
第一个部分为第一次进队出队的结果，用Queue1:...表示，共9行，结果用空格分隔，下同
第二部分为第二次进队出队的结果，用QueueA:...表示，共4行
第三部分为一行，即将卡牌排序后的结果（升序排序）

*/


#define NDEBUG
#include <cassert>
#include <iostream>
 
using namespace std;
 
#define MAX_NUMBER  9
#define MAX_NODES   100
 
class Node{
public:
	int y;
	char x;
};
 
class Queue{
public:
	Queue(){
		head_ = -1; 
		tail_ = 0; 
		len_ = 0;
		capacity_ = MAX_NODES+2;
		pbuff = new Node [MAX_NODES+2]; 
	}
	~Queue(void){
		delete[] pbuff;
	}
	int IsEmpty(void){
		return len_ == 0; 
	}
	int IsFull(void){
		return len_ == capacity_;   
	}
	void Enqueue(Node e){
		pbuff[ tail_++ ] = e;
		++len_;
		if ( tail_ == capacity_ )
			tail_ = 0;
	}
	Node Dequeue(void){
		--len_;
		if ( head_ == capacity_ )
			head_ = -1;
		return pbuff[ ++head_ ]; 
	}
private:
	int capacity_;
	int len_;
	int head_;
	int tail_;
	Node *pbuff;
};
 
char _index_tab[ 4 ] = {'A','B','C','D'};
 
Queue _queue_array[MAX_NUMBER];
Node  _node_array[MAX_NODES];
 
int main(void){
	int i,j;
	int num;
	Node node;
	cin >> num;
	for ( i=0; i<num; i++ ){
		cin >> node.x >> node.y;
		assert(node.y>=1&&node.y<=9);
		_queue_array[ node.y-1 ].Enqueue(node);
	}
 
	// 保存并输出第一次进队出队结果
	for ( i=j=0; i<MAX_NUMBER; i++ ){
		cout << "Queue" << i+1 << ":";
		while( !(_queue_array[i].IsEmpty()) ){
			_node_array[ j ] = _queue_array[ i ].Dequeue();	
			cout << _node_array[ j ].x << _node_array[ j ].y << " ";
			j++;
		}
		cout << endl;
	}
	assert(j==num);
 
	for ( i=0; i<num; i++ ){
		assert(_node_array[i].x>='A'&&_node_array[i].x<='D');
		_queue_array[ _node_array[i].x-'A' ].Enqueue(_node_array[i]);
	}
 
	// 保存并输出第二次入队出队结果
	for ( i=j=0; i<=3; i++ ){
		cout << "Queue" << _index_tab[ i ] << ":" ;
		while( !(_queue_array[i].IsEmpty()) ){
			node = _queue_array[ i ].Dequeue();
			_node_array[ j++ ] = node;
			cout << node.x << node.y << " " ;
			assert(j<=num);
		}
		cout << endl;
	}
	assert(j==num);
	// 输出排序后结果
	for ( i=0; i<num; i++ ){
		cout << _node_array[ i ].x << _node_array[ i ].y << " ";
	}
	return 0;
}
 