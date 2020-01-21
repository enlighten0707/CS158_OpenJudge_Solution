#include <iostream>
#include <cstdio>
using namespace std;
/*public TreeNode btConstruct(int[] preOrder, int[] inOrder, int pStart, int pEnd,int iStart,int iEnd)
{//建立根节点
TreeNode tree = new TreeNode(preOrder[pStart]);
tree.left = null;
tree.right = null;
if(pStart == pEnd && iStart == iEnd)
{return tree;}

int root = 0;
//找中序遍历中的根节点
for(root=iStart; root<iEnd; root++)
        {if(preOrder[pStart] == inOrder[root]){break;}}
/划分左右子树
int leftLength = root - iStart;//左子树
        int rightLength = iEnd - root;//右子树
        //遍历左子树
        if(leftLength>0)
        {tree.left = btConstruct(preOrder, inOrder,  pStart+1,  pStart+leftLength, iStart, root-1);}
        //遍历右子树
        if(rightLength>0)
        {tree.right = btConstruct(preOrder, inOrder,  pStart+leftLength+1,  pEnd, root+1, iEnd);}
        return tree;}}*/
struct node{
    int value;
    node* left;
    node* right;
    node(int v,node* l=NULL,node* r=NULL):value(v),left(l),right(r){}
    ~node(){}
};

int preOrder[100005],midOrder[100005];

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
void postOrder(node* t){
    if(t==NULL) return;
    postOrder(t->left);
    postOrder(t->right);
    printf("%d ",t->value);
}
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;++i)
        scanf("%d",&preOrder[i]);
    for(int i=0;i<n;++i)
        scanf("%d",&midOrder[i]);
    node* root=build(0,n-1,0,n-1);
    postOrder(root);
    return 0;
}
