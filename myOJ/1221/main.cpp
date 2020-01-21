#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    int value;
    node* left;
    node* right;
    node(int v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
};

node* root;

void insert(int x,node* &t){
    if(t==NULL) t=new node(x);
    else if(x<=t->value)  insert(x,t->left);
    else insert(x,t->right);
}

void remove(int x,node* &t){
    if(t==NULL) return;
    if(x<t->value) remove(x,t->left);
    else if(x>t->value) remove(x,t->right);
    else{
        if(t->left!=NULL&&t->right!=NULL){
            node* tmp=t->right;
            while(tmp->left) tmp=tmp->left;
            t->value=tmp->value;
            remove(tmp->value,t->right);
        }
        else{
            node* oldNode=t;
            if(t->left) t=t->left;
            else t=t->right;
            delete oldNode;
        }
    }
}
void clear(node* t){
    if(t==NULL) return;
    if(t->left) clear(t->left);
    if(t->right) clear(t->right);
}

void delete_less_than(int x,node* &t){
    if(t==NULL) return;
    if(t->value<x){
        node* tmp=t;
        t=t->right;
        clear(tmp->left);
        delete tmp;
        delete_less_than(x,t);
    }
    else delete_less_than(x,t->left);
}

void delete_greater_than(int x,node* &t){
    if(t==NULL) return;
    if(t->value>x){
        node* tmp=t;
        t=t->left;
        clear(tmp->right);
        delete tmp;
        delete_greater_than(x,t);
    }
    else delete_greater_than(x,t->right);
}

void delete_interval(int x,int y,node* &t){
    if(t==NULL) return;
    if(t->value<=x) delete_interval(x,y,t->right);
    else if(t->value>=y) delete_interval(x,y,t->left);
    else{
        remove(t->value,t);
        delete_interval(x,y,t);
    }
}

node* find(int x,node* &t){
    if(t==NULL||t->value==x) return t;
    else if(x<t->value) return find(x,t->left);
    else return find(x,t->right);
}

int Size(node* t){
    if(t==NULL) return 0;
    return 1+Size(t->left)+Size(t->right);
}

bool findKth(int i,int &res,node* t){
    if(t==NULL) return false;
    int ls=Size(t->left);
    if(ls==i-1){
        res=t->value;
        return true;
    }
    if(ls>=i) return findKth(i,res,t->left);
    else return findKth(i-ls-1,res,t->right);
}

int main() {
    int n,x,y;
    char opt[20];
    scanf("%d",&n);
    while(n--){
        getchar();
        cin>>opt;
        scanf("%d",&x);
        if(opt[0]=='i')
            insert(x,root);
        else if(opt[0]=='d'){
            int len=strlen(opt);
            if(len==6) remove(x,root);
            else if(len==15) {
                scanf("%d",&y);
                delete_interval(x,y,root);
            }
            else if(len==16) delete_less_than(x,root);
            else delete_greater_than(x,root);
        }
        else if(opt[0]=='f'){
            int len=strlen(opt);
            if(len==4){
                if(find(x,root))
                    printf("Y\n");
                else printf("N\n");
            }
            else{
                int ans;
                if(findKth(x,ans,root))
                    printf("%d\n",ans);
                else printf("N\n");
            }
        }
    }
    return 0;
}