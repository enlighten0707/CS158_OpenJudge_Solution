#ifndef BST_BST_H
#define BST_BST_H

template <class KEY,class OTHER>
struct SET{
    KEY key;
    OTHER other;
};

template <class KEY,class OTHER>
class BST{
private:

    struct node{
        SET<KEY,OTHER> data;
        node* left;
        node* right;

        node(const SET<KEY,OTHER> &thedata,node* lt=NULL,node* rt=NULL):
        data(thedata),left(lt),right(rt){}
    };
    node* root;
public:
    BST(){root=NULL;}
    ~BST(){makeEmpty(root);}
    SET<KEY,OTHER> *find(const KEY &x)const;
    void insert(const SET<KEY,OTHER> &x);
    void remove(const KEY &x);

private:
    SET<KEY,OTHER> *find(const KEY &x,node* t)const;
    void insert(const SET<KEY,OTHER> &x,node* &t);
    void remove(const KEY &x,node* &t);
    void makeEmpty(node* t);
};
#endif //BST_BST_H

template <class KEY,class OTHER>
SET<KEY,OTHER> *BST<KEY,OTHER>::find(const KEY &x,node* t)const{
    if(t==NULL||t->data.key==x) return (SET<KEY,OTHER>*) t;
    if(t->data.key>x) return find(x,t->left);
    else return find(x,t->right);
}

template <class KEY,class OTHER>
SET<KEY,OTHER> *BST<KEY,OTHER>::find(const KEY &x)const{
    return find(x,root);
}

template <class KEY,class OTHER>
void BST<KEY,OTHER>::insert(const SET<KEY,OTHER> &x,node* &t){
    if(t==NULL) t=new node(x,NULL,NULL);
    else if(t->data.key>x.key) insert(x,t->left);
    else if(t->data.key<x.key) insert(x,t->right);
}

template <class KEY,class OTHER>
void BST<KEY,OTHER>::insert(const SET<KEY,OTHER> &x){
    insert(x,root);
}

template <class KEY,class OTHER>
void BST<KEY,OTHER>::remove(const KEY &x,node* &t){
    if(t==NULL)return ;
    if(t->data.key>x) remove(x,t->left);
    else if(t->data.key<x) remove(x,t->right);
    else if(t->data.key==x){
        if(t->left==NULL||t->right==NULL){
            node* oldNode=t;
            t=(t->left!=NULL)?t->left:t->right;
            delete oldNode;
        }
        else{
            node* tmp=t->right;
            while(tmp->left) tmp=tmp->left;
            t->data=tmp->data;
            remove(t->data.key,t->right);
        }
    }
}

template <class KEY,class OTHER>
void BST<KEY,OTHER>::remove(const KEY &x){
    remove(x,root);
}

template <class KEY,class OTHER>
void BST<KEY,OTHER>::makeEmpty(node* t){
    if(t==NULL)return ;
    if(t->left) makeEmpty(t->left);
    if(t->right) makeEmpty(t->right);
    delete t;
}