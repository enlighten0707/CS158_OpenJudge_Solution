#include <iostream>
class Integer {
private:
    int data;
public:
    Integer(const int &value) : data(value) {}
    Integer(const Integer &other) : data(other.data) {}
    bool operator==(const Integer &t)
    {
        return data == t.data;
    }
};

struct node
{
    Integer* Data;
    node *pre,*next;
    node(Integer * d=NULL,node* p=NULL,node* n=NULL):Data(d),pre(p),next(n){}
    ~node(){if(Data)delete Data;}
};
struct mapIndex{
    int curSize;
    node* DataHead;
    node* DataTail;
    mapIndex *pre,*next;
    mapIndex(int cS,node* DH,node* DT,mapIndex* p,mapIndex* n)
    {curSize=cS;DataHead=DH;DataTail=DT;pre=p;next=n;}
    mapIndex():curSize(0),DataHead(NULL),DataTail(NULL),pre(NULL),next(NULL){}
};
int main() {
    mapIndex test;
    std::cout<< sizeof(test);
    return 0;
}