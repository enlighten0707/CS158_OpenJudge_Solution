#include <iostream>
#include <cstdio>
using namespace std;

struct node{
    int value;
    node* son;
    node* brother;
};

int LCA(node* t,int x,int y,bool &xFind,bool &yFind){
    bool xTmp,yTmp;
    int lca;
    if(t==NULL){
        xFind=yFind=false;
        return x;
    }
    node* p=t->son;
    while(p!=NULL){
        xTmp=yTmp=false;
        lca=LCA(p,x,y,xTmp,yTmp);
        if(xTmp&&yTmp){
            xFind=true;
            yFind=true;
            return lca;
        }
        if(xTmp) xFind=true;
        if(yTmp) yFind=true;
        p=p->brother;
    }
    if(t->value==x) xFind=true;
    if(t->value==y) yFind=true;
    return t->value;
}

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}