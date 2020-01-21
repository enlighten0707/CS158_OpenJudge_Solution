#include <iostream>
#include "BST.h"
using namespace std;

int main() {
    SET<int,char> a[]={{10,'a'},{8,'b'},{56,'c'},
                        {3,'d'},{22,'e'},{7,'f'}};
    BST<int,char> tree;
    SET<int,char> *p;

    for(int i=0;i<10;++i)
        tree.insert(a[i]);
    p=tree.find(56);
    if(p)cout<<"find 56 is"<<p->key<<" "<<p->other<<endl;
    else cout<<"not found"<<endl;

    tree.remove(56);
    p=tree.find(56);
    if(p)cout<<"find 56 is"<<p->key<<" "<<p->other<<endl;
    else cout<<"not found"<<endl;

    return 0;
}