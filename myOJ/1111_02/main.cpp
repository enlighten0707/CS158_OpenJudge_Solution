#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct node{
    char value;
    node* left;
    node* right;
    node(char v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
    ~node(){}
};

char preOrder[1005],midOrder[1005];

node* build(int pStart,int pEnd,int iStart,int iEnd){
    node* tree=new node(preOrder[pStart]);
    if(pStart==pEnd&&iStart==iEnd) return tree;
    int root=0;
    for(root=iStart;root<iEnd;++root){
        if(preOrder[pStart]==midOrder[root])break;
    }
    int leftLen=root-iStart,rightLen=iEnd-root;
    if(leftLen) tree->left=build(pStart+1,pStart+leftLen,iStart,root-1);
    if(rightLen) tree->right=build(pStart+leftLen+1,pEnd,root+1,iEnd);
    return tree;
}

char ans[1005];
int cnt=0;

void Convert(node* cur,int index){
    ans[index]=cur->value;
    if(cur->left) {
        cnt=max(cnt,2*index);
        Convert(cur->left,2*index);
    }
    if(cur->right){
        cnt=max(cnt,2*index+1);
        Convert(cur->right,2*index+1);
    }
}

int main(){
    scanf("%s",preOrder);
    scanf("%s",midOrder);
    int n=strlen(preOrder);
    node* root=build(0,n-1,0,n-1);
    for(int i=0;i<1005;++i) ans[i]='#';
    Convert(root,1);
    for(int i=1;i<=cnt;++i){
        if(ans[i]=='#')
            printf("NULL ");
        else printf("%c ",ans[i]);
    }
    return 0;
}
