#include <iostream>
#include <cstdio>
#include <cstring>

using namespace std;

struct TreeNode
{
    struct TreeNode* left;
    struct TreeNode* right;
    char  elem;
};


TreeNode* BinaryTreeFromOrderings(char* inorder, char* preorder, int length)
{
    if(length == 0) return NULL;
    TreeNode* node = new TreeNode;
    node->elem = *preorder;
    int rootIndex = 0;
    for(;rootIndex < length; rootIndex++)
    {
        if(inorder[rootIndex] == *preorder)
            break;
    }
    node->left = BinaryTreeFromOrderings(inorder, preorder +1, rootIndex);
    node->right = BinaryTreeFromOrderings(inorder + rootIndex + 1, preorder + rootIndex + 1, length - (rootIndex + 1));
    return node;
}

const int N=1005;
TreeNode* Queue[N];
char ans[N];
int cnt=0;
int front=0,rear=0;
TreeNode* root;
void enQueue(TreeNode* x){
    rear=(rear+1)%N;
    Queue[rear]=x;
}
TreeNode* deQueue(){
    front=(front+1)%N;
    return Queue[front];
}
bool isEmpty(){return front==rear;}

void levelOrder(){
    enQueue(root);
    TreeNode* tmp;
    while(!isEmpty()){
        tmp=deQueue();
        if(tmp==NULL) {
            ans[cnt++]='0';
            continue;
        }
        else {
            ans[cnt++]=tmp->elem;
            enQueue(tmp->left);
            enQueue(tmp->right);
        }
    }
}

int main(){
    char pre[30],mid[30];
    scanf("%s",pre);
    getchar();
    scanf("%s",mid);
    int len=strlen(pre);
    root=BinaryTreeFromOrderings(mid,pre,len);
    levelOrder();
    int j=cnt-1;
    while(ans[j]=='0')--j;
    cnt=j+1;
    for(int i=0;i<cnt;++i){
        if(ans[i]=='0') printf("NULL ");
        else printf("%c ",ans[i]);
    }
    return 0;
}