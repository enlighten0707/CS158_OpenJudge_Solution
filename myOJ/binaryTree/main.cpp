#include <iostream>
#include "QUEUE.h"
#include "STACK.h"
#include "binaryTree.h"
using namespace std;

int main()
{
    binaryTree<char> tree;
    tree.createTree('@');
    tree.preOrder();
    tree.midOrder();
    tree.postOrder();
    tree.levelOrder();

    tree.delLeft('L');
    tree.delRight('C');
    tree.delLeft('C');
    tree.levelOrder();
    return 0;
}