#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
    ~node(){}
};
node* root;

void insert(const int &x,node* &t){
    if(t==NULL)
        t=new node(x);
    else if(x<t->value)
        insert(x,t->left);
    else if(x>t->value)insert(x,t->right);
}
int cnt;
char s[100005];

node* find(const int &x,node* &t){
    if(t==NULL||x==t->value) return t;
    if(x<t->value) {
        s[cnt++]='l';
        return find(x,t->left);
    }
    else {
        s[cnt++]='r';
        return find(x,t->right);
    }
}

void remove(const int &x,node* &t){
    if(t==NULL) return;
    if(x<t->value) remove(x,t->left);
    else if(x>t->value) remove(x,t->right);
    else if(t->right==NULL){
        node* oldNode=t;
        t=t->left;
        delete oldNode;
    }
    else{
        node* tmp=t->right;
        node* tmp2=tmp;
        while(tmp->left!=NULL) {
            tmp2=tmp;
            tmp=tmp->left;
        }
        t->value=tmp->value;
        if(tmp2==tmp){
            t->right=tmp->right;
            delete tmp;
        }
        else{
            tmp2->left=tmp->right;
            delete tmp;
        }
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

        if(opt=='+') insert(x,root);
        else if(opt=='*') {
            cnt=0;
            s[cnt++]='*';
            if(find(x,root)==NULL)
                printf("Nothing.\n");
            else{
                for(int i=0;i<cnt;++i)
                    printf("%c",s[i]);
                printf("\n");
            }
        }
        else if(opt=='-'){
            remove(x,root);
        }
    }
    return 0;
}