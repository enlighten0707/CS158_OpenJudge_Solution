#include <iostream>
#include <cstdio>
using namespace std;

const int N=100005;

struct Node{
    int value;
    int left;
    int right;
}node[N];

bool root[N]={true};
int queue[N];
int front=0,rear=0;
int dequeue(){
    front=(front+1)%N;
    return queue[front];
}
void enqueue(const int &x){
    rear=(rear+1)%N;
    queue[rear]=x;
}
inline bool isEmpty(){return front==rear;}

void levelOrder(int k){
    enqueue(k);
    int cur;
    while(!isEmpty()){
        cur=dequeue();
        printf("%d ",node[cur].value);
        if(node[cur].left) enqueue(node[cur].left);
        if(node[cur].right) enqueue(node[cur].right);
    }
}


int main() {
    int n;
    scanf("%d",&n);
    for(int i=0;i<N;++i) root[i]=true;
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&node[i].left,&node[i].right,&node[i].value);
        root[node[i].left]=false;
        root[node[i].right]=false;
    }
    int k;
    for(int i=1;i<=n;++i){
        if(root[i]){
            k=i;
            break;
        }
    }
    levelOrder(k);
    return 0;
}