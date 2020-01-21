#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int n;
bool root[N];

int queue[N];
int front=0,rear=0;
void enqueue(int x){
    rear=(rear+1)%N;
    queue[rear]=x;
}
int dequeue(){
    front=(front+1)%N;
    return queue[front];
}
bool isEmpty(){return front==rear;}

struct Node{
    int value;
    int child;
    int brother;
}node[N];

void createTree(){
    for(int i=1;i<=n;++i){
        scanf("%d%d%d",&node[i].child,&node[i].brother,&node[i].value);
        root[node[i].child]=false;
        root[node[i].brother]=false;
    }

}

void preOrder(int k){
    cout<<node[k].value<<' ';
    if(node[k].child)
        preOrder(node[k].child);
    if(node[k].brother)
        preOrder(node[k].brother);
}

void postOrder(int k){
    if(node[k].child)
        postOrder(node[k].child);
    cout<<node[k].value<<' ';
    if(node[k].brother)
        postOrder(node[k].brother);
}

void levelOrder(int k){
    cout<<node[k].value<<' ';
    if(node[k].child) enqueue(node[k].child);
    int cur;
    while(!isEmpty()){
        cur=dequeue();
        cout<<node[cur].value<<' ';
        while(node[cur].brother){
            cout<<node[node[cur].brother].value<<' ';
            if(node[cur].child)
                enqueue(node[cur].child);
            cur=node[cur].brother;
        }
        if(node[cur].child) enqueue(node[cur].child);
    }
}
int findRoot(){
    for(int i=1;i<=n;++i){
        if(root[i])
            return i;
    }
}

int main() {
    scanf("%d",&n);
    for(int i=1;i<=n;++i) root[i]=true;
    createTree();
    int k=findRoot();
    preOrder(k);
    printf("\n");
    postOrder(k);
    printf("\n");
    levelOrder(k);
    return 0;
}