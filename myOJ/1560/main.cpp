#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
    ~node()=default;
};
node* root;

void insert(const int &x){
    if(root==NULL)
        root=new node(x);
    else{
        node* p=root;
        node* q=p;
        while(p!=NULL){
            q=p;
            if(x<p->value) p=p->left;
            else if(x>p->value)p=p->right;
            else return;
        }
        node* r=new node(x);
        if(x<q->value) q->left=r;
        else q->right=r;
    }
}

void find(const int &x){
    int cnt=0;
    char ch[100005];
    ch[cnt++]='*';
    node* p=root;
    bool f=false;
    while(p!=NULL){
        if(x<p->value) {
            p=p->left;
            ch[cnt++]='l';

        }
        else if(x>p->value) {
            p=p->right;
            ch[cnt++]='r';

        }
        else{
            f=true;
            break;
        }
    }
    if(!f) printf("Nothing\n");
    else{
        for(int i=0;i<cnt;++i)
            printf("%c",ch[i]);
        printf("\n");
    }
}

void Delete(const int &x){
    node* p=root;
    node* q=p;
    while(p!=NULL){
        if(x<p->value) p=p->left;
        else if(x>p->value) p=p->right;
        else break;
    }
    if(p==NULL) return;
    if(p==root){
        if(p->right==NULL){
            root=p->left;
            delete p;
        }
        else{
            node* r=p->right;
            node* s=NULL;
            while(r->left){
                s=r;
                r=r->left;
            }
            if(s==NULL){
                root=p->right;
                delete p;
            }
            else{
                p->value=r->value;
                s->left=r->right;
                delete r;
            }

        }
    }
    else if(p->right==NULL){
        if(q->left==p){
            q->left=p->left;
            delete p;
        }
        else{
            q->right=p->left;
            delete p;
        }
    }
    else{
        node* r=p->right;
        node* s;
        while(r->left){
            s=r;
            r=r->left;
        }
        p->value=r->value;
        s->left=r->right;
        delete r;
    }
}
int main() {
    int q,x;
    char opt;
    scanf("%d",&q);
    while(q--){
        getchar();
        scanf("%c",&opt);
        scanf("%d",&x);

        if(opt=='+') insert(x);
        else if(opt=='*') find(x);
        else if(opt=='-') Delete(x);
    }
    return 0;
}