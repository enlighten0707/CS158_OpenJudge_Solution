#include <iostream>
using namespace std;

const int MAXSIZE=1003;
int go[MAXSIZE],stack[MAXSIZE];
int n,m;
int pos=0;

class Queue
{
//private:
public:
    int *elem;
    int front;
    int rear;
    int currentLen;
public:
    Queue();
    ~Queue();
    bool isEmpty()const;
    void enQueue(const int &x);
    int deQueue();
    int Len()const;
};
Queue::Queue() {
    front=rear=0;
    elem=new int[1000];
    currentLen=0;
}
Queue::~Queue() {delete []elem;}
bool Queue::isEmpty() const {return front==rear;}
void Queue::enQueue(const int &x) {
    rear=(rear+1)%1000;
    elem[rear]=x;
    ++currentLen;
}
int Queue::deQueue() {
    front=(front+1)%1000;
    --currentLen;
    return elem[front];
}
int Queue::Len()const {return currentLen;}

bool isPossible()
{
    Queue queue;
    pos=0;
    int i=0;
    while(i<n)
    {
        if(go[i]==pos)
        {
            ++pos;++i;
        }
        else if(go[i]<pos)
        {
            if(queue.isEmpty())return false;
            if(go[i]!=queue.deQueue())return false;
            ++i;
        }
        else
        {
            if(queue.Len()==m) return false;
            queue.enQueue(pos);
            ++pos;
        }
    }
    return true;
}

int main() {
    int t;
    cin>>t;
    for(int i=0;i<t;++i)
    {
        cin>>n>>m;
        for(int j=0;j<n;++j)
            cin>>go[j];
        if(isPossible())
            cout<<"YES\n";
        else cout<<"NO\n";

    }
    return 0;
}
