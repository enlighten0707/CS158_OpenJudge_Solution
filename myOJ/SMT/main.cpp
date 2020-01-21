#include <iostream>

int main() {
    std::cout << "Hello, World!" << std::endl;
    return 0;
}

class SMT{
    struct node{
        int val;
        int tag[10];//多tag 不考
        int l,r;
    };
};
//非递归实现？
//【不考】可持久化线段树/主席树

