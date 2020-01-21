#include <iostream>
#include <cstdio>
using namespace std;
const int N=100005;
int Start[N];

struct edgeNode{
    int end;
    int w;
    edgeNode* next;
    edgeNode(int e=0,int ww=0,edgeNode* n=NULL):end(e),w(ww),next(n){}
};

edgeNode* head[N];

int main() {
    int n,m,k,u,v,l;
    scanf("%d%d%d",&n,&m,&k);
    for(int i=1;i<=n;++i){
        head[i]=new edgeNode;
        head[i]->end=1000000002;
    }

    while(m--){
        bool f=true;
        scanf("%d%d%d",&u,&v,&l);
        edgeNode* p=head[u];
        while(p->next!=NULL){
            if(p->end==v){
                if(p->w>l) p->w=l;
                f=false;
                break;
            }
            p=p->next;
        }
        if(p->next==NULL&&f)
            p->next=new edgeNode(v,l);
        if(l<head[u]->end) head[u]->end=l;
    }

//    for(int i=1;i<=n;++i){
////        edgeNode* p=head[i]->next;
////        while(p!=NULL){
////            cout<<p->end<<' '<<p->w<<"  ";
////            p=p->next;
////        }
////        cout<<endl;
////    }
    for(int i=0;i<k;++i)
        scanf("%d",&Start[i]);

    if(k==0){
        printf("-1");
        return 0;
    }
    int ans=1000000001;
    for(int i=0;i<k;++i){
        if(head[i]->end)
    }
}