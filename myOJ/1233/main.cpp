#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct edgeNode{
    int end;
    edgeNode* next;
    edgeNode(int e=0,edgeNode* n=NULL):end(e),next(n){}
};

edgeNode* head[12];

bool vis[12];
int cnt=0,M,Start;

void dfs(int start,int len){
    if(start==Start&&len>1) return ;
    if(len==M){
        ++cnt;
        return;
    }
    edgeNode* q=head[start]->next;
    vis[start]=true;
    while(q!=NULL){
        if(!vis[q->end]) {
            //cout<<endl;
            //cout<<q->end<<"visit start";
            dfs(q->end,++len);
        }
        q=q->next;
    }
}

int main() {
    int n,m,a,b;

    memset(vis,false, sizeof(vis));
    scanf("%d%d%d%d",&n,&m,&Start,&M);
    for(int i=1;i<=n;++i) head[i]=new edgeNode;
    while(m--){
        scanf("%d%d",&a,&b);
        edgeNode* p=head[a];
        while(p->next!=NULL){
            if(p->end==b) continue;
            p=p->next;
        }
        p->next=new edgeNode(b);
    }

//    for(int i=1;i<=n;++i){
//        edgeNode* p=head[i];
//        while(p!=NULL){
//            cout<<p->end<<' ';
//            p=p->next;
//        }
//
//        cout<<endl;
//    }

    edgeNode* p=head[Start]->next;
    while(p!=NULL){
        if(!vis[p->end])dfs(p->end,2);
        p=p->next;
    }
    printf("%d",cnt);
    return 0;
}