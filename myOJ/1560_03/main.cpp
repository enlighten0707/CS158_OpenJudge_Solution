#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
};
node* root;

void insert(int x,node* &t){
    if(t==NULL)
        t=new node(x);
    if(x<t->value) insert(x,t->left);
    else if(x>t->value) insert(x,t->right);
}

void remove(int x,node* &t){
    if(t==NULL) return;
    if(x==t->value){
        if(t->right==NULL){
            node* oldNode=t;
            t=t->left;
            delete oldNode;
        }
        else{
            node* tmp=t->right;
            node* tmp2=tmp;
            while(tmp->left){
                tmp2=tmp;
                tmp=tmp->left;
            }
            if(tmp2==tmp){
                t->value=tmp->value;
                t->right=tmp->right;
                delete tmp;
            }
            else{
                t->value=tmp->value;
                tmp2->left=tmp->right;
                delete tmp;
            }
        }
    }
    else if(x<t->value) remove(x,t->left);
    else remove(x,t->right);
}

const int N=100005;
char ch[N];
int cnt;

bool find(int x){
    cnt=0;
    ch[cnt++]='*';
    node* p=root;
    while(p){
        if(x==p->value) return true;
        else if(x<p->value){
            ch[cnt++]='l';
            p=p->left;
        }
        else{
            ch[cnt++]='r';
            p=p->right;
        }
    }
    return false;
}

int main() {
    int m,x;
    char opt;
    scanf("%d",&m);
    while(m--){
        getchar();
        scanf("%c%d",&opt,&x);
        if(opt=='+')
            insert(x,root);
        else if(opt=='-')
            remove(x,root);
        else if(opt=='*'){
            if(find(x)){
                for(int i=0;i<cnt;++i)
                    printf("%c",ch[i]);
                printf("\n");
            }
            else printf("Nothing.\n");
        }
    }
    return 0;
}