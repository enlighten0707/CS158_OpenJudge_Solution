#ifndef AVLTREE_AVLTREE_H
#define AVLTREE_AVLTREE_H

template <class KEY,class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

template <class KEY,class OTHER>
class AVLTree{
private:
    struct node{
        SET<KEY,OTHER> data;
        node* left;
        node* right;
        int height;

        node(const SET<KEY,OTHER> &thedata,node* lt=NULL,node* rt=NULL,int h=1):
                data(thedata),left(lt),right(rt),height(h){}
    };
    node* root;
public:
    AVLTree(){root=NULL};
    ~AVLTree(){makeEmpty(root);}
    SET<KEY,OTHER> *find(const KEY &x)const;
    void insert(const SET<KEY,OTHER> &x);
    void remove(const KEY &x);

private:
    void insert(const SET<KEY,OTHER> &x,node* &t);
    bool remove(const KEY &x,node* &t);
    void makeEmpty(node* t);
    int height(node* t){return t==NULL?0:t->height;}
    void LL(node* &t);
    void LR(node* &t);
    void RL(node* &t);
    void RR(node* &t);
    bool adjust(node* &t,int subTree);
    int max(int a,int b){return a>b?a:b;}
};
#endif //AVLTREE_AVLTREE_H

template <class KEY,class OTHER>
SET<KEY,OTHER> *AVLTree<KEY,OTHER>::find(const KEY &x)const{
    node* t=root;
    while(t!=NULL&&t->data.key!=x){
        if(t->data.key>x) t=t->left;
        else t=t->right;
    }

    if(t==NULL)return NULL;
    else return (SET<KEY,OTHER>*) t;
}

template <class KEY,class OTHER>
void AVLTree<KEY,OTHER>::LL(node* &t){
    node* t1=t;
    t->left=t1->right;
    t1->right=t;
    t1->height=max(height(t1->left),height(t1->right))+1;
    t->height=max(height(t->left),height(t->right))+1;
    t=t1;
}

template <class KEY,class OTHER>
void AVLTree<KEY,OTHER>::RR(node* &t){
    node* t1=t->right;
    t->right=t1->left;
    t1->left=t;
    t1->height=max(height(t1->left),height(t1->right))+1;
    t->height=max(height(t->left),height(t->right))+1;
    t=t1;
}

template <class KEY,class OTHER>
void AVLTree<KEY,OTHER>::LR(node* &t){
    RR(t->left);
    LL(t);
}

template <class KEY,class OTHER>
void AVLTree<KEY,OTHER>::RL(node* &t){
    LL(t->right);
    RR(t);
}

template <class KEY,class OTHER>
void AVLTree<KEY,OTHER>::insert(const SET<KEY,OTHER> &x,node* &t){
    if(t==NULL) t=new node(x,NULL,NULL);
    else if(x.key<t->data.key){
        insert(x,t->left);
        if(height(t->left)-height(t->right)==2){
            if(x.key<t->left->data.key) LL(t);
            else LR(t);
        }
    }
    else if(x.key>t->data.key){
        insert(x,t->right);
        if(height(t->right)-height(t->left)==2){
            if(x.key>t->right->data.key) RR(t);
            else RL(t);
        }
    }
    height(t)=max(height(t->left)+height(t->right))+1;
}