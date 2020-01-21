#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

const int N=100005;
bool Root[N]={true};

struct Node{
    int lchild;
    int rchild;
}node[N];

int queue[N];
int front=0,rear=0;

void enqueue(int x){
    rear=(rear+1)%N;
    queue[rear]=x;
}
bool isEmpty(){return front==rear;}

int pop(){
    if(isEmpty()) return -1;
    front=(front+1)%N;
    return queue[front];
}



int main() {
    int n,left,right,root;
    bool f=true;
    scanf("%d",&n);
    memset(Root,true, sizeof(Root));
    for(int i=1;i<=n;++i){
        scanf("%d%d",&left,&right);
        if(left) node[i].lchild=left;
        if(right) node[i].rchild=right;
        Root[left]=false;
        Root[right]=false;
    }
    for(int i=1;i<=n;++i){
        if(Root[i]){
            root=i;
            break;
        }
    }
    enqueue(root);
    int p=pop();
    while(p){
        enqueue(node[p].lchild);
        enqueue(node[p].rchild);
        p=pop();
    }
    while(!isEmpty()){
        p=pop();
        if(p){
            cout<<"N";
            f=false;
            break;
        }
    }
    if(f)cout<<"Y";
    return 0;
}