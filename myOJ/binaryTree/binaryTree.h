#include <iostream>
using namespace std;
#ifndef BINARYTREE_BINARYTREE_H
#define BINARYTREE_BINARYTREE_H
template <class T>
class binaryTree
{
    //friend void printTree(const binaryTree<T> &t, T flag);

private:
    struct Node
    {
        Node *left,*right;
        T data;
        Node():left(NULL),right(NULL){}
        Node(T item,Node *l=NULL,Node *r=NULL):data(item),left(l),right(r){}
        ~Node(){}
    };
    struct stNode
    {
        Node* node;
        int TimesPop;

        stNode(Node* N=NULL):node(N),TimesPop(0){};
    };
    Node* root;
public:
    binaryTree():root(NULL){}
    binaryTree(T x){root=new Node(x);}
    ~binaryTree();
    void clear();
    bool isEmpty()const;
    T Root(T flag)const;
    T lchild(T x,T flag)const;
    T rchild(T x,T flag)const;
    void delLeft(T x);
    void delRight(T x);
    void preOrder()const;
    void midOrder()const;
    void postOrder()const;
    void levelOrder()const;
    void createTree(T flag);


private:
    Node* find(T x,Node* t)const;
    void clear(Node* &t);
    /*
    void preOrder(Node *t)const;
    void midOrder(Node *t)const;
    void postOrder(Node *t)const;
     */
};
#endif //BINARYTREE_BINARYTREE_H

template <class T>
bool binaryTree<T>::isEmpty() const {
    return (root==NULL);
}

template <class T>
T binaryTree<T>::Root(T flag) const {
    if(root==NULL)return flag;
    else return root->data;
}

template <class T>
void binaryTree<T>::clear() {
    clear(root);
}

template <class T>
void binaryTree<T>::clear(binaryTree<T>::Node *&t) {
    if(t==NULL)return;
    if(t->left) clear(t->left);
    if(t->right) clear(t->right);
    delete t;
    t=NULL;
}

template <class T>
binaryTree<T>::~binaryTree() {
    clear();
}

template <class T>
typename binaryTree<T>::Node* binaryTree<T>::find(T x, binaryTree<T>::Node *t) const {
    Node* tmp;
    if(t==NULL)return NULL;
    if(t->data==x)return t;
    tmp=find(x,t->left);
    if(tmp) return tmp;
    else return find(x,t->right);
}

template <class T>
T binaryTree<T>::lchild(T x, T flag) const {
    Node* tmp=find(x,root);
    if(!tmp)return flag;
    if(tmp->left) return tmp->left->data;
    return flag;
}

template <class T>
T binaryTree<T>::rchild(T x, T flag) const{
    Node* tmp=find(x,root);
    if(!tmp)return flag;
    if(tmp->right) return tmp->right->data;
    return flag;
}

template <class T>
void binaryTree<T>::delLeft(T x) {
    Node* tmp=find(x,root);
    if(tmp)
    {
        clear(tmp->left);
        tmp->left=NULL;
    }
}

template <class T>
void binaryTree<T>::delRight(T x) {
    Node* tmp=find(x,root);
    if(tmp)
    {
        clear(tmp->right);
        tmp->right=NULL;
    }
}
/*
template <class T>
void binaryTree<T>::preOrder(binaryTree<T>::Node *t) const {
    if(t==NULL)return ;
    cout<<t->data<<' ';
    preOrder(t->left);
    preOrder(t->right);
}

template <class T>
void binaryTree<T>::preOrder() const {
    preOrder(root);
}

template <class T>
void binaryTree<T>::midOrder(binaryTree<T>::Node *t) const {
    if(t==NULL)return;
    midOrder(t->left);
    cout<<t->data<<' ';
    midOrder(t->right);
}

template <class T>
void binaryTree<T>::midOrder() const {
    midOrder(root);
}

template <class T>
void binaryTree<T>::postOrder(binaryTree<T>::Node *t) const {
    if(t==NULL)return ;
    postOrder(t->left);
    postOrder(t->right);
    cout<<t->data<<' ';
}
template <class T>
void binaryTree<T>::postOrder() const {
    postOrder(root);
}
*/
template <class T>
void binaryTree<T>::levelOrder() const {
    Queue<Node*> queue;
    queue.enQueue(root);
    Node* tmp;
    while(!queue.isEmpty())
    {
        tmp=queue.deQueue();
        cout<<tmp->data<<' ';
        if(tmp->left)queue.enQueue(tmp->left);
        if(tmp->right)queue.enQueue(tmp->right);
    }
}

template <class T>
void binaryTree<T>::createTree(T flag) {
    Queue<Node*> queue;
    T ldata,rdata,rootdata;
    Node* tmp;
    cout<<"input the root:";
    cin>>rootdata;
    root=new Node(rootdata,NULL,NULL);
    queue.enQueue(root);

    while(!queue.isEmpty())
    {
        tmp=queue.deQueue();
        cout<<"input "<<tmp->data<<" 's two children:";
        cin>>ldata;cin>>rdata;
        if(ldata!=flag)
            queue.enQueue(tmp->left=new Node(ldata));
        if(rdata!=flag)
            queue.enQueue(tmp->right=new Node(rdata));
    }
    cout<<"create complete!\n";
}
/*
template <class T>
void printTree(const binaryTree<T> &t, T flag)
{
    Queue<T> queue;
    queue.enQueue(t.root->data);
    T ldata,rdata,tmp;
    while(!queue.isEmpty())
    {
        tmp=queue.deQueue();
        ldata=t.lchild(tmp,flag);
        rdata=t.rchild(tmp,flag);
        cout<<tmp<<' '<<ldata<<' '<<rdata<<endl;
        if(ldata!=flag)
            queue.enQueue(ldata);
        if(rdata!=flag)
            queue.enQueue(rdata);
    }
}
*/
template <class T>
void binaryTree<T>::preOrder() const {
    Stack<Node*> st;
    cout<<"preOrder traverse:\n";
    st.push(root);
    Node* tmp;
    while(!st.isEmpty())
    {
        tmp=st.pop();
        cout<<tmp->data<<' ';
        if(tmp->right) st.push(tmp->right);
        if(tmp->left)  st.push(tmp->left);
    }
    cout<<endl;
}

template <class T>
void binaryTree<T>::midOrder() const {
    Stack<stNode> st;
    stNode tmp(root);
    cout<<"midOrder traverse:\n";
    st.push(tmp);
    while(!st.isEmpty())
    {
        tmp=st.pop();
        ++tmp.TimesPop;
        if(tmp.TimesPop==2)
        {
            cout<<tmp.node->data<<' ';
            if(tmp.node->right)
                st.push(stNode(tmp.node->right));
        }
        else
        {
            st.push(tmp);
            if(tmp.node->left)
                st.push(stNode(tmp.node->left));
        }
    }
    cout<<endl;
}

template <class T>
void binaryTree<T>::postOrder() const {
    Stack<stNode> st;
    stNode tmp(root);
    cout<<"postOrder traverse:\n";
    st.push(tmp);
    while(!st.isEmpty())
    {
        tmp=st.pop();
        ++tmp.TimesPop;
        if(tmp.TimesPop==3){
            cout<<tmp.node->data<<' ';
            continue;
        }
        st.push(tmp);
        if(tmp.TimesPop==1)
        {
            if(tmp.node->left)
                st.push(stNode(tmp.node->left));
        }
        else {
            if (tmp.node->right)
                st.push(stNode(tmp.node->right));
        }
    }
    cout<<endl;
}

